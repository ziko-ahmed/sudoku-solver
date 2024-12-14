#include <stdio.h>
#include <stdlib.h>

int UNSOLVED;
int SIZE_ROWS;
int SIZE_COLUMNS;
int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

typedef struct Sudoku
{
    struct Square *** squares;
    struct Box ** boxes;
} Sudoku;

typedef struct Box
{
    struct Square ** squares;
    int numbers;
    int possible[9];
    int solvable;
    struct Box * next;
} Box;

typedef struct Square
{
    int number;
    int possible[9];
    int solvable;
    Box * box;
    int row;
    int column;
} Square;

int ** createPuzzle();
void printPuzzle(Square *** puzzle);
Sudoku * setUpPuzzle(int ** puzzle);
Sudoku * createSudoku(Square *** squares, Box ** boxes);
int updateSudoku(Square *** sudoku, int row, int column);
int checkPuzzle(Square *** sudoku, Box ** boxes);
int solveSquare(Square * square);
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int column);
int boxSingles(Square *** sudoku, Box ** boxes);


Sudoku * createSudoku(Square *** squares, Box ** boxes)
{
    Sudoku * sudoku;
    sudoku = malloc(sizeof(Sudoku));

    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;
}

Sudoku * setUpPuzzle(int ** puzzle)
{
    Square *** sudoku;
    Box ** boxes;
    int i, j, x;
    int currentBox = 0;

    sudoku = (Square***)malloc(sizeof(Square**)*9);
    boxes = createBoxes();

    for (i = 0; i < SIZE_ROWS; i++)
    {
        sudoku[i] = (Square**)malloc(sizeof(Square*)*9);
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            sudoku[i][j] = (Square*)malloc(sizeof(Square)*9);
            sudoku[i][j]->number = puzzle[i][j];
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            sudoku[i][j]->solvable = 9;

            boxes[currentBox]->squares[ boxes[currentBox]->numbers ] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            for (x = 0; x < SIZE_ROWS; x++)
            {
                sudoku[i][j]->possible[x] = 0;
            }
            if (j == 2)
                currentBox++;
            if (j == 5)
                currentBox++;
        }
        currentBox -= 2;
        if (i == 2)
            currentBox = 3;
        if (i == 5)
            currentBox = 6;
    }
    for (i = 0; i < SIZE_ROWS; i++)
    {
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->number != 0)
            {
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }

    return createSudoku(sudoku, boxes);
}

int updateSudoku(Square *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;

    for (x = 0; x < SIZE_ROWS; x++)
    {
        if (sudoku[x][column]->possible[number - 1] == 0)
            sudoku[x][column]->solvable--;
        sudoku[x][column]->possible[number -1] = 1;
    }

    for (x = 0; x < SIZE_COLUMNS; x++)
    {
        if (sudoku[row][x]->possible[number - 1] == 0)
            sudoku[row][x]->solvable--;
        sudoku[row][x]->possible[number -1] = 1;
    }
    return 1;
}

int checkPuzzle(Square *** sudoku, Box ** boxes)
{
    int i, j, x;
    for (i = 0; i < SIZE_ROWS; i++)
    {
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->solvable == 1)
            {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                return 1;
            }
        }
    }
    return boxSingles(sudoku, boxes);
}

int ** createPuzzle()
{
    int ** puzzle;
    int i, j;
    int array[9][9]= {1, 0, 0,      5, 0, 0,     0, 4, 3,
                      4, 7, 0,      1, 0, 2,     0, 5, 0,
                      0, 0, 0,      0, 0, 0,     2, 9, 1,

                      9, 0, 3,      4, 0, 0,     5, 8, 6,
                      6, 0, 0,      0, 0, 5,     0, 2, 0,
                      0, 5, 0,      0, 0, 0,     1, 7, 0,

                      3, 0, 5,      8, 0, 0,     9, 6, 2,
                      0, 2, 6,      3, 0, 9,     8, 0, 5,
                      8, 0, 0,      0, 5, 0,     0, 0, 0 };

    puzzle = (int**)malloc(sizeof(int*)*9);

    for (i = 0; i < 9; i++)
    {
        puzzle[i] = (int*)malloc(sizeof(int)*9);

        for (j = 0; j < 9; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

void printPuzzle(Square *** puzzle)
{
    int i, j;

    printf("-------------------------------\n");
    for (i = 0; i < SIZE_ROWS; i++)
    {
        printf("|");
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            printf(" %d ", puzzle[i][j]->number);

            if (((j + 1) % 3) == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % 3) == 0)
        {
            printf("-------------------------------\n");
        }
    }
}

int boxSingles(Square *** sudoku, Box ** boxes)
{
    int i, j, x;
    int count;
    int temp;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            count = 0;
            for (x = 0; x < 9; x++)
            {
                if (boxes[i]->squares[x]->number != 0)
                    continue;
                if (boxes[i]->squares[x]->possible[j] == 0)
                {
                    count++;
                    temp = x;
                }
                if (count == 2)
                    break;
            }
            if (count == 1)
            {
                boxes[i]->squares[temp]->number = j + 1;
                UNSOLVED--;
                boxes[i]->squares[temp]->solvable = 0;
                updateSudoku(sudoku, boxes[i]->squares[temp]->row, boxes[i]->squares[temp]->column);
                return 1;
            }
        }
    }
    return 0;
}

Box ** createBoxes()
{
    int x, y;
    Box ** boxes;
    boxes = malloc(sizeof(Box*)*9);
    for (x = 0; x < 9; x++)
    {
        boxes[x] = malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*)*9);
        boxes[x]->numbers = 0;
        boxes[x]->solvable = 9;
        for (y = 0; y < 9; y++)
            boxes[x]->possible[y] = 0;
    }
    return boxes;
}

int updateBoxes(Square *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;
    Box * box;
    box = sudoku[row][column]->box;
    for (x = 0; x < 9; x++)
    {
        if (box->squares[x]->possible[number - 1] == 0)
        {
            box->squares[x]->solvable--;
            box->squares[x]->possible[number - 1] = 1;
        }
    }

}

int solveSquare(Square * square)
{
    int x;
    for (x = 0; x < SIZE_ROWS; x++)
    {
        if (square->possible[x] == 0)
        {
            square->number = x + 1;
            square->solvable = 0;
            UNSOLVED--;
        }
    }
}

void main()
{
    int ** puzzle;
    int progress;
    Sudoku * sudoku;
    puzzle = createPuzzle();
    sudoku = setUpPuzzle(puzzle);
    printPuzzle(sudoku->squares);
    while (UNSOLVED > 0)
    {
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);
        if (progress == 0)
        {
            printf("\nFailed to solve the puzzle!\n\n");
            break;
        }
    }
    printPuzzle(sudoku->squares);
}