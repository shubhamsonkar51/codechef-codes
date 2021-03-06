#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define p 1000000007
lli arr[1005][1005];
void set(){
	for(int i=1;i<=1004;i++){
		arr[i][i]=2;
		arr[i][1]=2*i;
	}
	for(int i=3;i<=1004;i++){
		for(int j=2;j<i;j++){
			arr[i][j]=(arr[i-1][j]%p+arr[i-1][j-1]%p+arr[i-2][j-1]%p)%p;
		}
	}
}

int main(){
	lli t;
	cin>>t;
	set();
	while(t--){
		lli n,m;
		cin>>n>>m;
		if(m>n)
			cout<<"0"<<endl;
		else
			cout<<arr[n][m]<<endl;
			
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<arr[i][j]<<"\t";
			cout<<endl;
		}*/
	}
}  
