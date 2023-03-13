#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

stack <long long> v;
long long a,b,result;
int q,y;
string x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;

    for(int i=0;i<q;i++){
        cin>>x;
            if(x=="+"){
                    a = v.top();
                    v.pop();
                    b = v.top();
                    v.pop();
                    result = b+a;
                    v.push(result);
            }
            else if(x=="-"){
                    a = v.top();
                    v.pop();
                    b = v.top();
                    v.pop();
                    result = b-a;
                    v.push(result);
            }
            else if(x=="*"){
                    a = v.top();
                    v.pop();
                    b = v.top();
                    v.pop();
                    result = b*a;
                    v.push(result);
            }
            else if(x=="/"){
                    a = v.top();
                    v.pop();
                    b = v.top();
                    v.pop();
                    result = b/a;
                    v.push(result);
            }
            else{
                    stringstream temp(x);
                    temp >> y;
                    v.push(y);
            }
        }
    cout<<v.top();

    return 0;
}