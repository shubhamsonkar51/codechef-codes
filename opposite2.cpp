#include <bits/stdc++.h>
#define lli long long int
using namespace std;


int main(){
	lli t;
	cin>>t;
	for(;t>0;t--){
		lli n;
		cin>>n;
		lli aarr[n],narr[n];
		for(ll i=0;i<n;i++){
			cin>>aarr[i];
			narr[i]=aarr[i];
		}
		int arr[n];
		for(int i=0,j=n-1;i<n;i++,j--){
			arr[j]=aarr[i];
		}
		if(n&1){
			cout<<"NO"<<endl;
			continue;
		}
		
		int f=1;;
		
		for(ll i=0;i<n;i++){
			ll o=(i+n/2)%n;
			if(arr[i]==-1&&(arr[o]==-1)){
				narr[i]=1;narr[o]=1;
			}
			else if(arr[i]==-1&&(arr[o]!=-1)){
				narr[i]=arr[o];
			}
			else if(arr[i]!=-1&&(arr[o]==-1)){
				narr[o]=arr[i];
			}
			else{
				if(arr[i]!=arr[o])
					f=0;
			}	
		}
		if(f){
			cout<<"YES"<<endl;
			for(ll i=0;i<n;i++)
				cout<<narr[i]<<" ";
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}  

