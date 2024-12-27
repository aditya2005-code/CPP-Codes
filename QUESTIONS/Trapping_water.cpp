#include<iostream>
using namespace std;

void Input_array(int arr[],int n)
{
    cout<<"Enter the elements of the array:";
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
}

int Trapped_water(int arr[], int n)
{
    if(n==2 || n==1){
        return 0;
    }

    int left_max[1000];
    left_max[0]= INT16_MIN;

    int right_max[1000];
    right_max[n-1]= INT16_MIN;

    for(int i=1 ; i<n ; i++){
        left_max[i]= max(left_max[i-1],arr[i-1]);
        cout<<left_max[i]<<" ";
    }
    cout<<endl;

    for(int i=n-2; i>=0 ; i--){

        right_max[i]= max(right_max[i+1],arr[i+1]);
        cout<<right_max[i]<<" ";
    }

    int water_trapped=0;

    for(int i=n-2; i>=0 ; i--){
        int current_water= min(left_max[i], right_max[i])-arr[i];

        if(current_water>0){
            water_trapped+=current_water;
        }

    }


    return water_trapped;
}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int arr[n];

    Input_array(arr,n);

    int result= Trapped_water(arr,n);

    if(result!=0){
        cout<<"The water trapped is "<<result<<endl;

    }
    else{
        cout<<"no water trapped";
    }

    return 0;
}