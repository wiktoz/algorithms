#include <iostream>

using namespace std;

int n,m;
int T[1000][1000];
long long K[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>T[i][j];
        }
    }

    K[0][0] = T[0][0];
    for(int i=1;i<m;i++) K[0][i] = K[0][i-1]+T[0][i];
    for(int i=1;i<n;i++) K[i][0] = K[i-1][0]+T[i][0];

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            K[i][j]=max(K[i-1][j],K[i][j-1])+T[i][j];
        }
    }

    cout<<K[n-1][m-1];

    return 0;
}