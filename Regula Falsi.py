def fn(coefficients, x):
    return sum(coefficients[i] * (x ** i) for i in range(len(coefficients)))


def regula_falsi(coefficients, a, b, tolerance=0.0001):
    fa = fn(coefficients, a)
    fb = fn(coefficients, b)

    if fa == 0:
        print(f"Root found at A = {a}")
        return
    if fb == 0:
        print(f"Root found at B = {b}")
        return

    if fa * fb > 0:
        print("Invalid interval: f(A) and f(B) must have opposite signs.")
        return

    temp = 0
    iteration = 1
    print("\nIteration\tA\tB\tXr\tf(Xr)")

    while True:
        fa = fn(coefficients, a)
        fb = fn(coefficients, b)
        xr = (fb * a - fa * b) / (fb - fa)  # Regula Falsi formula
        fxr = fn(coefficients, xr)

        print(f"{iteration}\t{a}\t{b}\t{xr}\t{fxr}")
        iteration += 1

        if abs(xr - temp) <= tolerance:
            print(f"\nRoot found at Xr = {xr}")
            return

        if fa * fxr < 0:
            b = xr
        else:
            a = xr

        temp = xr


if __name__ == "__main__":
    p = int(input("Enter the highest power of the polynomial: "))
    coefficients = []

    print("Enter the coefficients:")
    for i in range(p + 1):
        coeff = float(input(f"Coefficient of X^{i}: "))
        coefficients.append(coeff)

    a = float(input("Enter A: "))
    b = float(input("Enter B: "))

    regula_falsi(coefficients, a, b)
