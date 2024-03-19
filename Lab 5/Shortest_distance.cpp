#include <iostream>
#include <limits>
#include <time.h>
#include <fstream>
using namespace std;

const int INF = numeric_limits<int>::max(); // for the maximum value of int type
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
void sssp(int n, int **cost, int v, int *dist) {
    int *s = new int[n];
    for (int i = 0; i < n; i++) {
        dist[i] = cost[v][i];
        s[i] = false; // in NV
    }
    s[v] = true;
    for (int j = 2; j < n - 1; j++) {
        int u = -1;
        int minDist = INF;
        // choose a vertex u st s[u]=f
        for (int i = 0; i < n; i++) {
            if (!s[i] && dist[i] < minDist) {
                u = i;
                minDist = dist[i];
            }
        }
        s[u] = true; // putting in V
        // all neighbours of w of u st s[w]=false
        if (u == -1) {
            break;
        }
        for (int w = 0; w < n; w++) {
            if (!s[w] && (dist[w] > dist[u] + cost[u][w])) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
    delete[] s;
}

int main() {
    double time1,time2,avgtime;
    for(int k=1;k<100;k+=10){
    int **cost = new int *[k];
    for (int i = 0; i < k; i++) {
        cost[i] = new int[k];
        for (int j = 0; j < k; j++) {
            cost[i][j] = rand()%1000;
        }
    }

    int *dist = new int[k];
    time1=(double)clock();
    for(int j=0;j<10;j++){
    sssp(k, cost, 0, dist);
    }
    for(int i=0;i<k;i++){
    cout<<dist[k]<<" ";
    }
    time2=(double)clock();
    avgtime=(double)(time2-time1)/10;
    cout << avgtime*100<< " ";
    WriteDataToFile(k,(avgtime*100));
    for (int i = 0; i < k; i++) {
        delete[] cost[i];
    }
    delete[] cost;
    delete[] dist;
    }
    return 0;
}
