#include<iostream>
using namespace std;

int main(){
    int arr[]={2,7,11,15};
    
    int targetsum;
    cout<<"Enter target"<<endl;
    cin>>targetsum;
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    //int ans=0;

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==targetsum){
                cout<<i<<" "<<j;
                break;
            }   
        }
    }
    
}