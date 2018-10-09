#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long int
#define MAXN 50001
int arr[201][201];
pair<int,int> findk(vector < pair<int,int> > a, int key, int l, int r) {
    int lo = l, hi = r, mid ;
    while(lo < hi) {
        mid = (lo + hi + 1) / 2 ;
        if(a[mid].first == key)
            lo = mid ;
        else
            hi = mid - 1 ;
    }
    if(a[lo].first == key)
        return make_pair(a[lo].first,a[lo].second);
}


void invert(int *e){
	if(*e){
		*e=0;
	}
	else
		*e=1;
}
int defectedUtil(int i11,int i2, int j11, int j2, int c){
	//cout<<"fucked"<<endl;
	int d;
	int def=0;
	for(int i1=i11;i1<=i2;i1++){
		d=c;
		for(int j1=j11;j1<=j2;j1++){
			if(arr[i1][j1]!=d)
				def++;
			invert(&d);
		}
		invert(&c);
	}
	//if(i2-i11==6)
	//	cout<<"fuck"<<d<<" "<<i11<<" "<<i2<<" "<<j11<<" "<<j2<<endl;
	return def;
//	cout<<"again fucked"<<endl;
}
int defected(int i11,int i2, int j11, int j2){
	return min(defectedUtil(i11,i2,j11,j2,1),defectedUtil(i11,i2,j11,j2,0));
}

main(){
	int t=1;
	//cin>>t;
	while(t--){
		for(int i=0;i<201;i++){
			for(int j=0;j<201;j++){
				arr[i][j]=-1;
			}
			//cout<<endl;
		}
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=1;j<=s.size();j++){
				if(s[j-1]=='0')
					arr[i][j]=0;
				else
					arr[i][j]=1;
			}
		}
		int side[n+1];
		for(int i=0;i<=n;i++){
			side[i]=10000000;
		}
	//	cout<<"fuck1"<<endl;
		for(int x=1;x<=n;x++){
			int i1=1;
			for(int i2=i1+x-1;i1<=n-x+1;i1++,i2++){
				int j1=1;
				for(int j2=j1+x-1;j1<=m-x+1;j1++,j2++){
					side[x]=min(side[x],defected(i1,i2,j1,j2));
				}
			}
		}
	//	cout<<"fuck2"<<endl;
		vector < pair<int,int> > ans;
		for(int i=1;i<=n;i++){
			//cout<<i<<" "<<side[i]<<endl;
			ans.push_back(make_pair(side[i],i));
		}
		sort(ans.begin(),ans.end());
	/*	for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}*/
	//	cout<<"fucked"<<endl;
		int maxq=side[n];
	//	cout<<maxq<<endl;
		int finans[maxq];
		for(int i=0,j=0;i<maxq;i++){
			pair < int,int > a=findk(ans,i,j,ans.size()-1);
			finans[i]=a.second;
			j=a.second;
		//	cout<<i<<" "<<finans[i]<<endl;
		}
		int q;
		cin>>q;
		while(q--){
			int cq;
			cin>>cq;
			if(cq>=maxq)
				cout<<n<<endl;
			else{
				cout<<finans[cq]<<endl;
			}
		}
	}
}  
