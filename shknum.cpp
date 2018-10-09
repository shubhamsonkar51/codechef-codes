#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001

bool present(lli c[], lli n){
	for(int i=0;i<35;i++){
		if(c[i]==n)
			return true;
	}
	return false;
}
lli closest(lli c[],lli n, lli j){
	lli n1,n2, i;
	for(i=0;i<35;i++){
		if(n>c[i]&&n<c[i+1]){
			n1=n-c[i]; n2=c[i+1]-n; break;
		}
	}
	if(i!=j)
		return n1<=n2?n1:n2;
	return n-c[i];
}

int main(){
	lli t;
	cin>>t;
	lli c[35];
	c[0]=1;
	for(int i=1;i<35;i++){
	   c[i]=2*c[i-1];
   }
	while(t--){
		lli n;
		cin>>n;
		if(present(c,n)){
			if(n==1)
				cout<<"2"<<endl;
			else if(n==2)
				cout<<"1"<<endl;
			else{
				cout<<"1"<<endl;
			}
		}
		else{
			lli n1,n2,i;
			for(i=0;i<35;i++)
				if(n>c[i]&&n<c[i+1]){
					n1=n-c[i]; n2=c[i+1]-n; break;
				}
			if(present(c,n1)){
				cout<<"0"<<endl; 
			}
			else{
				lli c1=closest(c,n1,i-1);
				lli c2=n2+1;
				cout<<(c1<=c2?c1:c2)<<endl;
			}
		}
		cout<<endl;
	}
}  
