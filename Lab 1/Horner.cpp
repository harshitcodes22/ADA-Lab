//Horner
#include<iostream>
#include<time.h>
#include<fstream>
#include<random>
using namespace std;
void WriteTofile(int i,double avgTime){
    ofstream fout("data.txt",ios::app);
        if(fout.is_open()){
            fout<<i<<","<<avgTime<<endl;
            fout.close();
        }
        else{
            cout<<"Unable to open file for writing data."<<endl;
        }
}
int Horner(int a[],int n,int m,int x){
    if(n==m) {return a[m];}
    else{
    return (a[n]+x*Horner(a,n+1,m,x));}
}
void Algo(){
    double time1,time2,avgTime;
    int x;
    cout<<"Enter value of x: ";
    cin>>x;
    for(int i=1;i<1000;i+=10){
        int *a = new int[i];
        for( int j=0;j<i;j++){
            a[j]=rand();
        }
        time1=(double)clock();
            for(int j=0;j<10;j++){
                Horner(a,1,i,x);
            }
        time2=(double)clock();
        avgTime=(time2-time1)/10;
        cout<<i<<"-"<<avgTime<<endl;
        WriteTofile(i,avgTime);
    }
}
int main(){
    Algo();
    return 0;
}