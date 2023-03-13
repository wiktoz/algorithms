#include <iostream>
#include <vector>

using namespace std;

int n,m,q, *odw, nr=1,a,b,x,y;
vector<int> G[100001];

void DFS(int s){
    odw[s]=nr;

    for(int i=0;i<G[s].size();i++){
        if(odw[G[s][i]]==0) DFS(G[s][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    odw = new int[n+2];

    for(int i=1;i<=n;i++){
        odw[i] = 0;
    }

    for(int i=1;i<=m;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    DFS(1);

    for(int i=1;i<=n;i++){
        if(odw[i]==0){
            nr=i;
            DFS(i);
        }
    }

    for(int i=1;i<=q;i++){
        cin>>x>>y;

        if(odw[x]==odw[y]) cout<<"T"<<'\n';
        else cout<<"N"<<'\n';
    }

    return 0;
}