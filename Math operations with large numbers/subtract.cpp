#include <iostream>

using namespace std;

string liczba1,liczba2,suma="",pom,temp,znak1,znak2,pom3,znak="";
int w,w1,w2,r=0,roznica,pom2;

string dodaj(string liczba1, string liczba2){
    for(int i=w-1;i>0;i--){
        pom = suma;
        suma = to_string((int(liczba1[i] - '0') + int(liczba2[i] - '0') + r)%10);
        suma = suma+pom;

        r = (int((liczba1[i] - '0')) + int((liczba2[i] - '0')) + r)/10;
    }

        pom = to_string(int(liczba1[0] - '0') + int(liczba2[0] - '0') + r);
        if(pom!="0") suma = pom + suma;
    return suma;
}

int ktoraWieksza(string liczba1, string liczba2,int dl){
    int zwroc=0;
    for(int i=0;i<dl;i++){
        if(liczba1[i]>liczba2[i]){
            zwroc = 1;
            break;
        }else if(liczba1[i]<liczba2[i]){
            zwroc = 2;
            break;
        }
    }

    return zwroc;
}

string odejmij(string liczba1, string liczba2){
    for(int i=w-1;i>=0;i--){
        pom = suma;

        if(liczba1[i]>=liczba2[i]){
            suma = to_string(int(liczba1[i] - '0') - int(liczba2[i] - '0'));
        }else{
            int c = i-1;
            if(liczba1[c]!=0){
                liczba1[c]--;
            }

            pom2 = int(liczba1[i] - '0') +10;
            suma = to_string(pom2 - (int(liczba2[i] - '0')));
        }
        suma = suma+pom;
    }
    int i=0;
    int w = suma.size();
    string pom4;
    while(suma[i]=='0') i++;
    for(int a=i;a<=w-i+1;a++) pom4 = pom4+suma[a];
    suma = pom4;
    return suma;
}

int main()
{
    cin>>liczba1>>liczba2;

    w1 = liczba1.size();
    w2 = liczba2.size();
    int i=0;
    pom3="";

    if(liczba1[0]=='-' && liczba2[0]!='-'){
        while(liczba1[i]=='-') i++;
        for(int a=i;a<=w1-i;a++) pom3 = pom3+liczba1[a];
        liczba1 = pom3;
        znak1='-';
        znak2='+';
    }else if(liczba2[0]=='-' && liczba1[0]!='-'){
        while(liczba2[i]=='-') i++;
        for(int a=i;a<=w2-i;a++) pom3 = pom3+liczba2[a];
        liczba2 = pom3;
        znak1='+';
        znak2='-';
    }else if(liczba2[0]=='-' && liczba1[0]=='-'){
        while(liczba1[i]=='-') i++;
        for(int a=i;a<=w1-i;a++) pom3 = pom3+liczba1[a];
        liczba1 = pom3;
        i=0;
        pom3="";
        while(liczba2[i]=='-') i++;
        for(int a=i;a<=w2-i;a++) pom3 = pom3+liczba2[a];
        liczba2 = pom3;
        znak1='-';
        znak2='-';
    }else{
        znak1="+";
        znak2="+";
    }

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

    if((znak1=="-") && (znak2=="-"))
        cout<<'-'<<dodaj(liczba1,liczba2);
    else if(znak1=="+" && znak2=="+")
        cout<<dodaj(liczba1,liczba2);
    else{
        int stmnt = ktoraWieksza(liczba1,liczba2,w);
        if(stmnt==0)
            cout<<"0";
        else if(stmnt==1){
            if(znak1=="-") znak="-";
            cout<<znak<<odejmij(liczba1,liczba2);
        }
        else if(stmnt==2){
            if(znak2=="-") znak="-";
            cout<<znak<<odejmij(liczba2,liczba1);
        }
    }

    return 0;
}