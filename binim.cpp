#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n;
		string s;
		cin>>n>>s;
		vector < vector<int> > z;
		vector < vector<int> > o;
		for(int i=0;i<n;i++){
			string a;
			cin>>a;
			vector <int> oo;
			vector <int> zz;
			int l=0;
			while(l<a.size()){
				if(a[l]=='0')
					zz.push_back(l);
				else
					oo.push_back(l);
				++l;
			}
			if(zz.empty())
				zz.push_back(-1);
			if(oo.empty())
				oo.push_back(-1);
			z.push_back(zz);
			o.push_back(oo);
		}
		
	}
}  
