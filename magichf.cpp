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
		lli n,x,s;
		cin>>n>>x>>s;
		while(s--){
			int a,b;
			cin>>a>>b;
			if(a==x||b==x){
				if(a==x)
					x=b;
				else
					x=a;
			}
		}
		cout<<x<<endl;
	}
}  
