#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
lli cou(lli n)
{
  lli count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
lli bit(lli k){
	return (lli)log2(k)+1;
}

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n,k;
		cin>>n>>k;
		lli b=bit(k);
		if(n<=b){
			lli c=count(k);
				
		}
		else{
				for(int i=0;i<n-b;i++){
					cout<<"1 ";
				}
				for(int i=0;i<b;i++){
					cout<<pow(2,i);
					if(i!=b-1)
						cout<<" ";
				}
				cout<<endl;
		}
	}
}  
