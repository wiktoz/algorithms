#include <iostream>
#include <algorithm>

using namespace std;

int *bierki;
int n;
int o=0,g=2;
int max_elements=0;
bool czyMozliwyTrojkat(int d1, int d2, int naj);

int main()
{
    cin>>n;
    bierki = new int[n];
    for(int i=0;i<n;i++) cin>>bierki[i];

    sort(bierki, bierki+n);

    //gasienica
    while(g<n){
        if(o+2>g){
            g++;
            continue;
        }
        if(czyMozliwyTrojkat(bierki[o],bierki[o+1],bierki[g])){
            if((g-o+1)>max_elements) max_elements=g-o+1;
            g++;
            continue;
        }
        o++;
    }
    cout<<max_elements;

    return 0;
}

bool czyMozliwyTrojkat(int d1, int d2, int naj){
    if((d1+d2)>naj) return true;
    else return false;
}