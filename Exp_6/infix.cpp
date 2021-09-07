//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;
stack<int> num;
stack<char> op;

int precedence(char c)
{
    if(c == '*' || c == '/') return 2;
    else return 1;
}

int updateValue(int q,char p, int r)
{
    if( p == '+')
        return q + r;
    if( p == '-')
        return q - r;
    if( p == '*')
        return q * r;
    if( p == '/')
        return q / r;
}

void execution(stack<char> op, stack<int> num)
{
                char p = op.top();
                op.pop();
                int q = num.top();
                num.pop();
                int r = num.top();
                num.pop();
                int ans = updateValue(q,p,r);
                num.push(ans);

}

int main()
{
    string X;
    cin>>X;
    int i;

    for(i=0; i<X.length(); i++)
    {
        char c = X[i];
        if(c >= '0' && c <= '9')
        {
            int x = 0;
            while(i<X.length() && X[i] >= '0' && X[i] <= '9')
            {
                x = x*10 + (X[i] - '0');
                i++;
            }
            num.push(x);
            i--;
        }
        else if(c == '(') op.push(c);
        else if(c == ')')
        {
            while(!(op.empty()) && op.top() != '(')
            {
                execution(op,num);
            }
            if(!(op.empty())) op.pop();
        }

        else
        {
            while(!(op.empty()) && precedence(op.top()) >= precedence(c))
            {
                execution(op,num);
            }
            op.push(c);
        }
    }
        while(!(op.empty()))
          {
              execution(op,num);
          }
          cout<<num.top()<<endl; //(2+3)-5*(4/2)

}
