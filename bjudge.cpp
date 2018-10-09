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
	outer:
	while(t--){
		lli n,m;
		cin>>n>>m;
		lli a[n][m],b[n][m],d[n];
		bool d1=true,d0=true;
		bool b1=true,b0=true;
		//fill d
		for(lli i=0;i<n;i++){
			cin>>d[i];
			if(d[i]==0)
				d1=false;
			else
				d0=false;
		}
		//fill a
		for(lli i=0;i<n;i++){
			for(lli j=0;j<m;j++)
				cin>>a[i][j];
		}
		//fill b
		for(lli i=0;i<n;i++){
			for(lli j=0;j<m;j++){
				cin>>b[i][j];
				if(b[i][j]==1)
					b0=false;
				else
					b1=false;
			}
		}
		
		
		//fkhsfbjwfbsigbfhyjgbfhejbghgbsjgbsgbsjgsbjg
		if(d1){
			if(b0){
				cout<<"NO"<<endl;
				continue;
			}
			//func1(a,b,n,m);
			vector <lli> e;
			vector <lli> maxe;
			lli omax=-1;
			for(lli j=0;j<m;j++){
				bool f=true;
				lli max=-1;
				for(lli i=0;i<n;i++){
					if(b[i][j]==0)
						f=false;
					if(a[i][j]>max)
						max=a[i][j];
				}
				if(f){
					e.push_back(j);
					maxe.push_back(max);
					if(max>omax)
						omax=max;
				}	
			}
			if(e.empty()){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
				cout<<omax<<" "<<maxe.size()<<endl;
				for(lli j=0;j<e.size();j++)
					cout<<e[j]+1<<" ";
				cout<<endl;
			}
			continue;
		}
		if(d0){
			if(b0){
				cout<<"YES"<<endl;//<<"1 1"<<endl<<"1"<<endl;
				continue;
			} 
			bool f=false;
			lli minj=-1, omin=1000000000,ocount=1000000000;
			for(lli j=0;j<m;j++){
				lli count=0;
				lli min=1000000000;
				for(lli i=0;i<n;i++){
					if(b[i][j]==1){
						count++;
						if(a[i][j]<min)
							min=a[i][j];
					}
				}
				if(count<ocount&&min<omin&&min>1){
					omin=min;
					minj=j;
					ocount=count;
				}
				if(min=1000000000){
					cout<<"YES"<<endl<<"1 1"<<endl<<j+1<<endl;
					f=true;
					break;
				}
			}
			if(f)
				continue;
			if(minj==-1){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
				cout<<"1 1"<<endl<<minj+1<<endl;
			}
			continue;
		}
		
		
		
		
		vector <lli> e;
		vector <lli> maxe;
		vector <lli> mine;
		//sbfjsbgkbajgkdbgkmgbkgkrhjbdsjfgsyuygufsuge
		//fill e and maxt
		for(lli j=0;j<m;j++){
			bool f=true;
			lli max=-1, min=1000000000;
			for(lli i=0;i<n;i++){
				if(d[i]==1&&b[i][j]==0)
					f=false;
				if(d[i]==1&&a[i][j]>max)
					max=a[i][j];
				if(d[i]==0&&a[i][j]<min)
					min=a[i][j];
			}
			if(f&&min>max){
				e.push_back(j);
				maxe.push_back(max);
				mine.push_back(min);
			}	
		}
		
		//check whether atleast e[i];
		
		if(e.empty()){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			lli min=1000000000;
			for(lli j=0;j<mine.size();j++){
				if(mine[j]<min)
					min=mine[j];
			}
			vector <lli> newe;
			for(lli j=0;j<m;j++){
				if(min>maxe[j])
					newe.push_back(e[j]);
			}
			if(newe.empty())
				cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
				cout<<min-1<<" "<<newe.size()<<endl;
				for(lli j=0;j<newe.size();j++)
					cout<<newe[j]+1<<" ";
				cout<<endl;
			}
		}
	}
}  
