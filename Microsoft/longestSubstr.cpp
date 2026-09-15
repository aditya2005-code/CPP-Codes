#include <bits/stdc++.h>
using namespace std;

class LongestString
{
public:
    // Longest Substring Without Repeating Characters
    int longestSubstring(string &str)
    {
        int n = str.size();

        unordered_map<char, int> freq;

        int i = 0, j = 0;
        int res = 0;

        while (i < n)
        {
            char ch = str[i];
            freq[ch]++;

            while (freq[ch] > 1)
            {
                freq[str[j]]--;
                j++;
            }

            res = max(res, i - j + 1);
            i++;
        }

        return res;
    }

    // Longest substring with at most K distinct characters
    int kdistinctString(string &str, int k)
    {
        int n = str.size();

        unordered_map<char, int> freq;

        int i = 0, j = 0;
        int res = 0;

        while (i < n)
        {
            char ch = str[i];
            freq[ch]++;

            while (freq.size() > k)
            {
                freq[str[j]]--;

                if (freq[str[j]] == 0)
                    freq.erase(str[j]);

                j++;
            }

            res = max(res, i - j + 1);

            i++;
        }

        return res;
    }

    // Longest substring after replacing K characters
    int characterReplacement(string s, int k)
    {
        vector<int> freq(26, 0);

        int left = 0;
        int res = 0;
        int maxFreq = 0;

        for (int right = 0; right < s.size(); right++)
        {
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};

int main()
{
    LongestString obj;

    // 1. Longest substring without repeating characters
    string str1 = "abcabcbb";
    cout << "Longest substring without repeating: "
         << obj.longestSubstring(str1) << endl;

    // 2. Longest substring with at most K distinct characters
    string str2 = "eceba";
    int k = 2;
    cout << "Longest substring with at most " << k << " distinct characters: "
         << obj.kdistinctString(str2, k) << endl;

    // 3. Longest substring after replacing K characters
    string str3 = "AABABBA";
    int k2 = 1;
    cout << "Longest substring after replacing " << k2 << " characters: "
         << obj.characterReplacement(str3, k2) << endl;

    return 0;
}