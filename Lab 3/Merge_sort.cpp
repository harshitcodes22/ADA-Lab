#include<iostream>
#include<cstdlib> 
#include<time.h>
#include<fstream>
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
void merge(int *a, int left, int mid, int right){
    int n1 = mid - left +1;
    int n2 = right - mid;

    int *L= new int[n1];
    int *R= new int[n2];

    for(int i=0;i<n1;i++){
        L[i]=a[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=a[right+j];
    }

    int i=0;
    int j=0;
    int k=left;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}
void complex(){
    for (int i=1;i<=10000;i+=1000){
        int t= i*log(i);
        WriteToFile(i,t);
    }
}
void MergeSort(int *a,int low, int high){
    if(low <high){
        int mid = (low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main(){
    double time1, time2, avgtime;
    for(int j=1;j<=10000;j+=1000){
        int *a=new int[j];
        for(int k=0;k<j;k++){
            a[k]=rand();
        }
        time1=(double)clock();
        for(int i=0;i<10;i++){
            MergeSort(a,0,j-1);
        }
        time2=(double)clock();
        avgtime=(time2-time1)/10;
        cout<<avgtime<<" ";
        WriteDataToFile(j,avgtime*30000);
    }
    complex();
    return 0;
}