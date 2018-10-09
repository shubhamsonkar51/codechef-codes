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
    for(lli i=0;i<n;i++)
        a[i]=b[i];
    lli sum=0;
    vector< pair <lli,lli> > vect;
    for(lli i=0;i<n;i++){
        vect.push_back( make_pair(a[i],i+1) );
    }
    sort(vect.begin(), vect.end());
    for(lli i=1;i<=n;i++){
        lli aa=vect[i-1].second;
        a[aa-1]=smax(a,aa-1,max(1,aa-k)-1,min(n,aa+k)-1);
    }
    for(lli i=0;i<n;i++){
        sum+=a[i];
    }
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
void compress(lli ar[],lli s, lli n){
	lli arr[n];
	for(lli i=0;i<n;i++)
		arr[i]=ar[i];
    lli x[n];
    vector< pair <lli,lli> > vect;
    for(lli i=0;i<n;i++){
        vect.push_back( make_pair(arr[i],i) );
    }
    sort(vect.begin(), vect.end());
    vect.push_back( make_pair(-1,-1) );
    x[0]=1;
    for(lli i=1;i<n;i++){
        if(vect[i].first==vect[i-1].first)
        	x[i]=x[i-1];
        else
        	x[i]=x[i-1]+1;
    }
    for(lli i=0;i<n;i++){
        arr[vect[i].second]=x[i];
    }
    vect.clear();
    func(arr,s,n);
}
int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n,s;
        cin>>n>>s;
        lli arr[n];
        lli f=0;
        for(lli i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0)
            	f=1;
        }
        if(f)
        	for(lli i=0;i<n;i++)
        		arr[i]++;
        compress(arr,s,n);
        //compress(arr,s,n);
        return 0;
    }
}  

