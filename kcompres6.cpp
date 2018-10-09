#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define long long long lli
#define MAXN 50001
int max(int a, int b){
    if(a>=b)
        return a;
        return b;
}
int min(int a, int b){
    if(a<=b)
        return a;
    return b;
}
int smax(int a[], int i, int l, int r){
    int max=0;
    for(;l<=r;l++){
        if(a[i]==a[l]&&i!=l)
            return a[i];
        if(a[l]>max&&a[l]<a[i]){
            max=a[l];
        }
    }
    return max+1;
}
int csum(int b[], int k, int n){
    int a[n];
    for(int i=0;i<n;i++)
        a[i]=b[i];
    int sum=0;
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
    }
    return sum;
}

void func(int arr[],int s,int n){
    int lo = 0, hi = n, mid ;
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
void compress(int ar[],int s, int n){
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=ar[i];
    int x[n];
    vector< pair <int,int> > vect;
    for(int i=0;i<n;i++){
        vect.push_back( make_pair(arr[i],i) );
    }
    sort(vect.begin(), vect.end());
    vect.push_back( make_pair(-1,-1) );
    x[0]=1;
    for(int i=1;i<n;i++){
        if(vect[i].first==vect[i-1].first)
        	x[i]=x[i-1];
        else
        	x[i]=x[i-1]+1;
    }
    for(int i=0;i<n;i++){
        arr[vect[i].second]=x[i];
    }
    vect.clear();
    func(arr,s,n);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        int arr[n];
        int f=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0)
            	f=1;
        }
        if(f)
        	for(int i=0;i<n;i++)
        		arr[i]++;
        compress(arr,s,n);
        //compress(arr,s,n);
    }
}  

