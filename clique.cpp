#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool seek(vector<int>v,int target)
{
    return find(v.begin(),v.end(),target)!=v.end();
}

int main(void)
{
    int n,m;
    ios_base::sync_with_stdio(0);
    while(cin>>n>>m)
    {
        vector<int> adj[n];
        for(int i=0;i<m;i+=1)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int a;
        switch(m)
        {
            case 0:
                a=1;
                break;
            default:
                a=2;
                break;
        }
        for(int i=0;i<n;i+=1)
        {
            if(adj[i].size()==1)
            {
                int neighbor=adj[i].back();
                adj[i].pop_back();
                auto now=find(adj[neighbor].begin(),adj[neighbor].end(),i);
                adj[neighbor].erase(now);
            }
        }
        bool flag3=false,flag4=false;
        for(int i=0;i<n;i+=1)
        {
            bool fort=false;
            if(adj[i].size()>=2){
                flag3=true;
                int x=adj[i].at(0),y=adj[i].at(1);
                if(adj[x].size()<2||adj[y].size()<2)
                {
                        flag3=false;
                }
                else{
                    if(adj[x].size()<adj[y].size())
                    {
                        if(seek(adj[x],y)){fort=true;}
                    }
                    else{
                        if(seek(adj[y],x)){fort=true;}
                    }
                }
                if(!fort){flag3=false;}
            }
            if(flag3){break;}
        }
        for(int i=0;i<n;i+=1)
        {
            if(adj[i].size()==3)
            {
                flag4=true;
                int x=adj[i].at(0),y=adj[i].at(1),z=adj[i].at(2);
                if(!seek(adj[x],y)){flag4=false;}
                if(flag4 && !seek(adj[x],z)){flag4=false;}
                if(flag4 && !seek(adj[y],z)){flag4=false;}
            }
            if(flag4){break;}
        }
        if(flag3){a=3;}
        if(flag4){a=4;}
        cout<<a<<'\n';
    }
    return 0;
}
