#include <iostream>
#include <ctime>
using namespace std;

class Search {
private:
    int n, *arr, key;
    double timediff[12];
    string type[4] = {"Sorted Ascending array", "Sorted Descending Array", "Unsorted array", "Sorted and Unsorted mixed array"};

    bool checkSorted() {
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    void mergesort(int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }

    void merge(int low, int mid, int high) {
        int leftSize = mid - low + 1;
        int rightSize = high - mid;
        int* left = new int[leftSize];
        int* right = new int[rightSize];

        for (int i = 0; i < leftSize; i++) left[i] = arr[low + i];
        for (int i = 0; i < rightSize; i++) right[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = low;
        while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) arr[k++] = left[i++];
            else arr[k++] = right[j++];
        }

        while (i < leftSize) arr[k++] = left[i++];
        while (j < rightSize) arr[k++] = right[j++];

        delete[] left;
        delete[] right;
    }

    int binary(int low, int high) {
        int mid = (low + high) / 2;
        while (low <= high) {
            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) high = mid - 1;
            else low = mid + 1;
            mid = (low + high) / 2;
        }
        return -1;
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void keysearch(int index) {
        if (index == -1) cout << "Element does not exist\n";
        else cout << "Element found at index: " << index << endl;
    }

    void getdata(int c) {
        cout << "Enter values for a " << type[c] << endl;
        cout << "Enter array size: ";
        cin >> n;
        arr = new int[n];
        cout << "Enter array elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << "Enter element to search: ";
        cin >> key;
    }

    void calculatetime(clock_t start, clock_t end, int i) {
        timediff[i * 3] = double(start) / CLOCKS_PER_SEC;
        timediff[i * 3 + 1] = double(end) / CLOCKS_PER_SEC;
        timediff[i * 3 + 2] = double(end - start) / CLOCKS_PER_SEC;
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
    void operations() {
        for (int i = 0; i < 4; i++) {
            getdata(i);
            cout << "Before sorting:\n";
            display();

            clock_t start = clock();

            if (!checkSorted()) {
                mergesort(0, n - 1);
            }
            int index = binary(0, n - 1);

            clock_t end = clock();

            cout << "After sorting:\n";
            display();
            keysearch(index);
            calculatetime(start, end, i);

            delete[] arr;
        }
        displaytimediff();
    }
};

int main() {
    Search s;
    s.operations();
    return 0;
}
