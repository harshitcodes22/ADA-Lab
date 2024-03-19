#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<math.h>
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
void WriteToFile(int i, double avgTime){
    ofstream fout("data2.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}
void WriteFile(int i, double avgTime){
    ofstream fout("data1.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}
int Partition(int *a, int low, int high){
    int i=low;
    int j=high;
    int p=a[low];
    do{
        do{
            i=i+1;
        }while(a[i]<p);
        do{
            j=j-1;
        }while(a[j]>p);
        if(i<j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }while(i<=j);
    a[low]=a[j];
    a[j]=p;
    return j;
}
void QS(int *a,int low,int high){
    int j;
    if(low<high){
        j=Partition(a,low,high);
        QS(a,low,j-1);
        QS(a,j+1,high);
    }
}
void average(){
    int t;
    for(int i=1;i<10000;i+=1000){
        t=i*log(i);
        WriteToFile(i,t);
    }
} 
void worst(){
    int t;
    for(int i=1;i<10000;i+=1000){
        t=(i*i)/100;
        WriteFile(i,t);
    }
}
int main(){
    double time1,time2,avgtime;
    for(int i=1;i<10000;i+=1000){
        int *a=new int[i];
        for(int j=0;j<i;j++){
        a[j]=rand();
        }
        time1=(double)clock();
        for(int k=1;k<10;k++){
            QS(a,0,i-1);
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout << avgtime*10000<< " ";
        WriteDataToFile(i,(avgtime*20000));
        delete []a;
    }
    average();
    worst();
    return 0;
}