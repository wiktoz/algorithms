#include <iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> q;

int n,k;
int waga[105];
int cena[105];

int T[10005][105];

void wypiszT(){
    for(int j=0;j<=n;j++){
        for(int i=0;i<=k;i++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}

void wypiszKolejke(){
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
}

int main()
{
    cin>>n>>k;
    waga[0] = 0;
    cena[0] = 0;

    for(int i=1;i<=n;i++) cin>>waga[i];
    for(int i=1;i<=n;i++) cin>>cena[i];

    for(int j=1;j<=n;j++){
        for(int i=1;i<=k;i++){
            if(waga[j]>i){
                T[i][j] = T[i][j-1];
            }
            else{
                T[i][j] = max(T[i][j-1],T[i-waga[j]][j-1]+cena[j]);
            }
        }
    }

    int i=k,j=n;

    while(i!=0 && j!=0){
        if(T[i][j]==T[i][j-1]) j--;
        else if(T[i][j]==(T[i-waga[j]][j-1]+cena[j])){
            q.push(j);
            i-=waga[j];
            j--;
        }
        else{
            i--;
            j--;
        }
    }

    cout<<T[k][n]<<endl;
    cout<<q.size()<<endl;
    wypiszKolejke();

    return 0;
}