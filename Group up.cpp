#include <algorithm>
#include <iostream>
#include <cmath>
#include <new>
using namespace std;

int main(int argc,char **argv)
{
    int n,k;
    while(cin>>n>>k)
    {
        bool flag = false;
        if(n==k){flag=true;}
        int *arr=new int [n],cost=0,seat[k]={0},Partition[k]={0};
        for(int i=0;i<n;i+=1)
        {
            cin>>arr[i];
        }
        if(flag==true){cout<<'0'<<endl;}
        else{
            int j=0;
            for(int i=0;i<n-1;i+=1)
            {
                if(arr[i]>arr[i+1]&&j<k){
                    Partition[j]=arr[i];
                    seat[j]=i;
                    ++j;
                }
            }
            if(arr[n-1]>Partition[k-1]){seat[k-1]=n-1;}
            for(int i=0;i<n;i+=1)
            {
                if(!binary_search(seat,seat+k,i)){
                    int d=1e7;
                    for(int l=0;l<k;++l)
                    {
                        if(abs(i-seat[l])<=d&&seat[l]>i){d=abs(i-seat[l]);}
                    }
                    cost+=arr[i]*d;
                }
            }
            cout<<cost<<endl;
        }
        delete[]arr;
    }
    return 0;
}
