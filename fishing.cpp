#include <iostream>
#include <algorithm>
#include <queue>
#include <new>

using namespace std;

struct Pond{
    int fishing_;
    int decrease;
};

class cmp{
public:
    int operator () (const int &lhs,const int &rhs)
    {
        return lhs<rhs;
    }
};

int main(int argc,char **argv)
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,k;
        cin>>n>>k;
        Pond *pond=new Pond[n+1];
        for(int i=1;i<=n;i+=1)
        {
            cin>>pond[i].fishing_>>pond[i].decrease;
        }
        int DP[n+1][k];
        for(int i=1;i<=n;i+=1)
        {
            int f=pond[i].fishing_;
            int d=pond[i].decrease;
            for(int j=i;j<k;j+=1)
            {
                DP[i][j]=f-(j-i)*d;
                if(DP[i][j]<0){DP[i][j]=0;}
                cout<<DP[i][j]<<' ';
            }
            cout<<endl;
        }
        int wait=k;
        unsigned long long int cost=0;
        priority_queue<unsigned long long int> greedy;
        for(int i=1;i<=n;i+=1)
        {
            for(int j=i;j<k;j+=1)
            {
                if(DP[i][j]>=DP[i+1][i+1])
                {
                    greedy.push(DP[i][j]);
                }
                else
                {
                    if(!greedy.empty()){greedy.pop();}
                    i+=1;
                    j=i;
                    greedy.push(DP[i][j]);
                }
            }
        }
        int time=k-1;
        while(!greedy.empty()&&time>0)
        {
            cost+=greedy.top();
            cout<<greedy.top()<<endl;
            greedy.pop();
            time-=1;
        }
        cout<<cost<<endl;
        delete[]pond;
    }
    return 0;
}

bool cmp(const int &lhs,const int &rhs)
{
    return rhs<lhs;
}
