#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x,y;
    int zapytania;
    int a,b,c,d,wynik;
    cin>>y>>x;


      int t[x][y];

    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>t[j][i];
        }
    }

      int sum_pref[x+1][y+1];

      for(int a=0;a<=x;++a)

      sum_pref[a][0] = 0;

      for(int b=0;b<=y;++b)

       sum_pref[0][b] = 0;


     for(int a=0;a<x;++a){

       for(int b=0;b<y;++b){

         sum_pref[a+1][b+1] = sum_pref[a][b+1] + sum_pref[a+1][b] - sum_pref[a][b] + t[a][b];
         }
    }

    cin>>zapytania;
     for(int i=0; i<zapytania; ++i) {

       cin>>a>>b>>c>>d;

       wynik = sum_pref[d][c] - sum_pref[d][a-1] - sum_pref[b-1][c] + sum_pref[b-1][a-1]; // obliczamy wynik

       cout << wynik << "\n";

     }
     return 0;
}