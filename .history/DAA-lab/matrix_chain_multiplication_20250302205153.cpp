#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class MatrixChainMultiplication {
private:
    int n;

    void getdata(int c)
    {
        cout << "Enter values for a " << endl;
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
