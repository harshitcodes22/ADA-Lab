#include<iostream>
#include<fstream>
#include<time.h>
#include<random>
using namespace std;
void WriteToFile(int i,double avgTime){
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()){
        fout<<i <<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data."<<endl;
    }
}
char TT(char x[],int k,int n){
    if(k==n+1){
        for(int i=0;i<n;i++){
            cout<<x[i];
        }
        cout<<endl;
    }
    else{
        x[k]='T';TT(x,k+1,n);
        x[k]='F';TT(x,k+1,n);
    }
}
void Algo(){
    double time1,time2,avgTime;
    for(int i=0;i<10;i++){
        char x[10];
        time1=(double)clock();
        for(int j=0;j<10;j++){
            TT(x,0,i);
        }
        time2=(double)clock();
        avgTime=(time2-time1)/10;
        WriteToFile(i,avgTime);
    }
}
int main(){
    Algo();
    return 0;
}