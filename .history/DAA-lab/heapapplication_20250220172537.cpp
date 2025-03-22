#include <iostream>
using namespace std;

class sort {
    int n, *arr;

    void heapify(int i, int size) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < size && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(largest, size);
        }
    }

    void build_heap() {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, n);
        }
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
            cout << "Error: new key is smaller than current key." << endl;
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

        // Increase the array size by 1
        int* newArr = new int[n + 1];
        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;

        arr[n] = key;
        n++;
        heap_increase_key(n - 1, key);
    }

    int heap_maximum() {
        return arr[0];
    }

    int heap_extract_max() {
        if (n < 1) {
            cout << "Underflow" << endl;
            return -1;
        }
        int maxVal = arr[0];
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(0, n);
        return maxVal;
    }

    void getdata() {
        cout << "Enter the size of the array: ";
        cin >> n;
        arr = new int[n];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

public:
    // Display function to print the array
    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Operations function demonstrating all heap functions
    void operations() {
        getdata();
        cout << "\nOriginal array: ";
        display();

        // Build heap and display
        build_heap();
        cout << "After building heap: ";
        display();

        // Perform heapsort and display sorted array
        heapsort();
        cout << "After heapsort: ";
        display();

        // Rebuild heap for further operations (since heapsort destroys heap structure)
        // First, create a copy of the sorted array and then rebuild the heap.
        int* copyArr = new int[n];
        for (int i = 0; i < n; i++) {
            copyArr[i] = arr[i];
        }
        delete[] arr;
        arr = copyArr;
        build_heap();
        cout << "After rebuilding heap from sorted array: ";
        display();

        // Insert a new key and display
        heap_insert();
        cout << "After inserting key: ";
        display();

        // Display the maximum element in the heap
        cout << "Heap maximum: " << heap_maximum() << endl;

        // Extract the maximum element and display the updated heap
        int maxVal = heap_extract_max();
        cout << "Extracted max: " << maxVal << endl;
        cout << "After extracting max: ";
        display();

        // Increase key at a specified index
        int index, newKey;
        cout << "Enter index to increase key: ";
        cin >> index;
        cout << "Enter new key: ";
        cin >> newKey;
        heap_increase_key(index, newKey);
        cout << "After increasing key: ";
        display();
    }

    ~sort() {
        delete[] arr;
    }
};

int main() {
    sort s;
    s.operations();
    return 0;
}
