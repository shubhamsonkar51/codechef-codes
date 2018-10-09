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
		lli n,k;
		cin>>n>>k;
		string arr;
		cin>>arr;
		lli i=0,j=0,c=k,ans=0;
		for(i=0;i<k-1;i++){
			if(arr[i]!=arr[i+1])
				ans+=i+1;
		}
		cout<<ans<<endl;
		for(j=n-k-1;j<n-1;j++,c--){
			if(arr[j]!=arr[j+1])
				ans+=c;
		}
		cout<<ans<<endl;
		for(;i<n-k-1;i++){
			if(arr[i]!=arr[i+1])
				ans+=k;
		}
		cout<<ans<<endl;
	}
}  
