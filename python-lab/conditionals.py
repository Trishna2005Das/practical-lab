 void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (tempArr[j] > tempArr[j + 1]) {
                    swap(tempArr[j], tempArr[j + 1]);
                }
            }
        }
    }

    void insertionSort() {
        for (int i = 1; i < n; i++) {
            int key = tempArr[i];
            int j = i - 1;
            while (j >= 0 && tempArr[j] > key) {
                tempArr[j + 1] = tempArr[j];
                j--;
            }
            tempArr[j + 1] = key;
        }
    }

    void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (tempArr[j] < tempArr[min_idx]) {
                    min_idx = j;
                }
            }
            swap(tempArr[min_idx], tempArr[i]);
        }
    }

    void heapify(int i, int size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && tempArr[left] > tempArr[largest])
            largest = left;

        if (right < size && tempArr[right] > tempArr[largest])
            largest = right;

        if (largest != i) {
            swap(tempArr[i], tempArr[largest]);
            heapify(largest, size);
        }
    }

    void heapSort() {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(i, n);

        for (int i = n - 1; i > 0; i--) {
            swap(tempArr[0], tempArr[i]);
            heapify(0, i);
        }
    }
