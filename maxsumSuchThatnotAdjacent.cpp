#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define M 100000000000

vector<int> func(lli arr[], lli n){
	lli incl=arr[0], excl=0, en;
	vector <int> iv; vector <int> ev; vector <int> tmp;
	iv.push_back(0);
	for(int i=1;i<n;i++){
		if(incl>excl){
			en=incl; tmp.clear(); tmp=iv;
		}
		else{
			en=excl; tmp.clear(); tmp=ev;
		}
		incl=excl+arr[i]; iv.clear(); ev.push_back(i); iv=ev;
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
		lli arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		vector <int> c;
		c=func(arr,n);
		for(int i=0;i<c.size();i++)
			cout<<arr[c[i]]<<" ";
		cout<<endl;
	}
}   
