def gauss_elimination():
    n = int(input("Enter the number of equations: "))
    matrix = []

    print("Enter the augmented matrix coefficients (including constants):")
    for i in range(n):
        row = list(map(float, input(f"Equation {i + 1}: ").split()))
        matrix.append(row)

    # Forward elimination
    for i in range(n):
        for j in range(i + 1, n):
            ratio = matrix[j][i] / matrix[i][i]
            for k in range(n + 1):
                matrix[j][k] -= ratio * matrix[i][k]

    # Back substitution
    roots = [0] * n
    print("\nRoots are:")
    for i in range(n - 1, -1, -1):
        sum_terms = sum(matrix[i][j] * roots[j] for j in range(i + 1, n))
        roots[i] = (matrix[i][n] - sum_terms) / matrix[i][i]

    for i, root in enumerate(roots):
        print(f"X{i + 1} = {root}")


if __name__ == "__main__":
    gauss_elimination()
