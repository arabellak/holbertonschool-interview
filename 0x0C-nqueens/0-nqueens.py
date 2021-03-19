#!/usr/bin/python3
"""N Queens"""
import sys


def printss(board):
    """
    Prints the coordinates row and column for the position of
    each N queen in the posible solution
    """

    solve = []
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 1:
                solve.append([i, j])
    print(solve)


def isSafe(board, row, col, n):
    """
    Checks if a queen can be placed on board
    """

    for c in range(col):
        if board[row][c] == 1:
            return False

    for r, c in zip(range(row, -1, -1),
                    range(col, -1, -1)):
        if board[r][c] == 1:
            return False

    for r, c in zip(range(row, n, 1),
                    range(col, -1, -1)):
        if board[r][c] == 1:
            return False

    return True


def solution(board, col, n):
    """Solve the n queen problem using Backtracking"""

    if col == n:
        printss(board)
        return True

    c = False
    for i in range(n):
        if isSafe(board, i, col, n):
            board[i][col] = 1
            c = solution(board, col + 1, n) or c
            board[i][col] = 0
    return c


if __name__ == "__main__":
    """Starting the program"""
    if not len(sys.argv) == 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not (sys.argv[1]).isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [[0 for i in range(n)] for j in range(n)]
    solution(board, 0, n)
