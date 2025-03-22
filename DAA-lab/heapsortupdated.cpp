#include <iostream>
#include <ctime>
using namespace std;

class Sort{

private :
int n,*arr;
double timediff[12];
string type [4]= {"Sorted Ascending array","Sorted Descending Array","Unsorted array", "Sorted and Unsorted mixed array"};

void heapify(int i){
    int parent=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && arr[l]>arr[parent]){
        parent=l;
    }
    if(r<n && arr[r]>arr[parent]){
        parent=r;
    }
    if(parent!=i){
        swap(arr[parent],arr[i]);
        heapify(parent);
    }
                

}

void heapsort(){
for(int i=n/2-1;i>=0;i--){
    heapify(i);

}
for(int i=n-1;i>=0;i--){
    swap(arr[0],arr[i]);
    heapify(0);

}


}

void getdata(int c)
	{	cout<<"Enter values for a "<<type[c]<<endl;
		cout << "Enter the size of the array :";
		cin >> n;
		arr = new int[n];
		cout << "Enter the elements of the array : ";
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

	}

    void display()
	{
		cout << "The elements of the array are : " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	void calculatetime(clock_t start, clock_t end, int i){
		timediff[i*3]=double(start) / CLOCKS_PER_SEC;
		timediff[i*3+1]=double(end) / CLOCKS_PER_SEC;
		timediff[i*3+2] = double(end - start) / CLOCKS_PER_SEC;		
	}
	void displaytimediff() {
    int slow = 0, fast = 0; 
    cout << "The time differences between the 4 types of sorting are as follows:" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "For " << type[i] << ":" << endl;
        cout << "Initial time: " << timediff[i * 3] << " seconds" << endl;
        cout << "Final time: " << timediff[i * 3 + 1] << " seconds" << endl;
        cout << "Time taken: " << timediff[i * 3 + 2] << " seconds" << endl;

        
        if (timediff[i * 3 + 2] < timediff[fast * 3 + 2]) {
            fast = i;
        }
        if (timediff[i * 3 + 2] > timediff[slow * 3 + 2]) {
            slow = i;
        }
    }

    
    cout << "According to the above comparison of time differences, " << type[fast]
         << " is taking the least time to perform merge sort, with a complexity of "
         << timediff[fast * 3 + 2] << " seconds." << endl;

    cout << "And " << type[slow]
         << " is taking the most time compared to others, with a complexity of "
         << timediff[slow * 3 + 2] << " seconds." << endl;
}

public:
	void operations()
	{

	for (int i=0;i<4;i++){
		getdata(i);
		cout << "Before sorting : " << endl;
		display();

		clock_t start = clock(); 

		heapsort();

		clock_t end = clock(); 

		cout << "After Sorting : " << endl;
		display();

		calculatetime(start,end,i);

		delete[] arr;
		}
	displaytimediff();

	}
};

int main()
{
	Sort s;
	s.operations();
	return 0;
}