#include <iostream>

using namespace std;
class setmethod{
    int n, W;
    int *w, *p, **dp;
    setmethod() {
        cout << "Enter number of items: ";
        cin >> n;
        cout << "Enter knapsack capacity: ";
        cin >> W;

        w = new int[n];
        p = new int[n];
        dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = new int[W + 1]();

        cout << "Enter weights of the items: ";
        for (int i = 0; i < n; i++)
            cin >> w[i];
        cout << "Enter profits of the items: ";
        for (int i = 0; i < n; i++)
            cin >> p[i];
        sortItems();
    }
    void sortItems() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (w[j] > w[j + 1]) {
                    swap(w[j], w[j + 1]);
                    swap(p[j], p[j + 1]);
                }
            }
        }
    }
    
public:

void operations(){
    
}
};
int main(){
setmethod s;
s.operations();
return 0;

}