#include<stdio.h>
#include<stdlib.h>


void takeInput(int n, int pid[], int bt[], int priority[]) {
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time and Priority for Process %d: ", pid[i]);
        scanf("%d%d", &bt[i], &priority[i]);
    }
}

void sortByPriority(int n, int pid[], int bt[], int priority[]) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                temp = priority[i]; priority[i] = priority[j]; priority[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }
}

void calculateWaitingTime(int n , int bt[] , int wt[]){
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void calculateTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

int main(){
    int n;
    int pid[10], bt[10], priority[10];
    int wt[10], tat[10];

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    takeInput(n, pid, bt, priority);
    sortByPriority(n, pid, bt, priority);   

}