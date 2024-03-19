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
void WriteDataToFile2(int i, double avg_weight) {
    ofstream fout("data1.txt", ios::app);
    if (fout.is_open()) {
        fout<<i << "," <<avg_weight<<endl;
        fout.close();
    } else {
        cout << "Unable to open file for writing data." << endl;
    }
}
void WriteDataToFile3(int i, double avg_prof_weight) {
    ofstream fout("data2.txt", ios::app);
    if (fout.is_open()) {
        fout<<i << "," <<avg_prof_weight<< endl;
        fout.close();
    } else {
        cout << "Unable to open file for writing data." << endl;
    }
}
void sort_profit(int p[], int w[], int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j]<p[j+1]){
                int temp_p=p[j];
                p[j]=p[j+1];
                p[j+1]=temp_p;

                int temp_w=p[j];
                p[j]=p[j+1];
                p[j+1]=temp_w;
            }
        }
    }
}
void sort_weight(int p[], int w[], int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(w[j]<w[j+1]){
                int temp_p=p[j];
                p[j]=p[j+1];
                p[j+1]=temp_p;

                int temp_w=p[j];
                p[j]=p[j+1];
                p[j+1]=temp_w;
            }
        }
    }
}
void sort_profit_weight(int p[], int w[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            double ratio_i = (double)p[i]/w[i];
            double ratio_j = (double)p[j]/w[j];
            if(ratio_i>ratio_j){
                int temp_p=p[j];
                p[j]=p[i];
                p[i]=temp_p;

                int temp_w=w[j];
                w[j]=w[i];
                w[i]=temp_w;
            }
        }
    }
}
void knapsack(int n, int max, int p[], int w[]){
    int max_profit=max;
    int *Sol= new int[n];
    int i;
    for(int i=0;i<n;i++){
        Sol[i]=0;
    }
    for(i=0;i<n;i++){
        if(w[i]<max_profit){
            Sol[i]=1;
            max_profit=max_profit-w[i];
        }
        else{
            break;
        }
    }
    if(i<n){
        Sol[i]=max_profit/w[i];
    }
}
void Algo(){
    double time1, time2, time3, time4, time5, time6, avg_profit, avg_weight, avg_prof_weight;
    for(int i=1000;i<=100000;i+=100){
        int *w=new int[i];
        int *p=new int[i];
        for(int k=0;k<i;k++){
            w[k]=rand()%1000+1;
            p[k]=rand()%100+1;
        }
        int weight;
        weight=rand()%1000*i;
        time1 = (double)clock();
        for(int k=0;k<10;k++){
            sort_profit(p,w,i);
            knapsack(i,weight,p,w);
        }
        time2 = (double)clock();
        avg_profit=(time2-time1)/10;
        time3 = (double)clock();
        for(int k=0;k<10;k++){
            sort_weight(p,w,i);
            knapsack(i,weight,p,w);
        }
        time4 = (double)clock();
        avg_weight=(time4-time3)/10;
        time5 = (double)clock();
        for(int k=0;k<10;k++){
            sort_profit_weight(p,w,i);
            knapsack(i,weight,p,w);
        }
        time6 = (double)clock();
        avg_prof_weight=(time6-time5)/10;
        cout<<i<<". Avg_profit: "<<avg_profit<<" Avg_weight: "<<avg_weight<<" Avg_prof_weight: "<<avg_prof_weight<<"."<<endl;
        WriteDataToFile(i,avg_profit);
        WriteDataToFile2(i,avg_weight);
        WriteDataToFile3(i,avg_prof_weight);
    }
}
int main(){
    Algo();
    return 0;
}