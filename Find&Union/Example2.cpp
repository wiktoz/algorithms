#include <bits/stdc++.h>

using namespace std;

int *rep, *masa, *maxIQ, *minIQ;
int n, b1, b2, r1;
string polecenie;

int Find(int x){
    if(rep[x]==x) return x;
    else{
        rep[x]=Find(rep[x]);
        return (rep[x]);
    }
}

void Union(int a, int b){
    int x = Find(a);
    int y = Find(b);

    if(x!=y){
         rep[x] = rep[y];
         maxIQ[y] = max(maxIQ[y], maxIQ[x]);
         minIQ[y] = min(minIQ[y], minIQ[x]);
         masa[y] = masa[y] + masa[x];
    }
}

int main(){
    cin>>n;

    rep=new int[n];
    masa=new int[n];
    maxIQ=new int[n];
    minIQ=new int[n];

    for(int i=1; i<=n; i++)
        rep[i] = i;

    for(int i=1; i<=n; i++){
        cin>>masa[i]>>minIQ[i];
        maxIQ[i] = minIQ[i];
    }

    while( cin>>polecenie){
        if(polecenie=="JOIN"){
            cin>>b1>>b2;
            Union(b1, b2);
        }
        else if(polecenie=="MASA"){
            cin>>b1;
            r1 = Find(b1);
            cout<<masa[r1]<<'\n';
        }
        else if(polecenie=="IQ_MIN"){
            cin>>b1;
            r1 = Find(b1);
            cout<<minIQ[r1]<<'\n';
        }
        else if(polecenie=="IQ_MAX"){
            cin>>b1;
            r1 = Find(b1);
            cout<<maxIQ[r1]<<'\n';
        }
    }

    return 0;
}