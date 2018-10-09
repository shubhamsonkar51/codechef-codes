#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MAXN 50001

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli arr[n], x=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			x=x^arr[i];
		}
		
		cout<<x<<endl;
	}
}  
