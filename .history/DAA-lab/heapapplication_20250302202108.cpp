#include <iostream>
#include <ctime>
using namespace std;

class Sort {
private:
    int n, *arr;
   

public:
    void operations() {
        int c;
        cout << "Enter the choice: ";
        cin >> c;
        getdata(c);
        heapsort();
        display();
        heap_insert();
        display();
        cout << "Maximum element: " << heap_maximum() << endl;
        heap_extract_max();
        display();

     
    }
};

int main() {
    Sort s;
    s.operations();
    return 0;
}
