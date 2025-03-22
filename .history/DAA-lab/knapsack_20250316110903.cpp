#include <iostream>
using namespace std;

class Knapsack {
    int n, W;
    int *w, *p, **dp;

public:
    Knapsack(int items, int capacity) {
        n = items;
        W = capacity;
        w = new int[n];
        p = new int[n];
        dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = new int[W + 1]();
    }

    void getdata() {
        cout << "Enter weights and profits: ";
        for (int i = 0; i < n; i++)
            cin >> w[i] >> p[i];
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

    int solve() {
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

    void displayMatrix() {
        cout << "Knapsack DP Table:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
    }

    ~Knapsack() {
        delete[] w;
        delete[] p;
        for (int i = 0; i <= n; i++)
            delete[] dp[i];
        delete[] dp;
    }
};

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;

    Knapsack k(n, W);
    k.getdata();
    cout << "Maximum profit: " << k.solve() << endl;
    k.displayMatrix();
    return 0;
}
