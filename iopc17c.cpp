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
		lli arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		if(n==1){
			cout<<"0"<<endl;
			continue;
		}
		int i;
		sort(arr,arr+n);
		for(i=n-1;i>0;i--){
			if(arr[i-1]!=arr[i]){
				cout<<arr[i-1]<<endl;
				break;
			}
		}
		if(i==0)
			cout<<"0"<<endl;
	}
}  
