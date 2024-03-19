#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
#include<random>
#include<algorithm>
using namespace std;
void WriteDataToFile(int i, double avgTime){
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}
void sorted_list(int * list1,int * list2,int n,int m)
{
    int x=0;
    int y=0;
    int z=0;
    int list3[m+n];
    while(y<m && x<n)
    {
        if(list1[x]<list2[y]){
            list3[z]=list1[x];
            x++;
            z++;
        }
        else{
            list3[z]=list2[y];
            y++;
            z++;
        }
    }
    while(x<n){
        list3[z]=list1[x];
        x++;
        z++;        
    }
    while(y<m){
        list3[z]=list2[y];
        y++;
        z++;        
    }
}
int main()
{
    double time1,time2,avgtime;
    for (int j = 10000; j <= 1000000; j += 10000)
    {
        int *a = new int[j];
        int *b = new int[j/10];
        for (int k = 0; k < j; k++)
        {
            a[k] = rand();
        }
        for (int k = 0; k < j/10; k++)
        {
            b[k] = rand();
        }
        sort(a,a+j);
        sort(b,b+j/10);
        time1=(double)clock();
        for (int i=1;i<=10;i++)
        {
            sorted_list(a,b,j,j/10);
        }

        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout << avgtime*100<< " ";
        WriteDataToFile(j,(avgtime*100));

        delete[] a;
        delete[] b;
    }
}