#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define M 100000000000

//		PRINT
void print(lli arr[], lli ans[], lli n){
	if(n==1)
		cout<<arr[3];
	else
		for(int i=3;i<n+3;){
			if(ans[i]!=0)
				cout<<ans[i];
			else
				cout<<arr[i];
				
			if(i!=n+2)
				cout<<" ";
			++i;
		}
	cout<<endl;
}

//		CHECKS VALIDITY OF NUMBER
bool isvalid(lli arr[], int i){
	if(arr[i]<arr[i+1]&&arr[i]<arr[i-1])
		return true;
	else 
		return false;
}


//		RAMABAD
vector<int> func(vector <int> c, lli arr[]){
	lli incl=arr[c[0]], excl=0, en;
	vector <int> iv; vector <int> ev; vector <int> tmp;
	iv.push_back(c[0]);
	for(int i=1;i<c.size();i++){
		if(incl>excl){
			en=incl; tmp.clear(); tmp=iv;
		}
		else{
			en=excl; tmp.clear(); tmp=ev;
		}
		incl=excl+arr[c[i]]; iv.clear(); ev.push_back(c[i]); iv=ev;
		excl=en; ev.clear(); ev=tmp;
	}
	if(incl>excl){
		return iv;
	}
	return ev;
}


int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli arr[n+6];
		lli ans[n+6]={};
		vector <int> index;
		vector < vector < int > > con; 
		int s=3,e=n+3;
		arr[0]=M;arr[1]=M;arr[2]=M;arr[n+5]=M;arr[n+4]=M;arr[n+3]=M;
		ans[0]=M;ans[1]=M;ans[2]=M;ans[n+5]=M;ans[n+4]=M;ans[n+3]=M;
		for(int i=s;i<e;i++){
			cin>>arr[i];
			arr[i]=abs(arr[i]);
		}
		for(int i=s;i<e;i++){
			if(isvalid(arr,i))
				index.push_back(i);
		}
		index.push_back(n+5);
		//cout<<index[0]<<" "<<index[1]<<endl;
		if(index.size()==1){
			ans[index[0]]=arr[index[0]]*-1;
		}
		else{
			bool f=false;
			vector <int> v;
			for(int i=1;i<index.size();i++){
				if(index[i]-index[i-1]==2&&((arr[index[i]]+arr[index[i-1]])>=arr[index[i]-1])){
					v.push_back(index[i-1]);
					f=true;
				}
				else{
					if(f){
						v.push_back(index[i-1]);
						con.push_back(v);
						v.clear();
					}
					else{
						int c=index[i-1];
						//if((arr[c]+arr[c-2]<arr[c-1])||(arr[c]+arr[c+2]<arr[c+1]))
							ans[index[i-1]]=arr[c]*-1;
					}
						
					f=false;
				}
			}
		}
		index.clear();
		
		for(int i=0;i<con.size();i++){
			vector <int> d;
			d=func(con[i],arr);
			for(int j=0;j<d.size();j++)
				ans[d[j]]=arr[d[j]]*-1;
			d.clear();
		}
		print(arr,ans,n);
		con.clear();
	}
}   
