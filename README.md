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
- **The program displays the Sudoku puzzle before solving.
- **Shows progress and stops if it cannot logically solve the puzzle.
- **Prints the solved puzzle if successful.
