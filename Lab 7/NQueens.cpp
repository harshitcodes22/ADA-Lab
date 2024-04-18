#include <iostream>
#include <cstdlib>
using namespace std;
int x[100];
bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}
void Nqueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } else {
                Nqueens(k + 1, n);
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of Queens (n): ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid input!\n";
        return 1;
    }
    Nqueens(1, n);
    return 0;
}