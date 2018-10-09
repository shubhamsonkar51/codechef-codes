#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define lli long long int
#define MAXN 50001
using namespace std;
lli lsb(lli n){
	lli ans=0;
	if(n==0)
		return 0;
	while(n%2==0){
		ans++;
		n/=2;
	}
	return ans;
}
lli count(lli n)
{
  lli count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli a,b,ab,bb,a0,a1,b0,b1;
		cin>>a>>b;
		if(a==b){
			cout<<"0"<<endl;
			continue;
		}
		if(b==1&&a>1||b==0){
			cout<<"-1"<<endl;
			continue;
		}
		a1=count(a); ab=((lli)log2(a)+1); a0=ab-a1;
		b1=count(b); bb=((lli)log2(b)+1); b0=bb-b1;
		lli zerob=lsb(b);
		
		if(a1==b1){
			if(zerob==0)
				cout<<"2"<<endl;
			else
				cout<<zerob<<endl;
		}
		else if(a1<b1){
			if(zerob==0)
				cout<<(b1-a1)<<endl;
			else
				cout<<(b1-a1+zerob)<<endl;
		}
		else{
			if(zerob==0)
				cout<<"2"<<endl;
			else{
				if(a1-b1>=zerob)
					cout<<"2"<<endl;
				else
					cout<<(zerob-(a1-b1))<<endl;
			}
		}
		
		
	}
}  
