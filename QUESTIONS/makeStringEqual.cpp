#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even(26, 0), odd(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            if(i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        return even == vector<int>(26, 0) && odd == vector<int>(26, 0);
    }
};

int main() {
    Solution obj;

    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;

    cout << "Enter string s2: ";
    cin >> s2;

    bool result = obj.checkStrings(s1, s2);

    if(result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}