#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
bool isV(char c){
	if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
		return true;
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(n==1){
			cout<<"No"<<endl;
			continue;
		}
		else if(isV(s[0])&&isV(s[n-1])){
			cout<<"Yes"<<endl;
			continue;
		}
		else{
			int f=0;
			for(int i=0;i<n-1;i++){
				if(isV(s[i])&&isV(s[i+1])){
					f=1;
					break;
				}	
			}
			if(f){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
		s.clear();
	}
}  
