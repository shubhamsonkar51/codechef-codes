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
int def0[201][201][201];
int def1[201][201][201];
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


void def(int n, int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int d=0;
			for(int jj=j;jj<=m;jj++){
				if(arr[i][jj]!=d){
					def0[i][j][jj]=1+def0[i][j][jj-1];
					def1[i][j][jj]=def1[i][j][jj-1];
				}
					
				else{
					def1[i][j][jj]=1+def1[i][j][jj-1];
					def0[i][j][jj]=def0[i][j][jj-1];
				}
					
				invert(&d);
			}
			
		}
	}
}

int defected(int i11,int i2, int j11, int j2){
	int de0=0,de1=0;
	for(int i1=i11;i1<=i2;i1++){
		if(i1&1){
			de0+=def0[i1][j11][j2];
			de1+=def1[i1][j11][j2];
			//if(i2-i11==7)
			//	cout<<def1[i1][j11][j2]<<endl;
		}
		else{
			de0+=def1[i1][j11][j2];
			de1+=def0[i1][j11][j2];
			//if(i2-i11==7)
			//	cout<<def0[i1][j11][j2]<<endl;
		}
	}
	/*if(i2-i11==7)
	cout<<"de0:"<<de0<<"  de1:"<<de1<<endl<<min(abs(((i2-i11+1)*(i2-i11+1))-de0),abs(((i2-i11+1)*(i2-i11+1))-de1))<<endl;
	return min(abs(((i2-i11+1)*(i2-i11+1))-de0),abs(((i2-i11+1)*(i2-i11+1))-de1));*/
	return min(de0,de1);
}




main(){
	int t=1;
	//cin>>t;
	while(t--){
		for(int i=0;i<201;i++){
			for(int j=0;j<201;j++){
				for(int k=0;k<201;k++){
					def0[i][j][k]=0;
					def1[i][j][k]=0;
				}
				arr[i][j]=-1;
			}
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
		def(n,m);
		int side[n+1];
		for(int i=0;i<=n;i++){
			side[i]=10000000;
		}
		for(int x=1;x<=n;x++){
			int i1=1;
			for(int i2=i1+x-1;i1<=n-x+1;i1++,i2++){
				int j1=1;
				for(int j2=j1+x-1;j1<=m-x+1;j1++,j2++){
					side[x]=min(side[x],defected(i1,i2,j1,j2));
				}
			}
		}
		
		vector < pair<int,int> > ans;
		for(int i=1;i<=n;i++){
			ans.push_back(make_pair(side[i],i));
		}
		sort(ans.begin(),ans.end());
	/*	for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
		
	/*	cout<<endl<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<def1[1][i][j]<<" ";
			}
			cout<<endl;
		}*/
		
		int maxq=side[n];
		int finans[maxq];
		for(int i=0,j=0;i<maxq;i++){
			pair < int,int > a=findk(ans,i,j,ans.size()-1);
			finans[i]=a.second;
			j=a.second;
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
