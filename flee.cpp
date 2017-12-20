#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <new>
#define INF 0x3f3f3f3f
using namespace std;

struct Coordinate{
    int x;
    int y;
};

struct queueNode{
    Coordinate point;//this point
    int delta;//distance
};

int m,n;
int **graph,**table;
bool **visited;

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

bool isValid(int row, int col)
{
    return (row >= 0) && (row < m) &&
           (col >= 0) && (col < n);
}

void reset(int m,int n)
{
    for(int i=0;i<m;i+=1)
    {
        for(int j=0;j<n;j+=1)
        {
            visited[i][j]=false;
            table[i][j]=INF;
        }
    }
}
//pg.469
void BFS(vector<Coordinate> &des)
{
    reset(m,n);
    size_t a=des.size();
    for(auto &i:des){visited[i.x][i.y]=true;}
    queue<queueNode> q;
    for(size_t i=0;i<a;i+=1){
        queueNode s={des[i],0};
        q.push(s);
    }
    while(!q.empty())
    {
        queueNode cur=q.front();
        Coordinate now=cur.point;
        q.pop();
        for(int i=0;i<4;i+=1)
        {
            int row=now.x+rowNum[i];
            int col=now.y+colNum[i];
            if(isValid(row,col)&&graph[row][col]&&!visited[row][col])
            {
                visited[row][col]=true;
                queueNode adjroom={{row,col},cur.delta+1};
                table[row][col]=min(adjroom.delta,table[row][col]);
                q.push(adjroom);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    while(cin>>m>>n)
    {
        int aout=0,keluar=0;
        string temp;
        getline(cin,temp);
        graph=new int *[m];
        table=new int *[m];
        visited=new bool *[m];
        vector<Coordinate> _starts;
        vector<Coordinate> _ends;
        for(int i=0;i<m;i+=1)
        {
            string ss;
            getline(cin,ss);
            graph[i]=new int [n];
            table[i]=new int [n];
            visited[i]=new bool [n];
            for(int j=0;j<n;j+=1)
            {
                if(ss[j]=='F'){graph[i][j]=0;}
                else{
                    if(ss[j]=='P'){aout+=1;_starts.push_back({i,j});}
                    if(ss[j]=='E'){keluar+=1;_ends.push_back({i,j});}
                    graph[i][j]=1;
                }
                visited[i][j]=false;
            }
        }
        BFS(_ends);
        for(int i=0;i<aout;i+=1)
        {
            Coordinate src= _starts[i];
            if(table[src.x][src.y]<INF){
                cout<<table[src.x][src.y];
            }
            else{cout<<"Died";}
            cout<<'\n';
        }
        for(int i=0;i<m;i+=1){delete[]graph[i];delete[]table[i];delete[]visited[i];}
        delete graph;
        delete table;
        delete visited;
    }
    return 0;
}
