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
		lli arr[n],narr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			narr[i]=arr[i];
		}
		if(n%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		
		bool f=true;
		
		for(int i=0;i<n;i++){
			int o=(i+n/2)%n;
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
					f=false;
			}	
		}
		if(f){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
				cout<<narr[i]<<" ";
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}
}  
