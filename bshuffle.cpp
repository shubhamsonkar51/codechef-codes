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
	int arr[500][500];
	for(int i=0;i<500;i++){
		for(int j=0;j<500;j++)
			arr[i][j]=0;
	}
	//cout<<"fuck1";
	arr[1][1]=1;
	arr[2][1]=1;
	arr[2][2]=2;
	int l=0;
	//cout<<"fuck2";
	for(int i=3;i<=500;i++){
			int darr[i+1]={};
			darr[i]=arr[i-1][i-1];  //last
			darr[i-1]=i;			//second last
			for(int x=1;x<=i-2;x++)  //first l elements
				darr[x]=arr[i-1][x];
				
				
			if(i&1){
				int ndarr[i+1]={};
				ndarr[i]=darr[i]+1;  //last
				int x=1;
				for(x=1;x<1+l;x++){
					ndarr[x]=darr[x];
				}
				x=1+l;
				ndarr[x++]=darr[i];
				ndarr[x]=1;
				for(int j=i-1;j>i-1-l;j--)
					ndarr[j]=darr[j];
				
				for(x=1;x<=i;x++)
					arr[i][x]=ndarr[x];
				++l;
			}
			else{
				for(int x=1;x<=i;x++){
					arr[i][x]=darr[x];
				}
			}
			
	}
	int ar[500][500];
	for(int i=0;i<500;i++){
		for(int j=0;j<500;j++)
			ar[i][j]=0;
	}
	ar[1][1]=1;
	ar[2][1]=2;
	ar[2][2]=1;
	for(int i=3;i<=500;i++){
		ar[i][1]=i;
		for(int j=2;j<=i-1;j++)
			ar[i][j]=ar[i-1][j];
		ar[i][i]=i-1;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i!=n)
			cout<<arr[n][i]<<" ";
		else
			cout<<arr[n][i];
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		if(i!=n)
			cout<<ar[n][i]<<" ";
		else
			cout<<ar[n][i];
	}
	return 0;
}  
