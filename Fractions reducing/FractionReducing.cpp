#include <iostream>

using namespace std;

long long a,b,c,d;
long long n,l,m;

long long NWW(long long a, long long b)
{
    long long start_a=a;
    long long start_b=b;
	long long pom;

  	while(b!=0)
	{
    	pom = b;
    	b = a%b;
    	a = pom;
  	}

    return start_a/a*start_b;
}

long long NWD(long long a, long long b)
{
	long long pom;

  	while(b!=0)
	{
    	pom = b;
    	b = a%b;
    	a = pom;
  	}

    return a;
}

int main()
{
    cin>>n;

    for(int z=0;z<n;z++){
        cin>>a>>b>>c>>d;

        long long mnww=NWW(b,d);

        if(b==d) int nth=1;
        else if(mnww==b){
            c=(b/d)*c;
            d=b;
        }
        else if(mnww==d){
            a=(d/b)*a;
            b=d;
        }
        else{
            long long stat_b = b;
            a=a*d;
            b=b*d;
            c=c*stat_b;
            d=d*stat_b;
        }

        l=a+c;
        m=b;
        long long mnwd = NWD(l,m);
        l=l/mnwd;
        m=m/mnwd;

        cout<<l<<" "<<m<<endl;
    }

    return 0;
}