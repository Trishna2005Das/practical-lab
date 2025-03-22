#include <iostream>
#include <ctime>
using namespace std;

class quicksort{
int partition(int arr[],int n,int low,int high){
int pivot=arr[low];
int i=low;
int j=high;
while(i<j){
while(arr[i]<=pivot && i<high) i++;
while(arr[j]>pivot && j>low) j--;
if(i<j) swap(arr[i],arr[j]);
}
swap(arr[low],arr[j]);
return j;


}

public:
void quick(int arr[],int n,int low,int high){
if(low<high){
int part=partition(arr,n,low,high);
partition(arr,n,low,part-1);
partition(arr,n,part+1,high);
}
}
};
int main(){
quicksort qs;
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

qs.quick(arr,n,0,n-1);
clock_t end_time = clock();
    cout << "End time: " << static_cast<double>(end_time) / CLOCKS_PER_SEC << " seconds\n";
cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
  
}
