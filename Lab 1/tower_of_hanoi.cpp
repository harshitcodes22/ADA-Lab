//Tower of hanoi
#include<iostream>
#include<fstream>
#include<random>
#include<time.h>
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
void th(int n, char source, char destination, char spare){
    if(n==1){
       cout<<"Move from "<<source<<" to"<< destination<<endl;
    }
    else{
        th(n-1,source,spare,destination);
        th(1,source,destination,spare);
        th(n-1,spare,destination,source);
    }
}
void Algo(){
    double avgTime, time1, time2;
    for(int j=1;j<10;j++){
        time1=(double)clock();
        for(int i=0;i<10;i++){
            th(j,'A','B','C');
        }
        time2=(double)clock();
        avgTime=(double)(time2-time1)/10;
        cout<<avgTime<<" ";
        WriteDataToFile(j,avgTime);
    }
}
int main(){
    Algo();
    return 0;
}