#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define lli long long int
#define ERROR 0.0000001
#define dou double
using namespace std;
dou px,py,pz,qx,qy,qz,dx,dy,dz,cx,cy,cz,r;
dou quad(dou a, dou b, dou c){
	dou d=b*b-(4*a*c);
	d=sqrt(d);
	dou a1=((b*-1)-d)/(2*a), a2=((b*-1)+d)/(2*a);
	if(a1>=0)
		return a1;
	else
		return a2;
}
dou func(){
	dou t;
	r=r*r;
	//PC
	dou x=cx-px,y=cy-py,z=cz-pz;
	//PU
	dou ax=qx-px, ay=qy-py, az= qz-pz;
	//LHS
	dou a1=r*(ax*ax+ay*ay+az*az), b1=r*(dx*dx+dy*dy+dz*dz), c1=2*r*(ax*dx+ay*dy+az*dz);
	//RHS
	dou a2=y*az-z*ay, b2=y*dz-z*dy, a3=x*az-z*ax, b3=x*dz-z*dx, a4=x*ay-y*ax, b4=x*dy-y*dx;
	dou c2=2*(a2*b2+a3*b3+a4*b4);
	a2=(a2*a2+a3*a3+a4*a4); b2=(b2*b2+b3*b3+b4*b4);
	//quadratic
	dou a=b1-b2, b=c1-c2, c=a1-a2;
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(a!=0)
		t=quad(a,b,c);
	else{
		t=(-1*c)/b;
		//cout<<" here"<<endl;
	}
	return t;
}

int main(){
	lli t;
	cin>>t;
	//cin>>px>>py>>pz>>qx>>qy>>qz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
	while(t--){
		cin>>px>>py>>pz>>qx>>qy>>qz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
		printf("%.10f\n",func());
		//cout<<func()<<endl;
	}
}  
