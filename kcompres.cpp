#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
lli max(lli a, lli b){
	if(a>=b)
		return a;
		return b;
}
lli min(lli a, lli b){
	if(a<=b)
		return a;
	return b;
}
lli smax(lli a[], lli i, lli l, lli r){
	lli max=0;
	for(;l<=r;l++){
		if(a[i]==a[l]&&i!=l)
			return a[i];
		if(a[l]>max&&a[l]<a[i]){
			max=a[l];
		}
	}
	
	return max+1;
}
lli csum(lli b[], lli k, lli n){
	lli a[n];
	cout<<"k= "<<k<<endl;
	for(int i=0;i<n;i++)
		a[i]=b[i];
	lli sum=0;
	vector< pair <int,int> > vect;
	for(int i=0;i<n;i++){
		vect.push_back( make_pair(a[i],i+1) );
	}
	sort(vect.begin(), vect.end());
	for(int i=1;i<=n;i++){
		int aa=vect[i-1].second;
		a[aa-1]=smax(a,aa-1,max(1,aa-k)-1,min(n,aa+k)-1);
	}
	for(int i=0;i<n;i++){
		sum+=a[i];
		cout<<a[i]<<" ";
	}
	cout<<sum<<endl;
	//if(f)
	//return sum+n;
	return sum;
}

void func(lli arr[],lli s,lli n){
	lli lo = 0, hi = n, mid ;
    while(lo < hi) {
        mid = (lo + hi + 1) / 2 ;
        if(csum(arr,mid,n)<=s)
            lo = mid ;
        else
            hi = mid - 1 ;
    }
    if(csum(arr,mid,n)<=s)
        cout<<lo+1<<endl;
    else
        cout<<"0"<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		lli n,s;
		cin>>n>>s;
		lli arr[n];
		int f=0,g=1,c;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			c=arr[0];
			if(arr[i]==0)
				f=1;
			if(arr[i]!=c)
				g=0;
		}
		if(g){
			for(int i=0;i<n;i++)
				arr[i]=1;
		}
		else if(f)
			for(int i=0;i<n;i++){
				arr[i]++;
				cout<<arr[i]<<" ";
			}
				
		func(arr,s,n);
		//cout<<endl<<endl;
		
	}
}  
