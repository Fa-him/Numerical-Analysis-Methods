#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of equations: ";
    cin>>n;

    vector<vector<float>> a(n, vector<float> (4));

    cout<<"Enter the coefficients (A,B,C) and constant (D) for each equation: \n";
    for (int i=0; i<n; i++)
    {
        cout<<"Equation " <<i+1<<"(A, B, C, D): ";
        for (int j=0 ;j<4; j++)
            cin>>a[i][j];
    }

    vector<float>r;
    for (int i=1; i<n; i++)
        r.push_back(a[i][0]/ a[0][0]);

    vector<vector<float>>eq(2, vector<float>(4));

    for (int i=1; i<n; i++)
    {
        for (int j=0; j<4; j++)
        {
            eq[i-1][j] =a[i][j] -(r[i-1] * a[0][j]);
        }
    }

    float r3=(eq[0][1]!=0) ? eq[1][1] / eq[0][1] : 0;

    vector<float>eq6(4);

    for (int j=0; j<4;j++)
        eq6[j]=eq[1][j]-(r3* eq[0][j]);

    float z=(eq6[2] !=0) ? eq6[3]/eq6[2] : 0;
    float y=(eq[0][1]!=0) ?  (eq[0][3] - (eq[0][2]*z))/ eq[0][1] :0;
    float x=(a[0][0]!=0) ? (a[0][3] - (a[0][1]* y)- (a[0][2]*z)) / a[0][0] : 0;

    cout<<"\nSolution: \n";
    cout<<"X= " <<x<<endl;
    cout<<"Y= " <<y<<endl;
    cout<<"Z= " <<z<<endl;

}
