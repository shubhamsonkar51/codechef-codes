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
		lli n,z1,z2;
		cin>>n>>z1>>z2;
		lli arrp[n],arrn[n];
		bool f=false,ff[2][n];
		for(int i=0;i<n;i++){
			cin>>arrp[i];
			arrn[i]=arrp[i]*-1;
			ff[0][i]=false;
			ff[1][i]=false;
			if(arrp[i]==z1||arrp[i]==z2||arrn[i]==z1||arrn[i]==z2)
				f=true;
		}
		if(f){
			cout<<"1"<<endl;
			continue;
		}
		else{
			for(int i=0;i<n;i++){
				int a=arrp[i],b=arrn[i];
				for(int j=0;j<n;j++){
					int a1=a+arrp[j],a2=a+arrn[j];
					if((a1==z1||a1==z2||a2==z1||a2==z2)){
						ff[0][i]=true;
					}
				}
				for(int j=0;j<n;j++){
					int b1=b+arrn[j],b2=b+arrp[j];
					if((b1==z1||b1==z2||b2==z1||b2==z2)){
						ff[1][i]=true;
					}
				}
			}
			f=true;
			for(int i=0;i<n;i++)
				if(!(ff[0][i]&&ff[1][i])){
					f=false;
				}
			if(f){
				cout<<"2"<<endl;
				continue;
			}
				
		}
		cout<<"0"<<endl;
	}
}  
