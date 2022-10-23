#include <iostream>

using namespace std;

string slowo1,slowo2;
int dl1,dl2;
int lmax,lm;
int main()
{
    cin>>slowo1>>slowo2;
    dl1 = slowo1.size();
    dl2 = slowo2.size();
    lmax = 0;
    for(int i=0;i<dl1;i++){
        for(int j=0;j<dl2;j++){
            if(slowo1[i]==slowo2[j]){
                lm=1;
                while((slowo1[i+lm]==slowo2[j+lm]) && ((j+lm)<dl2) && ((i+lm)<dl1)) lm++;
                if(lm>lmax){
                    lmax = lm;
                }
            }
        }
    }

    cout<<lmax;

    return 0;
}