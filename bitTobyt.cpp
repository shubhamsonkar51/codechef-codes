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
		lli n,k,l;
		cin>>n;
		k=n%26;
		l=n/26;
		if(k==0)
			cout<<0<<" "<<0<<" "<<pow(2,l-1)<<endl;
		else if(k>0&&k<=2)
			cout<<pow(2,l)<<" "<<0<<" "<<0<<endl;
		else if(k>2&&k<=10)
			cout<<0<<" "<<pow(2,l)<<" "<<0<<endl;
		else
			cout<<0<<" "<<0<<" "<<pow(2,l)<<endl;
	}
}  
