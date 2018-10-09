#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll int
#define MAXN 50001

ll bS(ll arr[], ll l, ll r, ll x) 
{ 
    while (l <= r) 
    { 
        ll m = l + (r-l)/2; 
        if (arr[m] == x) 
            return m; 
        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    }
    return l; 
} 




int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll arrn1[n],arrn2[n],arrm[m];
		for(ll i=0;i<n;i++){
			cin>>arrn1[i]>>arrn2[i];
		}
		//for(ll i=0;i<m;i++){
		//	cin>>arrm[i];
		//}
		sort(arrn1,arrn1+n);
		sort(arrn2,arrn2+n);
		ll arr[2][n+2];
		arr[0][0]=0;arr[1][0]=0;arr[0][n+1]=0;arr[1][n+1]=0;
		for(ll i=1;i<=n;i++){
			arr[0][i]=arrn1[i-1];
			arr[1][i]=arrn2[i-1];
		}
		for(ll i=0;i<m;i++){
			cin>>arrm[i];
			ll x=arrm[i];
			ll l=bS(arrn1,0,n-1,x);
			if(arr[0][l+1]==arrm[i])
				cout<<"0"<<endl;
			else{
				++l;
				if(l==n+1){
					if(arrm[i]>=arr[0][l-1]&&arrm[i]<arr[1][l-1])
						cout<<"0"<<endl;
					else
						cout<<"-1"<<endl;
				}
				else if(l==1){
					cout<<arr[0][1]-arrm[i]<<endl;
				}
				else{
					if(arrm[i]>=arr[0][l-1]&&arrm[i]<arr[1][l-1])
						cout<<"0"<<endl;
					else
						cout<<arr[0][l]-arrm[i]<<endl;
				}
			}
		}
	}
	return 0;
}  

