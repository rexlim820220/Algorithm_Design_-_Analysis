#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <new>

using namespace std;

enum type{LOVE=1,ENJOY=2};

int *types;
vector<int> *adj;

int reverse_type(int type);

bool Bipartite(int src);

int main(void)
{
    int a;
    cin>>a;
    while(a--)
    {
        int n,m;
        cin>>n>>m;
        adj=new vector<int> [n+1];
        for(int i=0;i<m;i+=1)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        types=new int [n+1];
        for(int i=1;i<=n;i+=1){types[i]=0;}
        //execute DFS
        bool flag=true;
        vector<int>amen;
        deque<bool>color;
        for(int i=1;i<=n;i+=1)
        {
            if(!types[i])
            {
                if(!Bipartite(i)){
                    flag=false;
                }
                else{flag=true;}
            }
        }
        for(int i=1;i<=n;i+=1){
            cout<<types[i]<<' ';
        }
        cout<<'\n';
        delete[]adj;
        delete[]types;
    }
    return 0;
}

int reverse_type(int Type)
{
    return (Type==type::LOVE)?type::ENJOY:type::LOVE;
}

bool Bipartite(int src)
{
    types[src]=type::LOVE;
    int s=types[src];
    bool flag=true;
    queue<vector<int>> q;
    q.push(adj[src]);
    while(!q.empty())
    {
        auto tmp=q.front();
        q.pop();
        for(auto &i:tmp)
        {
            if(!types[i])
            {
                types[i]=reverse_type(s);
                q.push(adj[i]);
                if(flag){s=types[i];}
            }
            else if(types[i]==s)
            {
                return false;
            }
        }
    }
    return true;
}
