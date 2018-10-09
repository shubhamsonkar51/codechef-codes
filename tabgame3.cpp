#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
vector<vector<int> > func1(string mm, string nn, int m, int n,int a){
	int arr[n+1][m+1];
	arr[0][0]=1;
		for(int i=1;i<=m;i++)
			if(mm[i-1]=='0')
				arr[0][i]=1;
			else
				arr[0][i]=0;
		for(int i=1;i<=n;i++)
			if(nn[i-1]=='0')
				arr[i][0]=1;
			else
				arr[i][0]=0;
		if(arr[0][1]||arr[1][0])
			arr[1][1]=1;
		else
			arr[1][1]=0;
		
		for(int i=2;i<=m;i++){
			if(arr[0][i]||!arr[1][i-1])
				arr[1][i]=1;
			else
				arr[1][i]=0;
		}
		for(int i=2;i<=n;i++){
			if(arr[i][0]||!arr[i-1][1])
				arr[i][1]=1;
			else
				arr[i][1]=0;
		}
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				if(!arr[i][j-1]||!arr[i-1][j])
					arr[i][j]=1;
				else{
					arr[i][j]=0;
				}
			}
		}
		vector<vector<int> > ar;
		for(int i=0;i<=n;i++){
			vector<int> d;
			for(int j=0;j<=m;j++)
				d.push_back(arr[i][j]);
			ar.push_back(d);
			d.clear();
		}
		return ar;
		
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string mm,nn;
		cin>>mm>>nn;
		int q;
		cin>>q;
		int m=mm.length(), n=nn.length();
		if(m+n<=1001){
			vector<vector<int> > arr;
			arr=func1(mm,nn,m,n,0);
			string s;
			while(q--){
			
			int i,j;
			cin>>i>>j;
			if(arr[i][j]==1)
				s+='1';
			else
				s+='0';
				
		}
		//arr.clear();
		cout<<s<<endl;
		//s.clear();
		}
		else{
			vector<vector<int> > arru;
			vector<vector<int> > arrd;
			if(n>=3){
				arru=func1(mm,nn,m,3,1);
			}
			else{
				arru=func1(mm,nn,m,n,1);
			}
			
				if(m>=3)
					arrd=func1(mm,nn,3,n,2);
				else
					arrd=func1(mm,nn,m,n,2);
			
				
			string s;
			while(q--){
			
				int i,j;
				cin>>i>>j;
				if(i<=2||j<=2){
					if(i<=2)
						if(arru[i][j])
							s+='1';
						else
							s+='0';
					else
						if(arrd[i][j])
							s+='1';
						else
							s+='0';
				}
				else if(i==j){
					if(arru[2][2])
						s+='1';
					else
						s+='0';
				}
				else if(i>j){
                    int a=j-2;
                    int b=i-a;
                    if(arrd[b][2])
                        s+='1';
                    else
                        s+='0';
                }
                else{
                    int a=i-2;
                    int b=j-a;
                    if(arru[2][b])
                        s+='1';
                    else
                        s+='0';
                }
				
			}
			cout<<s<<endl;
			//s.clear();
			//arru.clear();
			//arrd.clear();
			
		}
		//mm.clear();
		//nn.clear();
			
	}
	return 0;
}  
