#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define k 1000000007
lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}


lli power(lli x, lli y, lli p)
    {
        lli res = 1;    
        x = x%p; 
     
        while (y>0)
        {
            if((y%2)==1)
                res =(res%p * x%p)%p;
            y = y/2; 
            x = (x%p * x%p)%p; 
        }
        return res%p;
    }


int main(){
	lli t;
	cin>>t;
	while(t--){
		lli a,b,n;
		cin>>a>>b>>n;
		//cout<<l<<"\n";
		if(a-b==0){
			lli l=((power(a,n,k)%k)+(power(b,n,k)%k))%k;
			cout<<l<<"\n";
		}
		else{
			lli p=abs(a-b);
			cout<<p<<"p ";
			lli l1=(power(a,n,p)%p);
			lli l2=(power(b,n,p)%p);
			cout<<l1<<"l1 "<<l2<<"l2 ";
			lli l=(l1+l2)%p;
			cout<<l<<"l";
			cout<<(gcd(l,(a-b))%k)<<"\n";
		}
			
	}
}  
