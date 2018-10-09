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
		lli n,k;
		cin>>n>>k;
		lli arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		lli max=abs(arr[0]);
		for(int i=0;i<n;i++){
			if(abs(arr[i])>max)
				max=abs(arr[i]);
		}
		cout<<"1"<<endl;
		cout<<max<<endl;
	}
}  
