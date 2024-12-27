#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int si, int mid, int ei) {
    vector<int> temp;
    int i = si;
    int j = mid + 1;

    // Merge the two sorted halves
    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from the right half
    while (j <= ei) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to the original array
    for (int k = 0; k < temp.size(); k++) {
        arr[si + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = (si + ei) / 2;

    // Recursively divide the array
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    // Merge the sorted halves
    merge(arr, si, mid, ei);
}

int main() {
    vector<int> arr;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    arr.resize(n); // Resize the vector to accommodate n elements
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
