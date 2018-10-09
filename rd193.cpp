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
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli arr[n];
		for(lli i=0;i<n;i++){
			cin>>arr[i];
		}
		bool ans=false;
		sort(arr,arr+n);
		lli g=arr[0];
		for(lli i=0;i<n;i++){	
			g=gcd(arr[i],g);
			if(g==1){
				ans=true;
				break;
			}
		}
		if(ans)
			cout<<"0"<<endl;
		else
			cout<<"-1"<<endl;
	}
}  
