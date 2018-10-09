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
	int t;
	cin>>t;
	while(t--){
		string mm,nn;
		cin>>mm>>nn;
		int q;
		cin>>q;
		//cout<<mm[0];
		int m=mm.length(), n=nn.length();
		unsigned char arr[n+1][m+1];
		arr[0][0]='0';
		for(int i=1;i<=m;i++)
			arr[0][i]=mm[i-1];
		for(int i=1;i<=n;i++)
			arr[i][0]=nn[i-1];
		if(arr[0][1]=='0'||arr[1][0]=='0')
			arr[1][1]='0';
		else
			arr[1][1]='1';
		for(int i=1;i<=m;i++){
			if(arr[0][i]=='0'||arr[1][i-1]=='1')
				arr[1][i]='0';
			else
				arr[1][i]='1';
		}
		for(int i=1;i<=n;i++){
			if(arr[i][0]=='0'||arr[i-1][1]=='1')
				arr[i][1]='0';
			else
				arr[i][1]='1';
		}
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				if(arr[i][j-1]=='1'||arr[i-1][j]=='1')
					arr[i][j]='0';
				else{
					arr[i][j]='1';
				}
			}
		}
		/*for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++)
				cout<<arr[i][j]<<"  ";
			cout<<endl;
		}*/
		string s;
		while(q--){
			
			int i,j;
			cin>>i>>j;
			if(arr[i][j]=='0')
				s+='1';
			else
				s+='0';
				
		}
		cout<<s<<endl;
		s.clear();
		
	}
	return 0;
}  
