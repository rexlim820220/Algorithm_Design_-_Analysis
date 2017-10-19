#include <iostream>
#include <functional>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;

unsigned long long int *weight;
std::map<string,int> h;

unsigned long long int group_up(int i,int j,int m)
{
    char tmp[99];
    sprintf(tmp,"%d_%d_%d",i,j,m);
    string s=tmp;
    auto it=h.find(s);
    if(it!=h.end()){
        return h[s];
    }
    if(j>i){
        h[s]=-1;
        return -1;
    }

    if (i-j+1<m){
        h[s]=-1;
        return -1;
    }

    if (i==j){
        h[s]=0;
        return 0;
    }

    if(m==1){
        int sum0=0;
        int people=i-j+1;
        for(int a=0;a<i-j;a++){
            sum0+=weight[a+j]*(people-a-1);
        }
        h[s]=sum0;
        return sum0;
    }
    int k=i;


    int min0=0x3f3f3f3f;
    while(k>=j){
        int a=group_up(i,k,1);
        int b=group_up(k-1,j,m-1);
        if(a==-1 || b==-1){
            k--;
            continue;
        }
        int tmp=a+b;
        if (tmp<min0){
            min0=tmp;
        }
        k--;
    }

    if(min0==0x3f3f3f3f){
        h[s]=-1;
    }
    else{
        h[s]=min0;
    }

    return h[s];
}

int main(int argc,char **argv)
{
    int n,k;
    while(cin>>n>>k)
    {
        weight = new unsigned long long int [n+1];
        weight[0]=0x3f3f3f3f;
        for(int i=1;i<n;i+=1)
        {
            cin>>weight[i];
        }
        cout<<group_up(n,1,k)<<endl;
        delete[]weight;
    }
    return 0;
}



/*int main(int argc,char **argv)
{
    int n,k;
    while(cin>>n>>k)
    {
        int arr[n];
        for(int i=0;i<n;i+=1)
        {
            cin>>arr[i];
        }
        int DP[n][n][k];
        for(int i=0;i<n;i+=1)
        {
            for(int j=0;j<n;j+=1)
            {
                for(int m=0;m<k;m+=1)
                {
                    int people=i-j;
                    if (m>people){
                        DP[i][j][m]=-1;
                    }
                    else if(i==j){
                        DP[i][j][m]=0;
                    }
                    else if(m==0){
                        int sum=0;
                        int people=i-j+1;
                        for(int ii=i;ii<j-1;ii++){
                            sum+=arr[ii]*(people-ii-i-1);
                        }
                        DP[i][j][m]=sum;

                    }
                    else{
                        DP[i][j][m]=0x3f3f3f3f;
                    }
                }
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                for(int m=1;m<k;m+=1)
                {
                    cout<<i<<" "<<j<<" "<<m<<endl;
                    cout<<DP[i][j][k]<<endl;
                    if(DP[i][j][k]==-1)continue;
                    int min=0x3f3f3f3f;
                    for(int k1=i;k1>=j;k1--){
                        cout<<i<<" xx "<<j<<" "<<m<<endl;
                        if(DP[i][k1][m]==-1)continue;
                        if(DP[k1+1][j][m]==-1)continue;
                        cout<<"here2"<<endl;
                        int tmp=DP[i][k1][m]+DP[k1+1][j][m];
                        if (tmp<min) min=tmp;
                    }
                    DP[i][j][k]=min;

                }
            }
        }
        cout<<DP[n-1][0][k-1]<<endl;
        cout<<0x3f3f3f3f<<endl;

    }
    return 0;
}*/
