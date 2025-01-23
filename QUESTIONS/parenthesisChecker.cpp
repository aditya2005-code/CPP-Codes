#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isParenthesisBalanced(string& s) {

        stack<char> st;
        
        for(int i=0 ; i<s.length() ; i++){
            char ch = s[i];
            if(ch== '{' || ch== '[' || ch== '('){
                st.push(ch);
            } else {
                if(st.empty()) return false;
                char che=st.top();
                st.pop();
                if ((ch== '}' && che != '{') || 
                    (ch== ']' && che != '[') || 
                    (ch== ')' && che != '(')) {
                    return false;
                }
        
            }
        }
        return st.empty();
    }
};



int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
