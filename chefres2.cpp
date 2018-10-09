#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001

lli bS(lli arr[], lli l, lli r, lli x) 
{ 
    while (l <= r) 
    { 
        lli m = l + (r-l)/2; 
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
	lli t;
	cin>>t;
	while(t--){
		lli n,m;
		cin>>n>>m;
		lli arrn1[n],arrn2[n];
		for(lli i=0;i<n;i++){
			cin>>arrn1[i]>>arrn2[i];
		}
		sort(arrn1,arrn1+n);
		sort(arrn2,arrn2+n);
		for(lli i=0;i<m;i++){
			lli x;
			cin>>x;
			lli l=bS(arrn1,0,n-1,x);
			if(arrn1[l]==x)
				cout<<"0"<<endl;
			else{
				if(l==n){
					if(x>=arrn1[l-1]&&x<arrn2[l-1])
						cout<<"0"<<endl;
					else
						cout<<"-1"<<endl;
				}
				else if(l==1){
					cout<<arrn1[1]-x<<endl;
				}
				else{
					if(x>=arrn1[l-1]&&x<arrn2[l-1])
						cout<<"0"<<endl;
					else
						cout<<arrn1[l]-x<<endl;
				}
			}
		}
	}
	return 0;
}  

