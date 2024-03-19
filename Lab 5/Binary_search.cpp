#include<iostream>
#include<fstream>
#include<time.h>
#include<algorithm>
using namespace std;
void WriteDataToFile(int i, double avgTime) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << "," << avgTime << endl;
        fout.close();
    }
    else {
        cout << "Unable to open file for writing data. " << endl;
    }
}
int binary_search(int a[],int low, int high,int el){
    if(low<high){
    int mid = (low + high)/2;
    if(el<a[mid]){
        high=mid-1;
    }
    else if(el>a[mid]){
        low=mid+1;
    }
    else{
        return mid;
    }
}
}
int main(){
    double time1, time2, avgtime;
    int el;
    for(int i=10;i<1000;i+=100){
        int *a=new int[i];
        for(int k=0;k<i;k++){
            a[k]=(rand()%100)+1;
        }
        sort(a,a+i);
        for(int k=0;k<i;k++){
            cout<<a[k]<<" ";
        }
        cout<<"Enter the element you want to find: ";
        cin>>el;
        time1=(double)clock();
        for(int j=0;j<10;j++){
           int s= binary_search(a,0,i,el);
           cout<<s<<" ";
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout<<i<<" - "<<avgtime<<endl;
        WriteDataToFile(i,avgtime);
    }
    return 0;
}