#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[100001];
queue<int> q;
int odl[100001];
char odwiedzony[100001];
int a,b,n,m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        odl[i]= -1;
    }

    q.push(1);
    odl[1] = 0;
    odwiedzony[1]=1;

    while(!q.empty()){
        int v = q.front();
        int dl = G[v].size();
        for(int i=0;i<dl;i++){
            if(!odwiedzony[G[v][i]]){
                q.push(G[v][i]);
                odl[G[v][i]] = odl[v]+1;
                odwiedzony[G[v][i]]=1;
            }
        }
        q.pop();
    }

    for(int i=1;i<=n;i++){
        cout<<odl[i]<<'\n';
    }

    return 0;
}