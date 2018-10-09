#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
//#define INT_MAX 100000000000000
lli SumOfDigit(lli n){
	lli sum=0;
	while(n!=0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
void print(lli arr[]){
	for(int i=0;i<=10;i++)
		cout<<arr[i]<<endl;
	cout<<endl<<endl;
}

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n,d;
		cin>>n>>d;
		lli arr[101];
		for(lli i=0;i<=100;i++){
			arr[i]=n+(d*i);
		}
		//print(arr);
		lli f[101];
		for(lli i=0;i<=100;i++){
			f[i]=i;
			while(arr[i]>=10){
				f[i]++;
				arr[i]=SumOfDigit(arr[i]);
			}
		}
		//print(arr);
		//print(f);
		lli minn=INT_MAX, minf=INT_MAX;
		for(lli i=0;i<=100;i++){
			if(arr[i]<=minn)
				minn=arr[i];
		}
		for(lli i=0;i<=100;i++){
			if(arr[i]==minn){
				if(f[i]<=minf)
					minf=f[i];
			}
		}
		cout<<minn<<" "<<minf<<endl;
	}
}  
