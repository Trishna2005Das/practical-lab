#include <iostream>
#include <ctime>
using namespace std;

class SortComparison {
private:
    int n, *arr;
    double timediff[16];
    string type[4] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Heap Sort"};

    // Bubble Sort Implementation
    void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Insertion Sort Implementation
    void insertionSort() {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Selection Sort Implementation
    void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            swap(arr[min_idx], arr[i]);
        }
    }

    // Heap Sort Implementation
    void heapify(int i, int size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest, size);
        }
    }

    void heapSort() {
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(i, n);

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(0, i);
        }
    }

    void getdata(int size) {
        n = size;
        arr = new int[n];
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void calculateTime(clock_t start, clock_t end, int sortType) {
        timediff[sortType * 4] = double(start) / CLOCKS_PER_SEC;
        timediff[sortType * 4 + 1] = double(end) / CLOCKS_PER_SEC;
        timediff[sortType * 4 + 2] = double(end - start) / CLOCKS_PER_SEC;
    }

    void displayTimeDiff() {
        cout << "Time taken by sorting algorithms for different array sizes:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << type[i] << " Performance:" << endl;
            cout << "Array Size " << n << " -> Start: " 
                 << timediff[i * 4] << " sec, End: " 
                 << timediff[i * 4 + 1] << " sec, Time taken: " 
                 << timediff[i * 4 + 2] << " sec" << endl;
        }
    }

public:
    void operations() {
        int sizes[] = {5, 10, 15, 20};
        for (int size : sizes) {
            getdata(size);
            
            // Bubble Sort
            cout << "Executing Bubble Sort:" << endl;
            cout << "Before sorting (Size " << n << "): ";
            display();
            
            int* bubbleArr = new int[n];
            copy(arr, arr + n, bubbleArr);
            
            clock_t start = clock();
            bubbleSort();
            clock_t end = clock();
            
            cout << "After sorting:            ";
            display();
            calculateTime(start, end, 0);
            
            // Restore original array
            copy(bubbleArr, bubbleArr + n, arr);
            delete[] bubbleArr;

            // Insertion Sort
            cout << "Executing Insertion Sort:" << endl;
            cout << "Before sorting (Size " << n << "): ";
            display();
            
            int* insertArr = new int[n];
            copy(arr, arr + n, insertArr);
            
            start = clock();
            insertionSort();
            end = clock();
            
            cout << "After sorting:            ";
            display();
            calculateTime(start, end, 1);
            
            // Restore original array
            copy(insertArr, insertArr + n, arr);
            delete[] insertArr;

            // Selection Sort
            cout << "Executing Selection Sort:" << endl;
            cout << "Before sorting (Size " << n << "): ";
            display();
            
            int* selectArr = new int[n];
            copy(arr, arr + n, selectArr);
            
            start = clock();
            selectionSort();
            end = clock();
            
            cout << "After sorting:            ";
            display();
            calculateTime(start, end, 2);
            
            // Restore original array
            copy(selectArr, selectArr + n, arr);
            delete[] selectArr;

            // Heap Sort
            cout << "Executing Heap Sort:" << endl;
            cout << "Before sorting (Size " << n << "): ";
            display();
            
            int* heapArr = new int[n];
            copy(arr, arr + n, heapArr);
            
            start = clock();
            heapSort();
            end = clock();
            
            cout << "After sorting:            ";
            display();
            calculateTime(start, end, 3);
            
            // Restore original array
            copy(heapArr, heapArr + n, arr);
            delete[] heapArr;
        }
        displayTimeDiff();
        delete[] arr;
    }
};

int main() {
    SortComparison sc;
    sc.operations();
    return 0;
}