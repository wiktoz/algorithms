#include<bits/stdc++.h>
using namespace std;

int n, q, x, tmp;

pair<int, int> w[200];

const int MIL = 20001;

pair<int, int[200]> d[MIL];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> w[i].first; 
    for(int i=0; i<n; i++)
        cin >> w[i].second;

    cin >> q;

    for(int i=1; i<=q; i++){
        d[i].first = q+1;  //nieskonczonosc
        tmp = -1;
        for(int j=0; j<n; j++){
            if(i < w[j].first || d[i-w[j].first].second[j] == w[j].second)
                continue;

            if(d[i-w[j].first].first+1 < d[i].first){
                d[i].first = d[i-w[j].first].first+1;
                tmp = j;
            }
        }
        if(tmp != -1){
            for(int z=0; z<n; z++)
                d[i].second[z] = d[i-w[tmp].first].second[z];
            d[i].second[tmp]++;
        }
    }

    cout << d[q].first << '\n';
    for(int i=0; i<n; i++){
        cout << d[q].second[i] << ' ';
    }

    return 0;
}