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
		lli n,a,b;
		cin>>n>>a>>b;
		double arr[10005]={};
		double s=0;
		for(int i=0;i<n;i++){
			lli aa;
			cin>>aa;
			arr[aa]++;
			s++;
		}
		double func=(arr[a]*arr[b])/(s*s);
		printf("%.10f\n",func);
		//cout<<(arr[a]*arr[b])/(s*s)<<endl;
	}
}  
