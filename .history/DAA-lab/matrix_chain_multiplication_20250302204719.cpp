#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void matrixChainMultiplication(vector<int>& t, int n, vector<vector<int>>& m, vector<vector<int>>& s) {
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

void printOptimalParenthesis(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> t(n + 1);
    cout << "Enter the dimensions of the matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> t[i];
    }

    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    matrixChainMultiplication(t, n, m, s);

    cout << "Minimum number of scalar multiplications: " << m[1][n] << endl;
    cout << "Optimal parenthesization: ";
    printOptimalParenthesis(s, 1, n);
    cout << endl;

    return 0;
}
