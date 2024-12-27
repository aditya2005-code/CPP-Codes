#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr , int si , int ei)
{
    int pivot = arr[ei];
    int i=si-1 ;
    for(int j=si ; j < ei ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
            
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    
    return i;
}

void quick_sort(vector<int>& arr, int si , int ei)
{
    if(si>=ei){
        return;
    }
   int pivotidx= partition(arr,si,ei);

   quick_sort(arr,si,pivotidx-1);
   quick_sort(arr,pivotidx+1,ei);
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

    quick_sort(arr,0,n-1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
