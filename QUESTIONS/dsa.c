#include<stdio.h>


int main(){
	
	int nums1[]={1,2,2,1};
	int nums2[]={2,2};
	int nums1Size=sizeof(nums1)/sizeof(int);
	int nums2Size=sizeof(nums2)/sizeof(int);
	
 
    int result[100];
    int k=0;
    for(int i=0 ;  i<nums1Size ; i++){
        for(int j=0; j<nums2Size ; j++){
            if(nums1[i]==nums2[j]){
               result[k]=nums1[i];
               k++;
               break;
            }
            
        }

    }
    int final[100];
    int a=0;
    final[0]=result[0];
    for(int i=1; i<k ;k++){
    	for(int j=1;j<k;k++){
    		if(result[j]==result[j+1] || result[j]==result[j-1]){
    			
    			
			}
			else{
				final[a]=result[i];
				a++;
			}
		}
	}
    for(int i=0;i<a;i++){
    	printf("%d\t",final[i]);
	}
	return 0;
}