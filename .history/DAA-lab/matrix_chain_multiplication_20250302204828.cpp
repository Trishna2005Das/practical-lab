#include <iostream>
#include <ctime>
using namespace std;

class Search
{
    int n, *arr, key, count, index;
    double timediff[12];
    string type[4] = {"Sorted Ascending array", "Sorted Descending Array", "Unsorted array", "Sorted and Unsorted mixed array"};

    void linear()
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                index = i;
                break;
            }
            count++;
        }
    }

    void display()
    {
        if (index == -1)
        {
            cout << "Element not found" << endl;
        }
        else
        {
            cout << "Element found at index: " << index << endl;
            cout << "Number of comparisons done: " << count << endl;
        }
    }

    void calculatetime(clock_t start, clock_t end, int i)
    {
        timediff[i * 3] = double(start) / CLOCKS_PER_SEC;
        timediff[i * 3 + 1] = double(end) / CLOCKS_PER_SEC;
        timediff[i * 3 + 2] = double(end - start) / CLOCKS_PER_SEC;
    }

    void getdata(int c)
    {
        cout << "Enter values for a " << type[c] << endl;
        cout << "Enter the size of the array: ";
        cin >> n;
        arr = new int[n];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter key to search: ";
        cin >> key;
    }

    void displaytimediff()
    {
        int slow = 0, fast = 0;
        cout << "The time differences between the 4 types of sorting are as follows:" << endl;

        for (int i = 0; i < 4; i++)
        {
            cout << "For " << type[i] << ":" << endl;
            cout << "Initial time: " << timediff[i * 3] << " seconds" << endl;
            cout << "Final time: " << timediff[i * 3 + 1] << " seconds" << endl;
            cout << "Time taken: " << timediff[i * 3 + 2] << " seconds" << endl;

            if (timediff[i * 3 + 2] < timediff[fast * 3 + 2])
            {
                fast = i;
            }
            if (timediff[i * 3 + 2] > timediff[slow * 3 + 2])
            {
                slow = i;
            }
        }

        cout << "According to the above comparison of time differences, " << type[fast]
             << " is taking the least time to perform linear search, with a complexity of "
             << timediff[fast * 3 + 2] << " seconds." << endl;

        cout << "And " << type[slow]
             << " is taking the most time compared to others, with a complexity of "
             << timediff[slow * 3 + 2] << " seconds." << endl;
    }

public:
    void operations()
    {
        for (int i = 0; i < 4; i++)
        {
            getdata(i);
            count = 0, index = -1;
            clock_t start = clock();

            linear();

            clock_t end = clock();
            display();
            calculatetime(start, end, i);

            delete[] arr;
        }
        displaytimediff();
    }
};

int main()
{
    Search s;
    s.operations();
    return 0;
}
