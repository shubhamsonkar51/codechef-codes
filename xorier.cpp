#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001

lli comb(lli a){
	return (((a)*(a-1))/2);
}

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli arr[1000005]={};
		int one[1000005]={};
		int two[1000005]={};
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			arr[a]++;
			if(a%4==2||a%4==3)
				two[a]=1;
			if(a%2==1)
				one[a]=1;
		}
		
		lli e=0,o=0,sub=0;
		for(int i=1;i<1000005;i++){
			if(one[i]){
				o+=arr[i];
			}
			else{
				e+=arr[i];
			}
			if(arr[i]&&arr[i+2]&&two[i+2])
				sub+=arr[i]*arr[i+2];
		}
		cout<<comb(o)+comb(e)-sub<<endl;
	}
	return 0;
}  
