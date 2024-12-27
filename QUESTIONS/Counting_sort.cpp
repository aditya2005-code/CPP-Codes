#include <iostream>
using namespace std;

void Input_array(int arr[], int n)
{
    cout << "\nEnter the elements of the array: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}

void Print_array(int arr[], int n)
{
   
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Counting_sort(int arr[], int n)
{
    int maximum = INT16_MIN;
    int minimum = INT16_MAX;

    for (int i = 0; i < n; i++)
    {
        maximum = max(arr[i], maximum);
        minimum = min(arr[i], minimum);
    }

    int freq[maximum] = {0};

    for (int i = 0; i <= maximum; i++)
    {
        freq[arr[i]]++;
    }
    
    for(int i=minimum,j=0 ; i<=maximum ; i++){

        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }

    Print_array(arr,n);

  
}

int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >> n;

    int arr[n];

    Input_array(arr, n);

    Counting_sort(arr, n);

    return 0;
}