#include <iostream>
#include <ctime>
using namespace std;

class lcs {
    int m, n, **table;
    string s1, s2;

    void getdata() {
        cout << "Enter first string: ";
        cin >> s1;
        cout << "Enter second string: ";
        cin >> s2;

        m = s1.length();
        n = s2.length();

        table = new int*[m + 1];
        for (int i = 0; i <= m; i++) {
            table[i] = new int[n + 1];
            for (int j = 0; j <= n; j++) {
                table[i][j] = 0;
            }
        }
    }

    int fillmatrix() {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    table[i][j] = table[i - 1][j - 1] + 1;
                } else {
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }
        return table[m][n];
    }

    void display() {
        cout << "LCS Table:\n";
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
    }

    string subsequence() {
        string s3 = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                s3 = s1[i - 1] + s3;
                i--;
                j--;
            } else if (table[i - 1][j] > table[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return s3;
    }

public:
    void operation() {
        getdata();
        cout << "Length of LCS: " << fillmatrix() << endl;
        display();
        cout << "Longest Common Subsequence: " << subsequence() << endl;

        for (int i = 0; i <= m; i++) {
            delete[] table[i];
        }
        delete[] table;
    }
};

int main() {
    lcs ob;
    ob.operation();
    return 0;
}