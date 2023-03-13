#include <iostream>

using namespace std;

int norek,dni,a,b;
int *wielkosc,*rep;

int Find(int x){
    if(rep[x]!=x) rep[x]=Find(rep[x]);
    return rep[x];
}

void Union(int x,int y){
    int a = Find(x);
    int b = Find(y);
    if(a!=b){
        rep[a] = b;
        wielkosc[b]+=wielkosc[a];
    }
}

int main()
{
    cin>>norek>>dni;

    rep = new int[norek+1];
    wielkosc = new int[norek+1];

    for(int i=1;i<=norek;i++){
            rep[i]=i;
            wielkosc[i]=1;
    }

    for(int i=1;i<=dni;i++){
        cin>>a>>b;
        Union(a,b);
        cout<<wielkosc[Find(1)]<<endl;
    }

    return 0;
}