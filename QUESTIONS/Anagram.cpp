#include <iostream>
#include <string>
using namespace std;

void Anagram(string str1, string str2) {
    if (str1.length() != str2.length()) {
        cout << "Strings are not of equal length, so they cannot be anagrams." << endl;
        return;
    }

    int count1[26] = {0};

    // Increment count for characters in str1
    for (int i = 0; i < str1.length(); i++) {
        int idx = tolower(str1[i]) - 'a';
        count1[idx]++;
    }

    // Decrement count for characters in str2
    for (int i = 0; i < str2.length(); i++) {
        int idx = tolower(str2[i]) - 'a';
        if (count1[idx] == 0) {
            cout << "not valid" << endl;
            return;
        }
        count1[idx]--;
    }

    cout << "valid" << endl;
}

int main() {
    string str1, str2;
    cout << "Input the strings:" << endl;
    getline(cin, str1);
    getline(cin, str2);
    Anagram(str1, str2);
    return 0;
}
