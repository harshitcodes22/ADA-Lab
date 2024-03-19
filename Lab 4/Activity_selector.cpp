#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;
void WriteDataToFile(int i, double avg_profit) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout<<i << "," <<avg_profit<<endl;
        fout.close();
    } else {
        cout << "Unable to open file for writing data." << endl;
    }
}

void sort_start(int s[],int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(s[j]>s[j+1]){
                int temp_s=s[j];
                s[j]=s[j+1];
                s[j+1]=temp_s;
            }
        }
    }
}

void sort_finish(int f[],int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(f[j]>f[j+1]){
                int temp_f=f[j];
                f[j]=f[j+1];
                f[j+1]=temp_f;
            }
        }
    }
}

void AS(int a[],int s[],int f[], int n){
    int *sol=new int[n];
    int i=0,j=0;
    for(int j=1;j<n ;j++){
        sol[i]=0;
    }
    sol[i]=a[i];
    for(int j=1;j<n ;j++){
        if(s[j]>=f[i]){
            sol[j]=a[j];
            i=j;
        }
    }
}
void algo(){
    double time1, time2, avgtime;
    for(int i=1000;i<=10000;i+=1000){
        int *s=new int[i];
        int *f=new int[i];
        int *a=new int[i];
        for(int k=0;k<i;k++){
            s[k]=rand()%100+1;
            f[k]=s[k]+rand()%100+1;
            a[k]=rand()%1000+1;
        }
        sort_start(s,i);
        sort_finish(f,i);
        time1 = (double)clock();
        for(int k=0;k<10;k++){
            AS(a,s,f,i);
        }
        time2 = (double)clock();
        avgtime=(time2-time1)/10;
        cout << avgtime<< " ";
        WriteDataToFile(i, avgtime);
        delete[] a;
        delete[] s;
        delete[] f;
    }
}
int main(){
    algo();
    return 0;
}