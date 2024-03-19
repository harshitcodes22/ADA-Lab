// Selection sort
#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;
void WriteToFile(int i, double avgTime)
{
    ofstream fout("data.txt", ios::app);
    if (fout.is_open())
    {
        fout << i << "," << avgTime << endl;
        fout.close();
    }
    else
    {
        cerr << "Unable to open file for writing data." << endl;
    }
}
void selection_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
        {
            if (a[k] < a[j])
            {
                j = k;
            }
        }
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}
void Algo()
{
    double time1, time2, avgTime;
    for (int i = 10000; i <= 50000; i += 5000)
    {
        int *a = new int[i];
        for (int j = 0; j < i; j++)
        {
            a[j] = rand();
        }
        time1 = (double)clock();
        for (int k = 0; k < 10; k++)
        {
            selection_sort(a, i);
        }
        time2 = (double)clock();
        avgTime = (time2 - time1) / 10.0;
        cout << i << "-" << avgTime << endl;
        WriteToFile(i, avgTime);
    }
}
int main()
{
    Algo();
    return 0;
}