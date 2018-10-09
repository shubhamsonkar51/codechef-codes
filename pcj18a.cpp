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
		lli n,x,f=0;
		cin>>n>>x;
		lli arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]>=x)
				f=1;
		}
		if(f)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}  
