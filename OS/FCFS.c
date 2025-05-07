#include <stdio.h>
#include <unistd.h>

void bubbleSort(int arr[][6], int n, int col , int srow) {
    for (int i = srow; i < n - 1; i++) {
        for (int j = srow; j < n - i - 1; j++) {
            if (arr[j][col] > arr[j + 1][col]) {
                for (int k = 0; k < 6; k++) {
                    int temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
    }
}

void printArray(int arr[][6], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); 
    }
}

void FCFS(int arr[][6],int n){

    arr[0][3] = arr[0][2]+arr[0][1];
    arr[0][4] = arr[0][3] - arr[0][1];
    arr[0][5] = arr[0][4] - arr[0][2];
    for(int i=1 ; i<n ; i++){
        
            if(arr[i][1] > arr[i-1][3]){
                arr[i][3] = arr[i][1]+arr[i][2];
            }
            else{
                arr[i][3] = arr[i-1][3]+arr[i][2];
            }
        
        arr[i][4] = arr[i][3] - arr[i][1];
        arr[i][5] = arr[i][4] - arr[i][2];
    }
}
//Non preemtive
void SJF(int arr[][6] , int n){
    arr[0][3] = arr[0][2] + arr[0][1];
    arr[0][4] = arr[0][3] - arr[0][1];
    arr[0][5] = arr[0][4] - arr[0][2];

    bubbleSort(arr,n,2,1);
    for(int i=1 ; i<n ; i++){
        arr[i][3] = arr[i-1][3]+arr[i][2];
    
       arr[i][4] = arr[i][3] - arr[i][1];
       arr[i][5] = arr[i][4] - arr[i][2];
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int nums[n][6];

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            nums[i][j] = 0;
        }
    }

    
    for (int i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time, and Burst Time for process %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &nums[i][j]);
        }
    }

    bubbleSort(nums, n, 1 , 0);  

    printf("\nAfter Bubble Sort based on Arrival Time:\n");
    printArray(nums, n);

    // SJF(nums,n);
    SJF(nums,n);   bubbleSort(nums,n , 0 , 0);
    printf("\nAfter Sjf Function:\n");
    printArray(nums,n);


    return 0;
}
