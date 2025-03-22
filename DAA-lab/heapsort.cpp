#include <iostream>
#include <ctime>
using namespace std;


void heapify(int arr[],int n,int i){
    int parent=i;
    int l=2*i;
    int r=2*i+1;
    
    if(l<=n && arr[l]>arr[parent]){
        parent=l;
    }
    if(r<=n && arr[r]>arr[parent]){
        parent=r;
    }
    if(parent!=i){
        swap(arr[parent],arr[i]);
        heapify(arr,n,parent);
    }
                

}

void heapsort(int arr[],int n){
for(int i=n/2;i>=0;i--){
    heapify(arr,n,i);

}
for(int i=n;i>=0;i--){
    swap(arr[0],arr[i]);
    heapify(arr,n,0);

}


}

int main(){
 int arr[7]={9,4,3,8,10,2,5};
 heapsort(arr,7-1);
 for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
 }
 cout<<endl;
 return 0;
}