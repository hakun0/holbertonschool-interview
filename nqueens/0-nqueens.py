#!/usr/bin/python3
import sys


def is_safe(row, col, solution):
    for r, c in solution:
        if c == col or abs(row - r) == abs(col - c):
            return False
    return True


def solve(row, n, solution, solutions):
    if row == n:
        solutions.append(solution[:])
        return
    for col in range(n):
        if is_safe(row, col, solution):
            solution.append([row, col])
            solve(row + 1, n, solution, solutions)
            solution.pop()


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve(0, n, [], solutions)
    for sol in solutions:
        print(sol)


if __name__ == "__main__":
    main()