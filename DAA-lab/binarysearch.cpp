#include <iostream>
using namespace std;

class Search {
    int binary(int arr[],int n,int low,int high,int key){
        int mid=(low+high)/2;
        while(low<=high){
                if(arr[mid]==key){
                    return mid;
                }
                else if(arr[mid]>key){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            mid=(low+high)/2;
        }
    return -1;

    }
    void display(clock_t start, clock_t end){
         cout << "Start time: " << static_cast<double>(start) / CLOCKS_PER_SEC << " seconds\n";
         cout << "End time: " << static_cast<double>(end) / CLOCKS_PER_SEC << " seconds\n";
         cout<<"Duration:"<<double(end - start) / CLOCKS_PER_SEC<<endl;

    }
public:
void operations(){
    int n;
    cout<<"enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"enter elements of sorted array";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<<"enter element to search";
    int key;
    cin>>key;
    clock_t start = clock();
    int index=binary(arr,n,0,n-1,key);
    if(index==-1){
        cout<<"element does not exist";
    }
    else{
        cout<<"element exists at index:"<<index<<endl;
    }
    clock_t end = clock();
    display(start, end);
    

}

};

int main(){
    Search s;
    s.operations();
    return 0;


}