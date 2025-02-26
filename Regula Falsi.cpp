#include <bits/stdc++.h>
using namespace std;

int f=0;

double fn(int *arr,int sz,double x, int *trig_arr)
{
    double ans=0;
    for(int i=0;i<=sz;i++)
    {
        ans+=arr[i]*pow(x,i);
    }

    double trig_ans=0;

    if(f=1)
    {
        trig_ans+=trig_arr[0]*sin(x);
        trig_ans+=trig_arr[1]*cos(x);
        trig_ans+=trig_arr[2]*tan(x);
    }

    return ans+trig_ans;
}

int main()
{
    int p;
    cout<<"Enter the highest power: ";
    cin>>p;

    int arr[p+1];
    int arr_trig[3]={};
    cout<<"Enter the coefficients: "<<endl;
    for(int i=0;i<=p;i++)
    {
        cout<< "X^"<<i<<" : ";
        cin>>arr[i];
    }

    double a, b;
    cout<<"Enter A: ";
    cin>>a;
    cout<<"Enter B: ";
    cin>>b;

    char ch;
    cout<<"Do you want to give coefficient of sin, cos, tan value?(y/n)";
    cin>>ch;
    if(ch=='y')
    {
        f=1;
        cout<<"Enter sin's: ";
        cin>>arr_trig[0];
        cout<<"Enter cos's: ";
        cin>>arr_trig[1];
        cout<<"Enter tan's: ";
        cin>>arr_trig[2];
    }

    double fa=fn(arr,p,a,arr_trig);
    double fb=fn(arr,p,b,arr_trig);

    if(fa*fb>0)
    {
        cout<<"Invalid interval. f(a) and f(b) must have diff signs."<<endl;
        return 0;
    }

    cout<<"Sl\ta\tb\txr\tf(xr)"<<endl;
    int c=1;
    double xr, temp=0;

    while (true)
    {
        double f_a=fn(arr, p, a,arr_trig);
        double f_b=fn(arr, p, b,arr_trig);

        xr=(f_b * a - f_a * b) / (f_b - f_a);
        double f_xr=fn(arr, p, xr,arr_trig);

        cout<<c++<<"\t"<<a<<"\t"<<b<<"\t"<<xr<<"\t"<<f_xr<<endl;

        if(fabs(xr-temp)<=0.0001||f_xr==0)
        {
            cout<<"\nRoot found: "<<xr<<endl;
            return 0;
        }

        if(f_a * f_xr<0)
        {
            b=xr;
        }
        else
        {
            a=xr;
        }
        temp=xr;
    }

    return 0;
}

