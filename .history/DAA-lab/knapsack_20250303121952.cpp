#include <iostream>
#include <ctime>
using namespace std;

class knapsack{
int w,n;
int *objects,*profit,*weight;
int **arr;

void getdata(){
    cout<<"enter no of objects";
    cin>>n;
    cout<<"enter maximum weight";
    cin>>w;
    cout<<"enter weight of n objects";
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    arr = new int*[w + 1];
    
    for(int i=0;i<n;i++){
        arr[i] = new int[w + 1];

    }
}

public:
void operations(){
    
}
};
