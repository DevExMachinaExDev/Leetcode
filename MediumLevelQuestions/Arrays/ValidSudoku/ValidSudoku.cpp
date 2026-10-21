#include <vector>

// To prevent repeated code logic is stored here
inline bool isDuplicate(int& foundMask, char c)
{
    if (c == '.')
        return false;

    int currentValueMask = 1 << (c - '1');

    if ((foundMask & currentValueMask) != 0)
        return true;

    foundMask |= currentValueMask;

    return false;
}

// This has O(1) time complexity and O(1) space complexity for a fixed 9x9 Sudoku board. For a generalized NxN Sudoku it would be O(N²) time and O(1) space.
bool isValidSudokuMultipass(std::vector<std::vector<char>>& board)
{
    int foundMask = 0;

    // Horizontal Checks
    for (const std::vector<char>& row : board)
    {
        foundMask = 0;

        for (char c : row)
        {
            if (isDuplicate(foundMask, c))
                return false;
        }
    }

    // Vertical Checks
    for (int i = 0; i < 9; ++i)
    {
        foundMask = 0;

        for (int j = 0; j < 9; ++j)
        {
            if (isDuplicate(foundMask, board[j][i]))
                return false;
        }
    }

    // Square Checks
    for (int squareRow = 0; squareRow < 9; squareRow += 3)
    {
        for (int squareCol = 0; squareCol < 9; squareCol += 3)
        {
            foundMask = 0;

            for (int i = squareRow; i < squareRow + 3; ++i)
            {
                for (int j = squareCol; j < squareCol + 3; ++j)
                {
                    if (isDuplicate(foundMask, board[i][j]))
                        return false;
                }
            }
        }
    }

    return true;
}

//Trades a small amount of additional constant memory for a single traversal. 
bool isValidSudokuSinglePass(std::vector<std::vector<char>>& board)
{
    int rowsBitmasks[9] = {0};
    int columnBitmasks[9] = {0};
    int boxBitmasks[9] = {0};

    for (int row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            char c = board[row][column];

            if (c == '.')
                continue;

            int valueMask = 1 << (c - '1');

            int box = (row / 3) * 3 + (column / 3);

            if ((rowsBitmasks[row] & valueMask) != 0)
                return false;

            if ((columnBitmasks[column] & valueMask) != 0)
                return false;

            if ((boxBitmasks[box] & valueMask) != 0)
                return false;

            rowsBitmasks[row] |= valueMask;
            columnBitmasks[column] |= valueMask;
            boxBitmasks[box] |= valueMask;
        }
    }

    return true;
}

