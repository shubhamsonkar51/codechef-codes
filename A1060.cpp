#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
lli sum(lli a){
	lli s=0;
	while(a!=0){
		s+=a%10;
		a/=10;
	}
	return s;
}

int main(){
	int t=1;
//	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		if(n<=18)
			cout<<n<<endl;
		else{
			lli a=n/2,b=n/2;
			if(n&1)
				b+=1;
			if(a%10==0){
				if(a>b){
					++a;
					--b;
				}
				else{
					--a;
					++b;
				}
			}
			else if(b%10==0){
				if(a>b){
					++a;
					--b;
				}
				else{
					--a;
					++b;
				}
			}
			cout<<a<<" "<<b<<endl;
			cout<<sum(a)+sum(b);
		}
	}
}  
