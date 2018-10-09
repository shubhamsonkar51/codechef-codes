#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
lli l;
lli r;
lli l1;
lli r1;
lli calc(lli arro[],lli s,lli e,lli p){
	lli mid=(s+e)/2;
	if(p==mid)
		return 0;
	else if(p>mid){
		if(arro[mid]>arro[p]){
			r++;
			return calc(arro,mid+1,e,p);
		}	
		else{
			r1++;
			return calc(arro,mid+1,e,p);
		}
	}
	else{
		if(arro[mid]<arro[p]){
			l++;
			return calc(arro,s,mid-1,p);	
		}
		else{
			l1++;
			return calc(arro,s,mid-1,p);
		}
	}
}

struct comp_pair_int{
    bool operator()(const pair<lli,lli> &a, const lli & b)
    {
        return (a.first < b);
    }
    bool operator()(const lli & a,const pair<lli,lli> &b)
    {
        return (a < b.first);
    }
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n,q;
		cin>>n>>q;
		lli arro[n];
		vector< pair<lli,lli> > arr;
		for(lli i=0;i<n;i++){
			cin>>arro[i];
			arr.push_back(make_pair(arro[i],i));
		}
		sort(arr.begin(), arr.end());
		while(q--){
			l=0;r=0;l1=0;r1=0;
			lli x;
			cin>>x;
			lli i=(lower_bound(arr.begin(),arr.end(),x,comp_pair_int())-arr.begin()); // index of x in sorted pair array
			lli p=arr[i].second;                                                      // index in original array
			lli pl=(n-1)-i, pr=i;													// possible left/right moves
			lli cc=calc(arro,0,n-1,p);												// calculates required left/right moves
			lli ans=0;
			if(l<=pl&&r<=pr)
				ans+=(l>=r?l:r);
			else
				ans=-1;
			cout<<ans<<endl;
		}
	}
}  
