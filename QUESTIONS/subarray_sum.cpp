#include<iostream>
using namespace std;

void Input_array(int arr[], int n)
{
    cout<<"\nEnter the elements of the array :";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
}


void Subarrays_sum1(int arr[], int n)
{
    int max_sum= INT16_MIN;
    for(int i=0 ; i<n ; i++){
        int sum=0;
        for(int j=i ; j<n ; j++){
            sum+=arr[j];
            max_sum=max(max_sum,sum);
        
        }
    }
    cout<<max_sum;
}

void Subarrays_sum2(int arr[], int n)
{
    int max_sum= INT16_MIN;
    int sum=0;
    for(int i=0; i<n ; i++)
    {
        if(sum < 0){
            sum=0;
        }
        sum=sum+arr[i];
        max_sum=max(max_sum,sum);
    }
    cout<<endl<<max_sum;

}




void Subarrays_sum(int arr[], int n)
{
    int max_sum= INT16_MIN;
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            int sum=0;
            for(int k=i; k<=j ; k++){
                sum+=arr[k];
                // if(sum>max_sum){
                //     max_sum=sum;
                // }
            }
            // cout<<sum<<" ";
            max_sum=max(max_sum,sum);

        }
        cout<<endl;
    }
    cout<<max_sum<<endl;
}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int arr[n];

    Input_array(arr,n);
    
    Subarrays_sum(arr,n);

    Subarrays_sum1(arr,n);

    Subarrays_sum2(arr,n);

}