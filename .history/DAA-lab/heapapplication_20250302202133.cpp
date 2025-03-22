#include <iostream>
#include <ctime>
using namespace std;

class Sort {
private:
    int n, *arr;

    void getdata(int c) {
        cout << "Enter values for a "  << endl;
        cout << "Enter the size of the array: ";
        cin >> n;
        arr = new int[n];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) cin >> arr[i];
    }

    void display() {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }


public:
    void operations() {
       
        
     
    }
};

int main() {
    Sort s;
    s.operations();
    return 0;
}
