#include<iostream>
#include<fstream>
#include<time.h>
#include<limits>
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
void prims(int *cost[],int n, int *t[]){
    int *near=new int[n];
    int minimum, mincost, k,l;

    minimum=cost[0][1];
    k=0;
    l=1;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(cost[i][j]<minimum){
                minimum=cost[i][j];
                k=i;
                l=j;
            }
        }
    }
    t[0][0]=k;
    t[0][1]=l;

    for(int i=0;i<n;i++){
        if(cost[i][k]<cost[i][l]){
            near[i]=k;
        }
        else
        near[i]=l;
    }
    near[k]=near[l]=0;
    
    for(int j=1;j<n-1;j++){
        int u;
        mincost=numeric_limits<int>::max();

        for(int i=0;i<n;i++){
            if(near[i]!=0 && cost[i][near[i]]<mincost){
                u=i;
                mincost=cost[i][near[i]];
            }
        }
        t[j][0]=u;
        t[j][1]=near[u];
        near[u]=0;

        for(int k=0;k<n;k++){
            if(near[k]!=0 && cost[k][near[k]]>cost[u][k]){
                near[k]=u;
            }
        }
    }
}
int main(){
    double time1, time2, avgtime;
    for(int k=10;k<10000;k+=100){
    int **cost=new int *[k];
    int **t = new int*[k-1];
    for(int i=0;i<k;i++){
        cost[i]=new int[k];
        if(i<k-1){
            t[i]=new int[2];
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
                cost[i][j]=cost[j][i]=(rand()%100)+1;
        }
    }
    time1=(double)clock();
    for(int j=0;j<10;j++){
    prims(cost,k,t);
    }
    time2=(double)clock();
    for(int i=0;i<k;i++){
        delete[] cost[i];
        if(i<k-1){
            delete[] t[i];
        }
    }
    avgtime=(double)(time2-time1)/10;
    cout<<k<<" - "<<avgtime<<endl;
    WriteDataToFile(k,avgtime);
    delete[] cost;
    delete[] t;
    }
    return 0;
}