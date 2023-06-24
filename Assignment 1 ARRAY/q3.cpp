#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int target){
    int s=0;
    int e=n;
    while(s<=e){
        int mid = (s+e)/2;
        
        if(arr[mid]==target){
            return mid;
        }
        
        else if(arr[mid]>target){
            e=mid-1;
        }
        
        
        else if(arr[mid]<target){
            s=mid+1;
        }
    }
    
    return -1;
}


int main() {
    // Write C++ code here
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int target;
    cin>>target;
    
    cout<<binarySearch(arr,n,target);
    
    return 0;
}

//Binary Search has Time Complexity -- O(log N)