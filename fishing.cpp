#include <iostream>
#include <new>
using namespace std;

struct Pond{
    int fishing_;
    int decrease;
};

Pond *pond;

int main(int argc,char **argv)
{
    pond=0;
    int a;
    cin>>a;
    while(a--)
    {
        int n,k,d=0;
        cin>>n>>k;
        pond = new Pond[n+1];
        for(int i=1;i<=n;i+=1)
        {
            cin>>pond[i].fishing_>>pond[i].decrease;
        }
        int DP[k][n+1];
        for(int i=0;i<k;i+=1)
        {
            for(int j=0;j<=n;j+=1)
            {
                DP[i][j]=(i>=j?0:-1);
            }
        }
        for(int j=1;j<=n;j+=1)
        {
            int f=pond[j].fishing_;
            int d=pond[j].decrease;
            for(int i=j;i<k;i+=1)
            {
                DP[j][i]=DP[j][i-1]+f-(i-j)*d;
                cout<<DP[j][i]<<' ';
            }
            cout<<endl;
        }
        /*print*
        for(int i=1;i<=n;i+=1)
        {
            for(int j=0;j<i;j+=1){DP[i][j]=0;}
            for(int j=0;j<k;j+=1)
            {
                cout<<DP[i][j]<<' ';
            }
            cout<<endl;
        }*/
        delete[]pond;
    }
    return 0;
}
