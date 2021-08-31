//Maayeesha Farzana
//ID: 1804069
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define EPSILON 0.001

double bisect(ld x)
{
    return x*x*x - x*x +2;
}
double derived(ld x)
{
    return 3*x*x - 2*x;
}

void newtonRaphson(ld x)
{
    ld h = bisect(x)/derived(x);

    while(abs(h) >= EPSILON)
    {
        h = bisect(x)/derived(x);
        x -= h;
    }
cout<<"The value of the root is = "<<x;
}

int main()
{
    ld x0;
    cout<<"Enter the value of x0: ";
    cin>>x0;
    newtonRaphson(x0);
    return 0;
}
