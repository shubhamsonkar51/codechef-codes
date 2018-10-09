#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define k 1000000007

int main(){
	lli q;
	cin>>q;
	while(q--){
		string t,b;
		cin>>t;
		cin>>b;
		if(((t[0]=='b'||b[0]=='b')&&(t[1]=='o'||b[1]=='o')&&(t[2]=='b'||b[2]=='b'))||((t[0]=='o'||b[0]=='o')&&(t[1]=='b'||b[1]=='b')&&(t[2]=='b'||b[2]=='b'))||((t[0]=='b'||b[0]=='b')&&(t[1]=='b'||b[1]=='b')&&(t[2]=='o'||b[2]=='o')))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}  
