#include<iostream>
using namespace std;

void Input_array(int arr[], int n)
{
    cout<<"\nEnter the elements of the array :";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
}

int Max_product(int arr[], int n)
{
    int maxProduct = arr[0];
    int minProduct = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            swap(maxProduct, minProduct); // swap if current element is negative
        }

        maxProduct = max(arr[i], maxProduct * arr[i]);
        minProduct = min(arr[i], minProduct * arr[i]);

        result = max(result, maxProduct); // update the result with the maximum product
    }

    return result;

}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int arr[n];
    Input_array(arr,n);

    int result= Max_product(arr,n);

    cout<<endl<<"The max product is "<<result;

    return 0;
}