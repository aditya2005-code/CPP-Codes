#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void Guessgame(int arr[], int n)
{
   int count=1;
   srand(static_cast<unsigned int>(time(0))); 
    int randomIndex = rand() % n;
   do{
    int g;
    cout<<"\nEnter the number you guessed:";
    cin>>g;
    
    if(arr[randomIndex]==g){
      cout<<"\nYou guessed right in"<<count<<" attempt";
      break;
    }

    else if(arr[randomIndex]<g){
      cout<<"\nThe number is smaller than your choosed one";
    }

    else{
      cout<<"\nThe number is greaterr than your choosed one";
    }

   
    count++;
   }while(1);
}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int* arr=(int*)malloc(n*sizeof(int));
    cout<<"\nEnter the elements of the Array";
    for(int i=0; i<n ; i++)
    {
       cin>>arr[i];
    }

    Guessgame(arr,n);

    
}