#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
int calcgcd(int a,int b){
	if(a==0)
		return b;
	else
		return calcgcd(b%a,a);
}
int prime(int a){
	int ret;
	while(a%2==0){
		ret=2;
		a/=2;
	}
	for(int i=3;i<=sqrt(a);i++){
		while(a%i==0){
			a/=i;
			ret=i;
		}
	}
	if(a>2)
		ret=a;
	return ret;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int gcd=arr[0];
		for(int i=0;i<n;i++){
			gcd=calcgcd(arr[i],gcd);
		}
		int pr=prime(gcd);
		if(pr<=k)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}  
