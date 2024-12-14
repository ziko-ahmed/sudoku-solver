# Sudoku Solver

Overview

This project is a C-based implementation of a Sudoku solver. The program uses structures like Square, Box, and Sudoku to represent and solve a 9x9 Sudoku puzzle. It incorporates techniques like updating possibilities for each cell and checking solvable squares to deduce the solution.

Features

Dynamic Data Structures: Uses struct in C to represent individual squares, boxes, and the entire Sudoku puzzle.

Logic-Based Solving: Implements logic for updating possibilities and solving squares systematically.

Partial Puzzle Input: Users can modify the initial puzzle input to solve any valid Sudoku.

Readable Output: Prints the puzzle in a structured 9x9 grid format.

Getting Started

Prerequisites

To compile and run this program, you need:

A C compiler (e.g., GCC).

A terminal or IDE to run the program.

Compilation

To compile the program, use the following command:

gcc -o sudoku_solver sudoku_solver.c

Execution

Run the program with:

./sudoku_solver

Usage

Modify the createPuzzle function in the code to input your Sudoku puzzle.

Replace the array variable with your desired puzzle.

Use 0 to represent empty cells.

Compile and execute the program.

The program will attempt to solve the puzzle and print the results in the terminal.

Example Input

int array[9][9]= {
    1, 0, 0,      5, 0, 0,     0, 4, 3,
    4, 7, 0,      1, 0, 2,     0, 5, 0,
    0, 0, 0,      0, 0, 0,     2, 9, 1,

    9, 0, 3,      4, 0, 0,     5, 8, 6,
    6, 0, 0,      0, 0, 5,     0, 2, 0,
    0, 5, 0,      0, 0, 0,     1, 7, 0,

    3, 0, 5,      8, 0, 0,     9, 6, 2,
    0, 2, 6,      3, 0, 9,     8, 0, 5,
    8, 0, 0,      0, 5, 0,     0, 0, 0
};

Output

The program prints the initial puzzle and the solved puzzle.

If the puzzle cannot be solved, a failure message is displayed.

File Structure

sudoku_solver.c: Contains the full implementation of the Sudoku solver.

