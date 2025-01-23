#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool dupParenthesis(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ')')
        {
            s.push(str[i]);
        }
        else
        {
            
            if( s.top() == '(') return true; 
            while(!s.empty() && s.top() == '('){
                s.pop();
            }
            if(s.empty()) s.pop();
        }
    }
    return false;
}

int main()
{
    string str;
    cout << "Enter the string" << endl;
    getline(cin, str);
    bool res = dupParenthesis(str);
    if (res)
    {
        cout << "\nIt contains duplicate Parenthesis" << endl;
    }
    else
    {
        cout << "\nIt doesnt contain duplicate parenthesis" << endl;
    }
    return 0;
}
