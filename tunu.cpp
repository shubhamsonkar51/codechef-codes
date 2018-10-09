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
		if(n){
			lli a,b;
			cin>>a>>b;
			cout<<a+b<<endl;
		}
		else{
			lli a,b;
			cin>>a>>b;
			cout<<a-b<<endl;
		}
	}
}  
