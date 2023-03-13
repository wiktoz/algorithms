#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[100001];
vector<int> v;
queue<int> q;
int a,b,n,m,*k,l;

int main()
{
    cin>>n>>m;
    k = new int[n+1];

    for(int i=1;i<=n;i++) k[i]=0;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
        k[b]++;
    }

    for(int i=1;i<=n;i++) if(k[i]==0) q.push(i);

    for(int i=1;i<=n;i++){
        if(q.empty()) break;

        l = q.front();
        q.pop();

        while(!G[l].empty()){
            k[G[l].back()]--;

            if(k[G[l].back()]==0){
                q.push(G[l].back());
            }
            G[l].pop_back();
        }
        v.push_back(l);
    }

    int dl = v.size();
    if(dl<n) cout<<"NIE";
    else{
        cout<<"TAK"<<'\n';
        for(int i=0;i<dl;i++) cout<<v[i]<<" ";
    }

    return 0;
}