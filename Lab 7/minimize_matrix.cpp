#include <iostream>
#include <climits>
using namespace std;
void printParenthesis(int i, int j, int brac[][5], char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, brac[i][j], brac, name);
    printParenthesis(brac[i][j] + 1, j, brac, name);
    cout << ")";
}

void MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int brac[5][5];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    brac[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
    char name = 'D';
    cout << "Optimal Parenthesization: ";
    printParenthesis(1, n - 1, brac, name);
    cout << endl;
}
int main() {
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    MatrixChainOrder(arr, N);
    return 0;
}