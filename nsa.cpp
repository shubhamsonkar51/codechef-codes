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
		string s;
		cin>>s;
		lli n=s.length();
		lli ltor[n]={0};
		lli cltor[27]={0};
		for(int i=0;i<n;i++){
			cltor[s[i]-96]++;
			lli total=0;
			for(int x=1;x<(s[i]-96);x++){
				total+=cltor[x];
			}
			ltor[i]=total;
		}
		lli left[n][27], right[n][27];
		for(int i=0;i<27;i++)
			left[0][i]=0;
		for(int i=1;i<n;i++){
			for(int j=1;j<27;j++)
				left[i][j]=left[i-1][j];
			left[i][s[i-1]-96]++;
		}
		for(int i=0;i<27;i++)
			right[n-1][i]=0;
		for(int i=n-2;i>=0;i--){
			for(int j=1;j<27;j++)
				right[i][j]=right[i+1][j];
			right[i][s[i+1]-96]++;
		}
		int ci=-1;
		lli max=-1,maxi=-1;
		for(int i=0;i<n;i++){
			lli rtotal=0;
			if(ltor[i]>=s[i]-96){
				lli rtotal=0,lleft=s[i]-96;
				for(int j=s[i]-96-1;j>=1;j--)
					if(left[i][j]!=0)
						lleft=j;
				for(int j=lleft+1;j<27;j++)
					rtotal+=right[i][j];
				if(s[i]-96-lleft>rtotal)
					if(s[i]-96-lleft>max)
						{max=s[i]-96-lleft;maxi=i;}
			}
		}
		if(maxi!=-1)
			{
			s[maxi]=s[maxi]-max;
			//cout<<s[maxi]<<endl<<maxi<<endl;
			}
	//	else{
	//		cout<<"no"<<endl;
	//	}
		lli total=0;
		for(int i=0;i<27;i++)
			left[0][i]=0;
		for(int i=1;i<n;i++){
			for(int j=1;j<27;j++)
				left[i][j]=left[i-1][j];
			left[i][s[i-1]-96]++;
			for(int j=1;j<s[i]-96;j++)
				if(left[i][j]>0)
					total++;
		}
		if(maxi!=-1)
			cout<<max+total<<endl;
		else
			cout<<total<<endl;
	}
}  
