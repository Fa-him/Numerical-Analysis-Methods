def fn(x):
    return x ** 3 - 2 * x - 5


def bisection(a, b):
    fa = fn(a)
    fb = fn(b)
    temp = 0
    c = 1

    if fa == 0 or fb == 0:
        print("Interval is found")
    if fa == 0:
        print(f"Root{c} = {a}")
        c += 1
    if fb == 0:
        print(f"Root{c} = {b}")
        c += 1
    elif c == 1:
        print("Sl\ta\tb\txr\tf(xr)")
        cc = 1
        while fn(a) * fn(b) < 0:
            xr = (a + b) / 2
            if abs(xr - temp) <= 0.00001:
                print("\nInterval is found")
                print(f"Root{c} = {xr}")
                return
            else:
                if fn(a) * fn(xr) < 0:
                    b = xr
                elif fn(a) * fn(xr) > 0:
                    a = xr
                else:
                    print("\nInterval is found")
                    print(f"Root{c} = {xr}")
                    return
            print(f"{cc}\t{a}\t{b}\t{xr}\t{fn(xr)}")
            temp = xr
            cc += 1
    print("Interval Not found")


if __name__ == "__main__":
    a, b = map(float, input().split())
    bisection(a, b)
