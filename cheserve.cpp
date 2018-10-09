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
		lli p1,p2,k,l;
		cin>>p1>>p2>>k;
        l=(p1+p2)/k;
        if(l%2!=0)
        	cout<<"COOK"<<endl;
        else
        	cout<<"CHEF"<<endl;
	}
}  
