#include<iostream>
using namespace std;

void Input_array(int arr[], int n) {
    cout << "\nEnter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;
}

void Print_array(int arr[], int n) {
    cout << "\nThe elements are: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Counting_sort(int arr[], int n) {
    int maximum = INT16_MIN;
    int minimum = INT16_MAX;

    // Find the minimum and maximum values in the array
    for(int i = 0; i < n; i++) {
        maximum = max(arr[i], maximum);
        minimum = min(arr[i], minimum);
    }
    
    cout << "Maximum: " << maximum << ", Minimum: " << minimum << endl;

    // Create a frequency array to store the count of each element
    int range = maximum - minimum + 1;
    int freq[range] = {0};  // Initialize all elements to 0

    // Calculate frequency of each element
    for(int i = 0; i < n; i++) {
        freq[arr[i] - minimum]++;  // Adjust the index by subtracting minimum
    }

    // Print the frequency array
    cout << "Frequency Array: ";
    Print_array(freq, range);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int arr[n];

    Input_array(arr, n);

    Counting_sort(arr, n);

    return 0;
}
