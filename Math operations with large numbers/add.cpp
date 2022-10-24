#include <iostream>

using namespace std;

string liczba1,liczba2,suma="",pom,temp;
int w,w1,w2,r=0,roznica;

int main()
{
    cin>>liczba1>>liczba2;

    w1 = liczba1.size();
    w2 = liczba2.size();

    if(w1>w2){
        roznica = w1-w2;
        for(int i=0;i<roznica;i++)
            temp = "0"+temp;
        liczba2 = temp + liczba2;
    }
    else if(w1<w2){
        roznica = w2-w1;
        for(int i=0;i<roznica;i++)
            temp = "0"+temp;
        liczba1 = temp + liczba1;
    }

    w = liczba1.size();

    for(int i=w-1;i>0;i--){
        pom = suma;
        suma = to_string((int(liczba1[i] - '0') + int(liczba2[i] - '0') + r)%10);
        suma = suma+pom;

        r = (int((liczba1[i] - '0')) + int((liczba2[i] - '0')) + r)/10;
    }

        pom = to_string(int(liczba1[0] - '0') + int(liczba2[0] - '0') + r);
        suma = pom + suma;

    cout<<suma;

    return 0;
}