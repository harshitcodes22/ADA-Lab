#include<iostream>
#include<fstream>
#include<random>
#include<time.h>
using namespace std;
void WriteToFile(int i, double avgTime) {
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()) {
        fout << i << "," << avgTime << endl;
        fout.close();
    }
    else {
        cout << "Unable to open file for writing data." << endl;
    }
}
int sum(int a[], int k) {
    if (k == 1) return a[0];
    else return (a[k - 1] + sum(a, k - 1));
}
void Algo() {
    double avgTime, time1, time2;
    for(int i = 13000 ; i < 100000; i += 10000) {
        int *a = new int[i];
        for( int j=0;j<i;j++){
            a[j]=rand();
        }
        time1 = (double)clock();
        for(int k = 0; k < 10; k++) {
            sum(a, i);
        }
        time2 = (double)clock();
        avgTime = (time2 - time1) / 10;
        cout << i << "-" << avgTime << endl;
        WriteToFile(i, avgTime);
    }
}
int main() {
    Algo();
    return 0;
}