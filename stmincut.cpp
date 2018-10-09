#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli arr[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		}
		lli cost[n-1],min=1000000000000;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int l=arr[i][j], r=arr[j][i];
				if(l==0&&r==0)
					cost[i]+=2;
				else
					cost[i]+=abs(l-r);
			}
			if(cost[i]<min)
				min=cost[i];
		}
		cout<<min<<endl;
	}
}  
