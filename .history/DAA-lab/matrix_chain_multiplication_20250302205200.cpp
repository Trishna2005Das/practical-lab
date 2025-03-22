#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class MatrixChainMultiplication {
private:
    int n;
    vector<int> t;
    vector<vector<int>> m;
    vector<vector<int>> s;

    void getdata() {
        cout << "Enter the number of matrices: ";
        cin >> n;
        t.resize(n + 1);
        cout << "Enter the dimensions of the matrices: ";
        for (int i = 0; i <= n; i++) {
            cin >> t[i];
        }
        m.resize(n + 1, vector<int>(n + 1, 0));
        s.resize(n + 1, vector<int>(n + 1, 0));
    }

    void matrixChainMultiplication() {
        for (int i = 1; i <= n; i++) {
            m[i][i] = 0;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                m[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++) {
                    int q = m[i][k] + m[k + 1][j] + t[i - 1] * t[k] * t[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }

    void printOptimalParenthesis(int i, int j) {
        if (i == j) {
            cout << "A" << i;
        } else {
            cout << "(";
            printOptimalParenthesis(i, s[i][j]);
            printOptimalParenthesis(s[i][j] + 1, j);
            cout << ")";
        }
    }

public:
    void operations() {
        getdata();
        matrixChainMultiplication();