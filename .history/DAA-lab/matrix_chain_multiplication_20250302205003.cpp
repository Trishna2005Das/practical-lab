#include <iostream>
#include <ctime>
using namespace std;

class Search {
private:
    int n, *arr, key, count, index;
    double timediff[12];
    string type[4] = {"Sorted Ascending array", "Sorted Descending Array", "Unsorted array", "Sorted and Unsorted mixed array"};

    void linear() {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                index = i;
                break;
            }
            count++;
        }
    }

    void display() {
        if (index == -1) {
    }

  

public:
    void operations(){

    }
    
};

int main()
{
    Search s;
    s.operations();
    return 0;
}
