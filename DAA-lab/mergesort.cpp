#include <iostream>
#include <ctime>
using namespace std;

class sort{
void merge(int arr[],int low,int mid,int high){
int n1=mid-low+1;
int n2=high-mid;
int leftarray[n1];
int rightarray[n2];

for(int i=0;i<n1;i++){
leftarray[i]=arr[low+1];
}

for(int i=0;i<n2;i++){
rightarray[i]=arr[mid+1+i];
}
int i=0,j=0,k=low;
while(i<n1 && j<n2){
if(leftarray[i]<=rightarray[j]) arr[k++]=leftarray[i++];
else arr[k++]=rightarray[j++];

if(i<n1) arr[k++]=leftarray[i++];
if(j<n2) arr[k++]=rightarray[j++];
}

}

public:
void mergesort(int arr[],int low,int high){
int mid=(low+high)/2;

if(low<high){
merge(arr,low,mid);
merge(arr,mid+1,high);
merge(arr,low,mid,high);
}
}
};
int main(){
sort ms;
cout << "Enter number of elements: ";
int n;
cin>>n;
int arr[n];
cout << "Enter the elements: ";
for(int i=0;i<n;i++){
cin>>arr[i];
}
clock_t start_time = clock();
    cout << "Start time: " << static_cast<double>(start_time) / CLOCKS_PER_SEC << " seconds\n";

ms.mergesort(arr,0,n-1);
clock_t end_time = clock();
    cout << "End time: " << static_cast<double>(end_time) / CLOCKS_PER_SEC << " seconds\n";
cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
  
}
