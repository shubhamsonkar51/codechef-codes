#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli comm(string a, string b){
	lli ans=0;
	for(int i=0;i<a.size()&&i<b.size();i++){
		if(a[i]==b[i])
			ans++;
		else
			break;
	}
	return ans;
}

int main(){
	lli t;
	cin>>t;
	string s[t];
	lli lex[t];
	map<lli,lli>m;
	//string str[t];
	for(int i=0;i<t;i++){
		cin>>s[i];
		lex[i]=s[i].compare("");
		m[lex[i]]=i;
		cout<<lex[i]<<" ";
	}
	cout<<endl;
	lli q;
	cin>>q;
	lli r[q];
	lli p[q];
	int i=0;
	while(q--){
		cin>>r[i];
		string x;
		cin>>x;
		p[i]=x.compare("");
		cout<<p[i]<<" ";
		++i;
	}
	
}  
