#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
#define F first
#define S second
void func(vector< pair <int,int> > arr, int n){
	int ff=1;
	sort(arr.begin(),arr.end());
	int last=arr[n-1].S;
	n-=1;
	int c=arr[0].F;
		for(int i=0;i<n;i++){
			if(c!=arr[i].F){
					ff=0;
					break;
			}
		}
		if(ff){
			for(int i=0;i<n;i++){
					cout<<arr[i].S+1<<" ";
			}
			cout<<last+1<<endl;
			return;
		}

	int sum = 0;  
    for(int i = 0; i < n; i++) {
    	 sum += arr[i].F;
	}   
    bool dp[n+1][sum+1];
    int dp2[sum+1]={};
    for(int i = 0; i <= n; i++) 
        dp[i][0] = true;
    for(int i = 1; i <= sum; i++) 
        dp[0][i] = false;
    for(int i=1; i<=n; i++) { 
        for(int j=1; j<=sum; j++) {  
            dp[i][j] = dp[i-1][j];
            if (arr[i-1].F <= j) {
            	dp[i][j] |= dp[i-1][j-arr[i-1].F]; 
			}
			if(dp[i][j])
				if(dp2[j]==0)
					dp2[j]=i; 
        } 
    }
  
    vector < pair <int,int> > s1;
    vector < pair <int,int> > s2;
    int aa=0;
    for(int j=sum/2; j>=0; j--) {
        if (dp[n][j]) {
        	int s=j;
        	int c=n;
        	while(s!=0){
        		s1.push_back(arr[dp2[s]-1]);
        		while(c>dp2[s]){
					s2.push_back(arr[c-1]);
					c--;
				}
				c=dp2[s]-1;
        		s-=arr[dp2[s]-1].F;
			}
			while(c>=1){
				s2.push_back(arr[c-1]);
				c--;
			}	
            break; 
        }
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
   
    int sum1=0, sum2=0;
    vector< pair <int,int> > narr;
    int x=0,y=0;
    for(int i=0;i<n;i++){
    	if(sum1<=sum2){
    		narr.push_back(s1[x]);
    		sum1+=s1[x].F;
    		x++;
		}
		else{
			narr.push_back(s2[y]);
    		sum2+=s2[y].F;
    		y++;
		}
	}
	for(int i=0;i<narr.size();i++){
		cout<<narr[i].S+1<<" ";
	}
	cout<<last+1<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector < pair < int,int > > arr;
	
		for(int i=0;i<n;i++){
			int c;
			cin>>c;
			arr.push_back(make_pair(c,i));
		}
		if(n==1)
			cout<<arr[0].S+1<<endl;
		else if(n==2){
			int a=arr[0].S, b=arr[1].S;
			(arr[0].F>arr[1].F)?(cout<<a+1<<" "<<b+1):(cout<<b+1<<" "<<a+1);
			cout<<endl;
		}
		else{
			func(arr,n);	
		}
		
	}
}  
