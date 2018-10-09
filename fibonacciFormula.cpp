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
	double a,b,n,m=5;
	double
	cin>>a>>b>>n;
	//double p=(1+sqrt(m))/2,q=(1-sqrt(m))/2;
	double fn=(((2*a+b*(1+sqrt(m)))*pow((1+sqrt(m)),n-1))-((2*a+b*(1-sqrt(m)))*pow((1-sqrt(m)),n-1)))/(pow(2,n)*sqrt(m));
	//double f2=(((2*a+b*(1+sqrt(m)))*pow((1+sqrt(m)),1))-((2*a+b*(1-sqrt(m)))*pow((1-sqrt(m)),1)))/(pow(2,2)*sqrt(m));
	cout<<fn<<endl;
	
}  
