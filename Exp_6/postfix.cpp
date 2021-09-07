//Maayeesha Farzana
//ID: 1804069

#include<bits/stdc++.h>
using namespace std;


int precedence(char c)
{
    if(c == '*' || c == '/') return 2;
    else return 1;
}

int main()
{
    string X,Y= "";
    cin>>X;
    stack<char> st;
    st.push('(');
    X += ")";

    int p = 0,ans;
    while(!(st.empty()))
    {
        char c = X[p];
        if(c >= '0' && c <='9') Y += c;
        else if(c == '(')
        {
            st.push('(');
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            while(!(st.empty()) && st.top() != '(' && precedence(st.top()) >= precedence(c))
            {
                Y += st.top();
                st.pop();
            }
            st.push(c);
        }
        else{
            while(st.top() != '(')
            {
                Y += st.top();
                st.pop();
            }
            st.pop();
        }
         p++;
    }
    cout<<Y<<endl;

    stack<int> eval;

    for(int i=0; Y[i] != '\0'; i++)
    {
        char c = Y[i];

        if(c >= '0' && c <= '9') eval.push(c - '0');
        else if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            if(c == '+')
            {
                ans  = eval.top();
                eval.pop();
                eval.top() += ans;
            }
            if(c == '-')
            {
                ans  = eval.top();
                eval.pop();
                eval.top() -= ans;
            }
            if(c == '*')
            {
                ans  = eval.top();
                eval.pop();
                eval.top() *= ans;
            }
            if(c == '/')
            {
                ans  = eval.top();
                eval.pop();
                eval.top() /= ans;
            }
        }
    }

    cout<<"Answer = "<<eval.top()<<endl;
}
