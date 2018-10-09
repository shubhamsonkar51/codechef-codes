#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
int l;
int r;
int func(int arro[],int s,int e,int p){
	int mid=(s+e)/2;
	if(p==mid)
		return 0;
	else if(p>mid){
		if(arro[mid]>arro[p]){
			r++;
			return func(arro,mid+1,e,p);
		}	
		else
			return func(arro,mid+1,e,p);
	}
	else{
		if(arro[mid]<arro[p]){
			l++;
			return func(arro,s,mid-1,p);	
		}
		else
			return func(arro,s,mid-1,p);
	}
}

struct comp_pair_int{
    bool operator()(const pair<int,int> &a, const int & b)
    {
        return (a.first < b);
    }
    bool operator()(const int & a,const pair<int,int> &b)
    {
        return (a < b.first);
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int arro[n];
		vector< pair<int,int> > arr;
		for(int i=0;i<n;i++){
			cin>>arro[i];
			arr.push_back(make_pair(arro[i],i));
		}
		sort(arr.begin(), arr.end());
		while(q--){
			l=0;
			r=0;
			int x;
			cin>>x;
			int mid=(n-1)/2;
			int i=(lower_bound(arr.begin(),arr.end(),x,comp_pair_int())-arr.begin());
			int p=arr[i].second;
			int pl=(n-1)-i, pr=i;
			int cc=func(arro,0,n-1,p);
			int ans=0;
			if(l<=pl&&r<=pr){
				if(l==r)
					ans+=l;
				else
					ans+=(l>r?l:r);
				cout<<ans<<endl;
			}
			else
				cout<<"-1"<<endl;
		}
		arr.clear();
	}
}  
