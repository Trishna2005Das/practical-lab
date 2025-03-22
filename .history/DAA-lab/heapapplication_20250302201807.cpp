#include <iostream>
#include <ctime>
using namespace std;

class Sort {
private:
    int n, *arr;
    double timediff[4][3];
    string type[4] = {"Sorted Ascending array", "Sorted Descending Array", "Unsorted array", "Sorted and Unsorted mixed array"};

    void heapify(int i, int size) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(largest, size);
        }
    }

    void build_heap() {
        for (int i = n / 2 - 1; i >= 0; i--) heapify(i, n);
    }

    void heapsort() {
        build_heap();
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(0, i);
        }
    }

    void heap_increase_key(int i, int key) {
        if (key < arr[i]) {
            cout << "New key is smaller than current key, operation not allowed" << endl;
            return;
        }
        arr[i] = key;
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heap_insert() {
        int key;
        cout << "Enter key to insert: ";
        cin >> key;

        int* newArr = new int[n + 1];
        for (int i = 0; i < n; i++) newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;

        arr[n] = -1; // Insert a dummy value at the last position
        n++;
        heap_increase_key(n - 1, key);
    }

    int heap_maximum() {
        return arr[0];
    }

    int heap_extract_max() {
        if (n < 1) {
            cout << "Heap underflow, cannot extract key" << endl;
            return -1;
        }
        int maxVal = arr[0];
        arr[0] = arr[n - 1];
        n--;
        if (arr[0] > arr[(0 - 1) / 2]) {
            heap_increase_key(0, arr[0]);
        } else {
            heapify(0, n);
        }
        return maxVal;
    }

    void getdata(int c) {
        cout << "Enter values for a " << type[c] << endl;
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

    void calculatetime(clock_t start, clock_t end, int i) {
        timediff[i][0] = double(start) / CLOCKS_PER_SEC;
        timediff[i][1] = double(end) / CLOCKS_PER_SEC;
        timediff[i][2] = double(end - start) / CLOCKS_PER_SEC;
    }

    void displaytimediff() {
        int fast = 0, slow = 0;
        cout << "The time differences between the 4 types of sorting are as follows:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "For " << type[i] << ":" << endl;
            cout << "Initial time: " << timediff[i][0] << " seconds" << endl;
            cout << "Final time: " << timediff[i][1] << " seconds" << endl;
            cout << "Time taken: " << timediff[i][2] << " seconds" << endl;

            if (timediff[i][2] < timediff[fast][2]) fast = i;
            if (timediff[i][2] > timediff[slow][2]) slow = i;
        }

        cout << type[fast] << " is taking the least time, with " << timediff[fast][2] << " seconds." << endl;
        cout << type[slow] << " is taking the most time, with " << timediff[slow][2] << " seconds." << endl;
    }

public:
    void operations() {
        for (int i = 0; i < 4; i++) {
            getdata(i);
            cout << "Before sorting: " << endl;
            display();

            clock_t start = clock();
            heapsort();
            clock_t end = clock();

            cout << "After Sorting: " << endl;
            display();

            calculatetime(start, end, i);
            delete[] arr;
        }
        displaytimediff();
    }
};

int main() {
    Sort s;
    s.operations();
    return 0;
}
