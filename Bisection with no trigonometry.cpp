#include <bits/stdc++.h>
using namespace std;

double fn(int *arr, int sz, double x)
{
    double ans = 0;
    for (int i = 0; i <= sz; i++)
    {
        ans += arr[i] * pow(x, i);
    }
    return ans;
}

int main()
{
    int p;
    cout << "Enter the highest power: ";
    cin >> p;

    int arr[p + 1];
    cout << "Enter the coefficients: " << endl;
    for (int i = 0; i <= p; i++)
    {
        cout << "X^" << i << " : ";
        cin >> arr[i];
    }

    double a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    double fa = fn(arr, p, a);
    double fb = fn(arr, p, b);

    if (fa * fb > 0)
    {
        cout << "Invalid interval. f(a) and f(b) must have different signs." << endl;
        return 0;
    }

    cout << "Sl\ta\tb\txr\tf(xr)" << endl;
    int c = 1;
    double xr, temp = 0;

    while (true)
    {
        double f_a = fn(arr, p, a);
        double f_b = fn(arr, p, b);

        xr = (f_b * a - f_a * b) / (f_b - f_a);
        double f_xr = fn(arr, p, xr);

        cout << c++ << "\t" << a << "\t" << b << "\t" << xr << "\t" << f_xr << endl;

        if (fabs(xr - temp) <= 0.0001 || f_xr == 0)
        {
            cout << "\nRoot found: " << xr << endl;
            return 0;
        }

        if (f_a * f_xr < 0)
        {
            b = xr;
        }
        else
        {
            a = xr;
        }
        temp = xr;
    }

    return 0;
}
