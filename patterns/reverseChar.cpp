#include <iostream>
using namespace std;

void Reverse(char arr[], int n) {
    int start = 0, end = n - 1;
    while (start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cin.ignore(); // Ignore the leftover newline character

    char arr[n + 1]; // Increased size by 1 to hold the null terminator
    cout << "\nEnter the string: ";
    cin.getline(arr, n + 1);

    // Calculate the actual length of the string input by the user
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }

    Reverse(arr, len);

    cout << "\nReversed string: " << arr;
    return 0;
}
