#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define p 1000000007
lli fact(lli n, lli r){
    if(r<0)
        return 0;
    else if(r==0)
        return 1;
    else if(r==1)
        return n%p;
    else{
        lli arr[r];
        arr[0]=n;
        for(int i=1;i<r;i++)
            arr[i]=arr[i-1]-1;
        for(int i=r;i>=2;i--){
            for(int j=0;j<r;j++){
                if(arr[j]%i==0){
                    arr[j]=arr[j]/i;
                    break;
                }
            }
        }
        lli a=1;
        for(int i=0;i<r;i++){
            a=((a%p)*(arr[i]%p))%p;
        }
        return a%p;
    }
}
lli power(lli k){
	lli ret=1;
	if(k==0)
		return 1;
	for(int i=1;i<=k;i++){
		ret=((ret%p)*2)%p;
	}
	return ret%p;
}
lli fun(lli n, lli r){
	lli sum=0;
	for(int k=0;k<=min(n-r,r)+1;k++){
		sum=((sum%p)+((((fact(r-1,k-1)%p)*(fact(n-r,k)%p))%p)*(power(k)%p))%p)%p;
	}
	return sum%p;
}
int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n,m;
		cin>>n>>m;
		if(m>n)
			cout<<"0"<<endl;
		else
			cout<<fun(n+1,m)<<endl;
	}
}  
