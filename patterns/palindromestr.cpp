#include <iostream>
#include <cstring> 
using namespace std;

void Palindrome(char arr[], int n)
{   
    char duplicate[n + 1]; 
    for(int i = 0; i < n; i++) {
       duplicate[i] = arr[i];
    }
    duplicate[n] = '\0'; 

    int start = 0, end = n - 1;
    while(start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    if(strcmp(arr, duplicate) == 0) {
        cout << "palindrome";
    } else {
        cout << "not palindrome";
    }
}

int main()
{
    int n;
    cout << "Enter the length of the string: ";
    cin >> n;
    cin.ignore();

    char arr[n + 1];
    cout << "Enter the string: ";
    cin.getline(arr, n + 1); 

    Palindrome(arr, n);

    return 0;
}
