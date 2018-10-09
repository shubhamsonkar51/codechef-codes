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
vector<int> csum(lli a[], lli k, lli n){
	vector <int> x;
	for(int i=0;i<n;i++)
		x.push_back(0);
	//vector< pair <int,int> > vect;
	for(int i=1;i<=n;i++){
		for(int j=max(1,i-k);j<=min(n,i+k);j++){
			//if(i==n)
			//cout<<j<<" "<<min(n,i+k)<<endl;;
			if(a[j-1]<=a[i-1])
				x[i-1]++;
			//cout<<x[i-1]<<" ";
		}
		//vect.push_back( make_pair(x[i-1],i) );
		//sort(vect.begin(), vect.end());
		//cout<<x[i-1]a<<endl;
	}
/*	//cout<<endl<<endl;
	for(int i=1;i<=n;i++){
		int aa=vect[i-1].second;
		y[aa-1]=smax(x,aa-1,max(1,aa-k)-1,min(n,aa+k)-1);
		//cout<<y[aa-1]<<" ";
		sum+=y[aa-1];
	}
	for(int i=0;i<n;i++)
		cout<<y[i]<<" ";*/
	return x;
}
void prin(vector<int> x, vector<int> y, lli check[],lli s, lli q){
	int f=1;
	lli sum=0;
	for(int i=0;i<8;i++){
		sum+=check[i];
		if(x[i]!=y[i])
			f=0;
	}
	if(f&&sum<=s){
		for(int i=0;i<8;i++){
			cout<<check[i]<<" ";
		}
			
		cout<<sum<<"     "<<q<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		lli n,s;
		cin>>n>>s;
		lli arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		lli check[8];
		for(int q=2;q<=n;q++){
			vector <int> x=csum(arr,q,n);
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				for(int k=1;k<=8;k++){
					for(int l=1;l<=8;l++){
						for(int m=1;m<=8;m++){
							for(int nn=1;nn<=8;nn++){
								for(int o=1;o<=8;o++){
									for(int p=1;p<=8;p++){
										check[0]=i;check[1]=j;check[2]=k;check[3]=l;check[4]=m;check[5]=nn;check[6]=o;check[7]=p;
										vector <int> y=csum(check,q,8);
										prin(x,y,check,s,q);
									}
								}
							}
						}
					}
				}
			}
		}
		}
		//for(int i=0;i<=n;i++)
		//	cout<<csum(arr,i, n)<<endl;
		cout<<endl<<endl;
		
	}
}  
