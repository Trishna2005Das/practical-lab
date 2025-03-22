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
            cout << "error";
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
        cout << "Enter key: ";
        cin >> key;

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
            cout << "Underflow\n";
            return -1;
        }
        int max = arr[0];
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(0, n);
        return max;
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
    void operations() {
        getdata();
        build_heap();
        heapsort();
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
