#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n,i=0,ans=0;
		cin>>n;
		if(n%2==1)
			for(i=0;i<=n;i+=2){
				ans+=(i+1)*(i+1);
			}
		else
			for(i=1;i<=n;i+=2)
				ans+=(i+1)*(i+1);
		cout<<ans<<endl;
	}
}  
