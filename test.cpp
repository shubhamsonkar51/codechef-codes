#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define p 1000000007
lli comb[1005][1005];//main to store combination of k<=1000
lli arr[1005][1005];//to store further combination values 
lli arr2[1020][1020];//check
void set(){
	for(int i=1;i<=1004;i++){
		comb[i][i]=2;
		comb[i][1]=2*i;
		arr[i][1]=1;
		arr[i][i]=1;
	}
	for(int i=3;i<=1004;i++){
		for(int j=2;j<i;j++){
			comb[i][j]=(comb[i-1][j]%p+comb[i-1][j-1]%p+comb[i-2][j-1]%p)%p;
			arr[i][j]=(arr[i-1][j]%p+arr[i-1][j-1]%p+arr[i-2][j-1]%p)%p;
		}
	}
}
void set0(){
	for(int i=0;i<=1004;i++){
		for(int j=0;j<=1004;j++){
			comb[i][j]=0;
			arr[i][j]=0;
			//arr2[i][j]=0;
		}
	}
}
/*void init(){
	for(int i=1;i<=1004;i++){
		arr[i][1]=1;
		arr[i][i]=1;
	}
	for(int i=3;i<=1004;i++){
		for(int j=2;j<i;j++){
			arr[i][j]=(arr[i-1][j]%p+arr[i-1][j-1]%p+arr[i-2][j-1]%p)%p;
			//arr[i][j]=arr[i-1][j]+arr[i-1][j-1]+arr[i-2][j-1];
		}
	}
}*/
void rec(int i,int j){
	if(i<=1000)
		return;
	//arr[i][j]++;
	arr2[i-1][j]++;
	arr2[i-1][j-1]++;
	arr2[i-2][j-1]++;
	rec(i-1,j);
	rec(i-1,j-1);
	rec(i-2,j-1);
}
int main(){
	set0();
	set();
	cout<<arr[1000][500]<<endl;
	int t=0;
	cin>>t;
	while(t--){
		for(int i=0;i<=1019;i++){
    		for(int j=0;j<=1019;j++)
    		arr2[i][j]=0;
		}
		int i,j;
		cin>>i>>j;
		rec(i,j);
		cout<<"\t";
		for(int ii=1;ii<=10;ii++)
			cout<<ii<<"\t";
		cout<<endl;
		for(int ii=998;ii<=1010;ii++){
			cout<<ii<<"\t";
			for(int jj=1;jj<=10;jj++){
				cout<<arr2[ii][jj]<<"\t";
			}
			cout<<endl;
		}
		
	}
	
}  
