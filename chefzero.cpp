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
	lli n,m,k;
	cin>>n>>m>>k;
	lli arr[n][m];
	lli narr[n][m];
	if(k==1){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
				if(k==1)
					narr[i][j]=1;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
				//narr[i][j]=1;
			}
		}
		int i=0,j=0;
		for( i=0;i<n/2;i++){
			for( j=0;j<m;j++){
				narr[i][j]=1;
			}
		}
		for( i=n/2;i<n;i++){
			for( j=0;j<m;j++){
				narr[i][j]=2;
			}
		}
		for( i=0;i<n;i++){
			for( j=0;j<m;j++){
				if(j!=m-1)
					cout<<narr[i][j]<<" ";
				else
					cout<<narr[i][j];
			}
			cout<<endl;
		}
	}
	
}  
