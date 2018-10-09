#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int f[26];
		for(int i=0;i<26;i++)
			f[i]=0;
		for(int i=0;i<str.length();i++)
			f[str[i]-97]++;
		sort(f,f+26);
		int c=0;
		for(int i=0;i<26;i++)
			if(f[i]!=0)
				c++;
		if(c>=3){
			int d=1,i;
		for(i=25;i>=2;i--){
			if(f[i-2]!=0)
				if(f[i]!=f[i-1]+f[i-2]){
					d=0;
					break;
				}
			else
				break;
		}
		if(!d)
			cout<<"Not"<<endl;
		else
			cout<<"Dynamic"<<endl;
		}
		else
			cout<<"Dynamic"<<endl;
		
	}
}  
