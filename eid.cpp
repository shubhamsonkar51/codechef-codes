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
		lli arr[n];
		lli ans=10000000;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		for(int i=1;i<n;i++){
			if(abs(arr[i]-arr[i-1])<ans)
				ans=abs(arr[i]-arr[i-1]);
		}
		cout<<ans<<endl;
	}
}  
