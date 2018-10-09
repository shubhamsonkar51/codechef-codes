#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long long
#define MAXN 50001
long a[7654322]={};
void swap(long *x, long *y){
	long t=*x;
	*x=*y;
	*y=t;
}
long make(long arr[],long n){
	long d=0;
	for(long i=0;i<n;i++){
		d=d*10+arr[i];
	}
	return d;
}
void rec(long arr[],long n, long i){
	
	if(i>n){
		a[make(arr,n)]++;
		return;
	}
	else{
		for(long j=1;j<=n;j++){
			long ar[n];
			for(long x=0;x<n;x++)
				ar[x]=arr[x];
			swap(ar[i-1],ar[j-1]);
			rec(ar,n,i+1);
			//cout<<endl;
		}
	}
}
int main(){
	long arr[]={1,2,3,4,5,6,7};
	
	rec(arr,7,1);
	long min=100000000,min1=100000000, max=-1, max1=-1;
	for(long i=0;i<7654322;i++){
		if(a[i]){
			//cout<<i<<" "<<a[i]<<endl;
			if(a[i]<min){
				min=a[i];
				min1=i;
			}
			if(a[i]>max){
				max=a[i];
				max1=i;
			}
		}
	}
	//int x;
	//cin>>x;
	for(int i=0;i<7654322;i++){
		
		if(a[i]==min)
			cout<<i<<endl;
	}
	//cout<<"min: "<<min1<<" "<<min<<endl;
	//cout<<"max: "<<max1<<" "<<max<<endl;
}  
