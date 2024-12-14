# Sudoku Solver

This project is a C-based **Sudoku Solver** that solves a 9x9 Sudoku puzzle using logical reasoning. It utilizes a structured approach with `structs` to represent Sudoku components, such as `Square`, `Box`, and `Sudoku`, allowing the solver to dynamically process the puzzle.

---

## Features

- **Dynamic Puzzle Representation**: Uses a combination of arrays and structures to dynamically store and manipulate the puzzle.
- **Logical Solving**: Implements various strategies, including box singles and row-column constraints, to logically solve the puzzle.
- **Progressive Solving**: Continuously updates the solvable squares until the puzzle is completed or deemed unsolvable.
- **Console Output**: Prints the Sudoku puzzle before and after solving for clear visualization.

---

## Files in the Repository

- **`sudoku_solver.c`**: The main implementation file containing the code for solving the Sudoku puzzle.
- **Sample Input Puzzle**: A pre-defined 9x9 puzzle is embedded in the `createPuzzle` function.
- **Output Display**: The console output shows the puzzle at different stages of solving.

---

## How to Run the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/sudoku-solver.git
   cd sudoku-solver

2. **Compile the Code: Use a C compiler such as GCC to compile the program:
   ```bash
   gcc sudoku_solver.c -o sudoku_solver

3. Run the Program: Execute the compiled program:
   ```bash
   ./sudoku_solver

4. Output:
- The program displays the Sudoku puzzle before solving.
- Shows progress and stops if it cannot logically solve the puzzle.
- Prints the solved puzzle if successful.

## Sample Input and Output

### Sample Input

The input puzzle is represented as a 9x9 grid with zeros indicating empty cells:

```plaintext
----------------------------------
|  1  0  0 |  5  0  0 |  0  4  3 |
|  4  7  0 |  1  0  2 |  0  5  0 |
|  0  0  0 |  0  0  0 |  2  9  1 |
----------------------------------
|  9  0  3 |  4  0  0 |  5  8  6 |
|  6  0  0 |  0  0  5 |  0  2  0 |
|  0  5  0 |  0  0  0 |  1  7  0 |
----------------------------------
|  3  0  5 |  8  0  0 |  9  6  2 |
|  0  2  6 |  3  0  9 |  8  0  5 |
|  8  0  0 |  0  5  0 |  0  0  0 |
----------------------------------
```

### Sample Output

The output puzzle is represented as a 9x9 grid:

```plaintext

----------------------------------
|  1  8  2 |  5  9  6 |  7  4  3 |
|  4  7  9 |  1  3  2 |  6  5  8 |
|  5  3  6 |  7  4  8 |  2  9  1 |
----------------------------------
|  9  1  3 |  4  7  2 |  5  8  6 |
|  6  4  7 |  9  8  5 |  3  2  1 |
|  2  5  8 |  6  1  3 |  4  7  9 |
----------------------------------
|  3  9  5 |  8  6  1 |  9  6  2 |
|  7  2  6 |  3  4  9 |  8  1  5 |
|  8  6  4 |  2  5  7 |  1  3  9 |
----------------------------------


