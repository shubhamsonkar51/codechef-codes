#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int main(){
	bool prime[MAXN];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=MAXN; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=MAXN; i += p)
                prime[i] = false;
        }
    }
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli arr[n],c=0,cc=0;
		for(lli i=0;i<n;i++){
			cin>>arr[i];
			if(prime[arr[i]]&&arr[i]!=cc){
				c++;
				cc=arr[i];
			}
		}
		if(c>=2)
			cout<<"0";
		else if(c==1){
			bool ans=false;
			for(lli i=0;i<n;i++){
				if(gcd(arr[i],cc)==1){
					ans=true;
					break;
				}
			}
			if(ans)
				cout<<"0";
			else
				cout<<"-1";
		}
		else{
			bool ans=false;
			for(lli i=0;i<n;i++){
				if(gcd(arr[i],arr[0])==1){
					ans=true;
					break;
				}
			}
			if(ans)
				cout<<"0";
			else
				cout<<"-1";	
		}
	}
}  
