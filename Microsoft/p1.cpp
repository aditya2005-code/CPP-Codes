// 9. Count Triangles from Adjacent Elements

// Autodesk-reported variation

// Given an array, examine every three consecutive elements and determine whether they can form a triangle.

// Example:

// [1,2,2,4]

// → [1,0]

// This exact style was reported in an Autodesk SDE intern OA.

// Variations:

// Count all possible triangles.
// Find maximum triangle perimeter.
// Find valid triplets after sorting.

#include<bits/stdc++.h>
using namespace std;

class Triangle{
    public:

    bool valid(int a , int b , int c){
        return a+b > c && b+c > a && c+a > b;
    }

    int validTriangles(vector<int>& arr){
        int n = arr.size();
        int i = 0 , j = 1 , k = 2;
        int res = 0;

        while(k < n){
            int a = arr[i];
            int b = arr[j];
            int c = arr[k];

            if(valid(a,b,c)) res++;

            i++;
            j++;
            k++;
        }
        return res;
    }

    int maximumTrianglePrameter(vector<int>& nums){
        int n = nums.size();

        int res = INT_MIN;

        int i = 0 , j = 1 , k =2;
        while(k < n){
            int a = nums[i];
            int b = nums[j];
            int c = nums[k];

            if(valid(a,b,c)){
                res = max(res , a+b+c);
            }

            i++;
            j++;
            k++;
        }

        return res;
    }


};

int main(){
    vector<int> arr = {1 ,2 ,2 , 4  ,5, 6 , 6};

    int n = arr.size();

    Triangle t;

    cout<<"Number of valid triangles : "<<t.validTriangles(arr);
    cout<<"Maximum perimter og triangle : "<<t.maximumTrianglePrameter(arr);


    return 0;

}