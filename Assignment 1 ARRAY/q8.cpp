#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,2,4};
    int n = 4;
    int ans = 0;
    for(int i=0;i<n;i++){
       for(int j =i+1;j<n;j++){
             if(arr[i]==arr[j]){
            ans = arr[i];
            break;
        }
       }
    }
    cout<<ans<<" "<<ans+1;
}