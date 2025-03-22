#include <iostream>
#include <ctime>
using namespace std;

class sort{
    int n, *arr;
    void heapify(int i){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        
        if(l<n && arr[l]>arr[largest]){
            largest=l;
        }
        if(r<n && arr[r]>arr[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(largest);
        }
                    
    
    }
    void build_heap(){
        for(int i=n/2-1;i>=0;i--){
            heapify(i);
        
        }
    }
    
    void heapsort(){
        build_heap();
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(0);
        
        }

    }
    void heap_increase_key(int i,int key){
        if(key<arr[i]){
            cout<<"error";
        }
        arr[i]=key;
        int parent=i/2;
        while(i>0 && arr[parent]<arr[i]){
            swap(arr[i],arr[parent]);
            i=parent;
        }
    }
    void heap_insert(int key){
        cout<<"enter key";
        cin>>key;
        //icrease the size of the array by 1
        n=n+1;
        //insert the element at the end of the array
        arr[n-1]=key;
        int i=n-1;
        while(i!=0 && arr[i]>arr[(i-1)/2]){
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
        heap_increase_key(i,key);
    }
    int heap_maximum(){
        return arr[0];
      

    }

    int heap_extract_max(){
        if (n<1){
            cout<<"underflow";

        }
        int max=arr[0];
        swap(arr[0],arr[n-1]);
        n=n-1;
        heapify(0);
        return max;
    }


    void getdata()
	{
		cout << "Enter the size of the array :";
		cin >> n;
		arr = new int[n];
		cout << "Enter the elements of the array : ";
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

	}
public:
    void operations(){
     
        getdata();
        build_heap();

    }
};
int main(){
    sort s;
    s.operations();
    return 0;

}