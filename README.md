Program Description

N-Queens Problem Solver

This program solves the classic N-Queens puzzle using a backtracking algorithm. The challenge is to place N chess queens on an N×N chessboard such that no two queens can attack each other.

Functionality



Input: Takes a single integer N as a command-line argument (the board size)

Algorithm: Uses recursive backtracking to find all valid queen placements

Output: Prints all possible solutions, where each solution is represented as a sequence of row positions for each column


The N-Queens Problem

In chess, a queen can attack any piece in the same:


Row (horizontal)

Column (vertical)

Diagonal (both directions)


The program must place N queens such that none share a row, column, or diagonal.

Usage

bash./program 4

./program 8

```

### Example Output

For N=4:
```
1 3 0 2 

2 0 3 1 
```

Each number represents the row position of a queen in that column:
- First solution: Queens at (0,1), (1,3), (2,0), (3,2)
- Second solution: Queens at (0,2), (1,0), (2,3), (3,1)

### How It Works

1. **Recursive Backtracking**: Places queens column by column from left to right
2. **Safety Check**: For each position, verifies:
   - No queen exists in the same row (`row == arr[i]`)
   - No queen exists on the same diagonal (`abs(i - col) == abs(arr[i] - row)`)
3. **Base Case**: When all columns are filled (col == n), prints the solution
4. **Exploration**: Tries all rows in the current column, backtracking when conflicts occur

### Technical Details

- **Data Structure**: Uses a 1D array where `arr[col] = row` represents a queen at position (col, row)
- **Time Complexity**: O(N!) in worst case (exploring all permutations)
- **Space Complexity**: O(N) for the recursion stack and array
- **Algorithm**: Depth-First Search (DFS) with backtracking

### Key Functions

**`is_safe(int col, int row, int *arr)`**
- Checks if placing a queen at (col, row) is safe
- Returns 1 if safe, 0 if conflicts exist

**`queens(int n, int col, int row, int *arr)`**
- Recursively places queens column by column
- Prints solutions when all queens are placed

### Example Visualization

For the solution `1 3 0 2` on a 4×4 board:

```
. Q . .    (row 0, col 1)
. . . Q    (row 1, col 3)
Q . . .    (row 2, col 0)
. . Q .    (row 3, col 2)
