#include<iostream>
using namespace std;

void Input_array(int arr[], int n) {
    cout << "\nEnter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void duplicates(int arr[], int n) {
    int k = 0;
    int d[n], count;

    for(int i = 0; i < n; i++) {
        count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        if(count > 1) {
            bool isDuplicateAlreadyAdded = false;
            for(int x = 0; x < k; x++) {
                if(d[x] == arr[i]) {
                    isDuplicateAlreadyAdded = true;
                    break;
                }
            }

            if(!isDuplicateAlreadyAdded) {
                d[k] = arr[i];
                k++;
            }
        }
    }

    if(k > 0) {
        cout << "\nDuplicate elements are: ";
        for(int i = 0; i < k; i++) {
            cout << d[i] << " ";
        }
    } else {
        cout << "\nNo duplicate elements found.";
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int arr[n];

    Input_array(arr, n);
    duplicates(arr, n);

    return 0;
}
