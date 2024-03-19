#include<iostream>
#include<cstdlib>
#include<fstream>
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
int actual_pst(int * a,int n,int el)
{
    int grt=0;
    int sml=0;
    int indx_pst;
    for(int i=0;i<n;i++)
    {
        if(a[i]<el){ 
            sml++;
        }
        else if(a[i]>el){
            grt++;
        }
        else{
            indx_pst=i;
        }
    }
    int t=a[indx_pst];
    a[indx_pst]=a[sml];
    a[sml]=t;

    int fst=0;
    int last=n-1;
    int i;
    int j;
    while(fst<last)
    {
        for(int i=fst;i<sml;i++)
        {
            if(a[i]>el){
                fst=i;
                break;
            }
        }
        fst=i;
        for(int j=n-1;j<sml;j--)
        {
            if(a[j]<el){
                last=j;
                break;
            }
        }
        last=j;
        if(fst<last){
            int t=a[fst];
            a[fst]=a[last];
            a[last]=t;
        }
    }
}
int main ()
{
    double time1,time2,avgtime;
    for (int j = 1000; j <= 100000; j += 1000)
    {
        int a[j];
        for(int k=0;k<j;k++){
            a[k]=rand()%2;
        }
        time1=(double)clock();
        int t = 0;

        for (int i=1;i<= 10;i++)
        {
           t= actual_pst(a,j,a[10]);
           cout<<t<<" ";
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10;
        cout<<avgtime<<" ";
        WriteDataToFile(j,(avgtime*100));
    }
    return 0;
}