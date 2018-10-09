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
int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        if(k>n){
        	cout<<"0"<<endl;
        	continue;
		}
        lli fin=fact(2*n,k)%p;
        cout<<"fin:"<<fin<<endl;
        lli h=0,v=0,hv=0;
        for(lli i=2;k-i>=0;i+=2){
        	lli a=((n%p)*(fact((2*n-i),(k-i))%p))%p;
        	cout<<"a:"<<a<<endl;
        	if((i/2)&1)
        		h=((h%p)+(a%p))%p;
        	else
        		h=((h%p)-(a%p))%p;
		}
		cout<<"h:"<<h<<endl;
		for(lli i=2;k-i>=0;i++){
			lli a=(((2*(n-i+1))%p)*((fact((2*n-i),(k-i))%p)))%p;
			cout<<"a:"<<a<<endl;
			if((i-1)&1)
				v=((v%p)+(a%p))%p;
			else
				v=((v%p)-(a%p))%p;
		}
		cout<<"v:"<<v<<endl;
		lli nn=4*(n-1);
		for(int i=1,j=3;k-j>=0;i++,j+=3){
			lli a=((fact(nn,i)%p)*(fact((2*n-j),(k-j))%p))%p;
			cout<<"a:"<<a<<endl;
			if(i&1)
				hv=((hv%p)+(a%p))%p;
			else
				hv=((hv%p)-(a%p))%p;
		}
		
		
	//	hv=(((nn%p)*(fact((2*n-3),(k-3))))%p  -((fact(nn,2)%p)*(fact((2*n-6),(k-6))%p))%p    +((fact(nn,3)%p)*(fact((2*n-9),(k-9))%p))%p)%p;
		cout<<"hv:"<<hv<<endl;
		lli sub=((h%p)+(v%p)-(hv%p))%p;
		cout<<fin-sub<<endl;
    }
}  
