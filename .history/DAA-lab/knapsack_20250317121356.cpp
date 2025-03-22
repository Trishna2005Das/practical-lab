#include <iostream>
using namespace std;

class Knapsack {
    int n, W;
    int *w, *p, **dp;

public:
    Knapsack() {
        cout << "Enter number of items: ";
        cin >> n;
        cout << "Enter knapsack capacity: ";
        cin >> W;

        w = new int[n];
        p = new int[n];
        dp = new int*[n + 1];
        for (int i = 0; i <= n; i++){
            dp[i] = new int[W + 1];
                for(int j=0;j<=W;j++){
                
            dp[i][j] = 0;
                }
        }
        cout << "Enter weights of the items: ";
        for (int i = 0; i < n; i++)
            cin >> w[i];
        cout << "Enter profits of the items: ";
        for (int i = 0; i < n; i++)
            cin >> p[i];
        sortweight();
    }

    void sortweight() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (w[j] > w[j + 1]) {
                    swap(w[j], w[j + 1]);
                    swap(p[j], p[j + 1]);
                }
            }
        }
    }

    void fillmatrix() {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (w[i - 1] <= j)
                    dp[i][j] = max(p[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][W];
    }

    void display() {
        cout << "Knapsack DP Table (" << n + 1 << " x " << W + 1 << "):\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
    }

    void operations() {
        cout << "Maximum profit: " <<fillmatrix() << endl;
        display();
        delete[] w;
        delete[] p;
        for (int i = 0; i <= n; i++)
            delete[] dp[i];
        delete[] dp;
    }

   
};

int main() {
    Knapsack k;
    k.operations();
    return 0;
}
