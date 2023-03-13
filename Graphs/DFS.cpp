#include <iostream>
#include <vector>

using namespace std;

int w,k,a,b;
char odwiedzony[100001];

vector<int> G[100001];

void PwG(int v)
{
    odwiedzony[v] = true;

    for(int i=0;i<G[v].size();i++){
        if(odwiedzony[G[v][i]]==0) PwG(G[v][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>w>>k;

    for(int i=0;i<k;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    PwG(1);

    for(int i=1;i<=w;i++){
        if(odwiedzony[i]){
            cout<<"TAK";
        }
        else cout<<"NIE";
        cout<<'\n';
    }

    return 0;
}