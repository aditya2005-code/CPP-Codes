// 10. Last Element Appearing More Than Twice

// A recent Autodesk internship report described a coding question asking for the last element that appears more than twice in an array.

// Variations:

// First duplicate.
// Last duplicate.
// First element occurring K times.
// Most frequent element.
// Last element with maximum frequency.

// Pattern: Hash Map / Frequency counting

#include<bits/stdc++.h>
using namespace std;

class ElementPresence{
    public:

    int firstDuplicate(vector<int>& arr){
        unordered_map<int,int> freq;
        int n = arr.size();

        for(int num : arr){
            freq[num]++;
            if(freq[num] > 1){
                return num;
            }
        }

        cout<<"No duplicate element exists"<<endl;

        return -1;
    }

    int lastDuplicate(vector<int>& arr){
        unordered_map<int,int> freq;
        int n = arr.size();
        int res = -1;

        for(int num : arr){
            freq[num]++;
            if(freq[num] > 1){
                res = num;
            }
        }

        return res;
    }

};

int main(){
    vector<int> arr = {1,2,3,2,3,4,4,5,5,1};
    ElementPresence e;
    cout<<"Fist Duplicate : "<<e.firstDuplicate(arr)<<endl;
    cout<<"Last Duplicate : "<<e.lastDuplicate(arr);
    return 0;
}