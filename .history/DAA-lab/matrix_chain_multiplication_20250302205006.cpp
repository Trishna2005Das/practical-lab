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
            cout << "Element not found" << endl;
        } else {
            cout << "Element found at index: " << index << endl;
            cout << "Number of comparisons done: " << count << endl;
        }
    }

    void calculatetime(clock_t start, clock_t end, int i) {
        timediff[i * 3] = double(start) / CLOCKS_PER_SEC;
        timediff[i * 3 + 1] = double(end) / CLOCKS_PER_SEC;

int main()
{
    Search s;
    s.operations();
    return 0;
}
