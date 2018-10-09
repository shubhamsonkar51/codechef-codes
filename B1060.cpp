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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int arr[n];
	for(int i=0;i<s.length();i++){
		if(s[i]=='1')
			arr[i]=1;
		else if(s[i]=='2')
			arr[i]=2;
		else if(s[i]=='3')
			arr[i]=3;
		else if(s[i]=='4')
			arr[i]=4;
		else if(s[i]=='5')
			arr[i]=5;
		else if(s[i]=='6')
			arr[i]=6;
		else if(s[i]=='7')
			arr[i]=7;
		else if(s[i]=='8')
			arr[i]=8;
		else if(s[i]=='9')
			arr[i]=9;
		else
			arr[i]=0;
	}
	int narr[10]={};
	for(int i=0;i<n;i++){
		narr[arr[i]]++;
	}
	int sum=0;
	for(int i=0;i<10;i++){
		if(i!=8)
			sum+=narr[i];
	}
	if(sum/10>=narr[8])
		cout<<sum/10<<endl;
	else{
		int c=sum/10;
		int d=sum%10+(arr[8]-sum/10);
		cout<<c+d/10<<endl;
		
	}
	
}  
