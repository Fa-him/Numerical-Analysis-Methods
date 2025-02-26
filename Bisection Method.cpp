#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double fn(double x){
    return x * x * x - 2 * x - 5;
}
void bisection(double a, double b){
    double fa =  fn(a);
    double fb = fn(b);
    double temp = 0;
    int c = 1;
    if(fa==0 or fb==0)cout << "Interval is found" << endl;
    if(fa==0){
        cout << "Root" << c++ << " = " << a << endl;
    }
    if(fb==0){
        cout << "Root" << c++ << " = " << b << endl;
    }
    else if(c==1) {
        cout << "Sl\ta\tb\txr\tf(xr)" << endl;
        int cc = 1;
        while(fn(a) * fn(b) < 0){

            double xr = (a + b)/2;
            if(abs(xr - temp) <= 0.00001){
                cout << "\nInterval is found" << endl;
                cout << "Root" << c++ << " = " << xr << endl;
                return;
            }
            else{
                if(fn(a) * fn(xr) < 0){
                    b = xr;
                }
                else if(fn(a) * fn(xr) > 0){
                    a = xr;
                }
                else {
                    cout << "\nInterval is found" << endl;
                    cout << "Root" << c++ << " = " << xr << endl;
                    return;
                }
            }
            cout << cc++ << "\t" << a << "\t" << b << "\t" << xr << "\t" << fn(xr) << endl;
            temp = xr;
        }
    }
    cout << "Interval Not found" << endl;
}
int main(){

    double a, b;
    cout<<"Enter range(a,b): "<<endl;
    cin >> a >> b;
    bisection(a,b);

return 0;
}
