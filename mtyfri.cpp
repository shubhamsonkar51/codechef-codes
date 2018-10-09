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
		double n,k;
		cin>>n>>k;
		if(n==1){
			lli a;
			cin>>a;
			cout<<"NO"<<endl;
		}
		else{
			int ml=ceil(n/2),tl=floor(n/2);
		lli m[ml],t[tl],ms=0,ts=0,mc=0,tc=0;
		for(int i=0;i<n;i++){
			if((i+1)%2==1){
				cin>>m[mc];
				ms+=m[mc];
				mc++;
			}
			else{
				cin>>t[tc];
				ts+=t[tc];
				tc++;
			}
		}
		sort(m, m+ml, greater<int>());
		sort(t,t+tl);
		for(int i=1,j=0;i<=k&&j<ml&&j<tl;i++){
			if(ts>ms)
				break;
			else{
				ms=ms-m[j]+t[j];
				ts=ts-t[j]+m[j];
				j++;
			}
		}
		if(ts>ms)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		}
		
	}
}  
