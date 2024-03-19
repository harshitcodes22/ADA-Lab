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
int power( int n, int x){
    int power=1;
    while(n!=0){
        if(n%2==0){
            x=x*x;
            n=n/2;
        }
        else{
            power=power*x;
            n=n-1;
        }
    }
    return power;
}
int main(){
    double time1,time2,avgtime;
    for(int i=1;i<200;i+=10){
        int t=0;
        time1=(double)clock();
            for(int j=0;j<10;j=j+5){
             t=  power(i,2);
            }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout<<avgtime*100<<" ";
        WriteDataToFile(i,(avgtime*100));
    }
    return 0;
}