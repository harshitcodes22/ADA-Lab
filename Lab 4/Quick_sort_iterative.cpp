#include<iostream>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void WriteDataToFile(int i, double avgTime) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << "," << avgTime << endl;
        fout.close();
    }
    else {
        cout << "Unable to open file for writing data. " << endl;
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int low, int high) {
    int i = low;
    int j = high;
    int p = a[low];
    do {
        do {
            i = i + 1;
        } while (a[i] < p);
        do {
            j = j - 1;
        } while (a[j] > p);
        if (i < j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    } while (i <= j);
    a[low] = a[j];
    a[j] = p;
    return j;
}

void quickSortIterative(int a[], int low, int high) {
    stack<int> stack;

    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        int pivotIndex = partition(a, low, high);

        if (pivotIndex - 1 > low) {
            stack.push(low);
            stack.push(pivotIndex - 1);
        }

        if (pivotIndex + 1 < high) {
            stack.push(pivotIndex + 1);
            stack.push(high);
        }
    }
}

int main() {
    double time1, time2, avgtime;
    for (int i = 1000; i <= 10000; i += 1000) {
        int *a = new int[i];
        for (int j = 0; j < i; j++) {
            a[j] = rand();
        }
        time1=(double)clock();
        for (int k = 0; k < 10; k++) {
            int *a = new int[i];
            quickSortIterative(a, 0, i - 1);
            delete[] a;
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout << avgtime<< " ";
        WriteDataToFile(i, avgtime);
        delete[] a;
    }
    return 0;
}
