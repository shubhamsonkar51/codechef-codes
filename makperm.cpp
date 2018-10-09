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
		lli n;
		cin>>n;
		lli arr[n+1]={};
		int ans=0;
		for(int i=0;i<n;i++){
			int c;
			cin>>c;
			if(c>n)
				ans++;
			else
				arr[c]++;
		}
		for(int i=0;i<=n;i++)
			if(arr[i]>1)
				ans+=(arr[i]-1);
		cout<<ans<<endl;
	}
}  
