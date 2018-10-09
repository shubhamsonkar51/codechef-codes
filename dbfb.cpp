#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define mod 1000000007

int main(){
	lli fib[100010];
	fib[0]=0;
	fib[1]=1;
	fib[2]=1;
	for(int i=3;i<100010;i++){
		fib[i]=(fib[i-1]%mod+fib[i-2]%mod)%mod;
	}
	lli t;
	cin>>t;
	while(t--){
		lli m,n;
		cin>>m>>n;
		lli a[m],b[m];
		lli as=0,bs=0;
		for(int i=0;i<m;i++){
			cin>>a[i];
			as=(as%mod+a[i]%mod)%mod;
		}
		for(int i=0;i<m;i++){
			cin>>b[i];
			bs=(bs%mod+b[i]%mod)%mod;
		}
		if(n==1)
			cout<<((as%mod)*(m%mod))%mod<<endl;
		else if(n==2)
			cout<<((bs%mod)*(m%mod))%mod<<endl;
		else{
			lli mpa=(m%mod*fib[n-2]%mod)%mod;
			lli mpb=(m%mod*fib[n-1]%mod)%mod;
			lli ans=(((mpa%mod*as%mod)%mod)+((mpb%mod*bs%mod)%mod))%mod;
			cout<<ans<<endl;
		}
	}
}  
