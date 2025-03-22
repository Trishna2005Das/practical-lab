#include <iostream>
#include <ctime>
using namespace std;

class Sort{
private:
    int n, *arr, *temp;
    double timediff[16 * 4];
    string type[4] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Heap Sort"};
    int sizes[4] = {5, 10, 15, 20};

    void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (temp[j] > temp[j + 1]) {
                    swap(temp[j], temp[j + 1]);
                }
            }
        }
    }

    void insertionSort() {
        for (int i = 1; i < n; i++) {
            int key = temp[i];
            int j = i - 1;
            while (j >= 0 && temp[j] > key) {
                temp[j + 1] = temp[j];
                j--;
            }
            temp[j + 1] = key;
        }
    }

    void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (temp[j] < temp[min_idx]) {
                    min_idx = j;
                }
            }
            swap(temp[min_idx], temp[i]);
        }
    }

    void heapify(int i, int size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && temp[left] > temp[largest])
            largest = left;

        if (right < size && temp[right] > temp[largest])
            largest = right;

        if (largest != i) {
            swap(temp[i], temp[largest]);
            heapify(largest, size);
        }
    }

    void heapSort() {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(i, n);

        for (int i = n - 1; i > 0; i--) {
            swap(temp[0], temp[i]);
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

    void display(int* array) {
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void calculateTime(clock_t start, clock_t end, int i, int j) {
        timediff[i * 16 + j * 4] = double(start) / CLOCKS_PER_SEC;
        timediff[i * 16 + j * 4 + 1] = double(end) / CLOCKS_PER_SEC;
        timediff[i * 16 + j * 4 + 2] = double(end - start) / CLOCKS_PER_SEC;
    }

    void displayTimeDiff() {
        cout << "\nTime taken by sorting algorithms for different array sizes:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "\nArray Size " << sizes[i] << ":" << endl;
            for (int j = 0; j < 4; j++) {
                cout << type[j] << " -> Start: " 
                     << timediff[i * 16 + j * 4] << " sec,\n End: " 
                     << timediff[i * 16 + j * 4 + 1] << " sec,\n Time taken: " 
                     << timediff[i * 16 + j * 4 + 2] << " sec\n" << endl;
            }
        }
    }

public:
    void operations() {
        for (int i = 0; i < 4; i++) {
            getdata(sizes[i]);
            cout << endl;
            
            for (int j = 0; j < 4; j++) {
                temp = new int[n];
                for (int k = 0; k < n; k++) {
                    temp[k] = arr[k];
                }

                cout << "Executing " << type[j] << ":" << endl;
                cout << "Before sorting (Size " << n << "): ";
                display(temp);

                clock_t start = clock();
                if (j == 0) bubbleSort();
                else if (j == 1) insertionSort();
                else if (j == 2) selectionSort();
                else heapSort();
                clock_t end = clock();

                cout << "After sorting:            ";
                display(temp);
                calculateTime(start, end, i, j);
                delete[] temp;
            }
            delete[] arr;
        }
        displayTimeDiff();
    }
};

int main() {
    Sort sc;
    sc.operations();
    return 0;
}