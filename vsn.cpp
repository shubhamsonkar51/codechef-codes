#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define lli long long int
#define ERROR 0.0000001
#define dou long double
using namespace std;
dou px,py,pz,qx,qy,qz,dx,dy,dz,cx,cy,cz,r;
dou cross(dou t){
	double a=(qx+(dx*t)-px),b=(qy+(dy*t)-py),c=(qz+(dz*t)-pz),d=(cx-px),e=(cy-py),f=(cz-pz);
	//cout<<" a:"<<a<<" b:"<<b<<" c:"<<c<<" d:"<<d<<" e:"<<e<<" f:"<<f<<" cross:";
	double pp=(e*c)-(b*f),qq=(c*d)-(a*f),rr=(b*d)-(a*e);
	return sqrt((pp*pp+qq*qq+rr*rr));
}
dou distance(dou t){
	double a=(qx+(dx*t)-px),b=(qy+(dy*t)-py),c=(qz+(dz*t)-pz);
	return sqrt((a*a+b*b+c*c));
}
dou func(dou t){
	dou ccc=cross(t), ddd=distance(t);
	//cout<<ccc<<"  "<<ddd<<"  ";
	return (ccc/ddd);
}

dou binary(dou r, dou a, dou b)
{
   dou low=a, high = b;
   dou mid;
   while(low<=high)
   {
      mid=(low/2)+(high)/2;
      dou dd=func(mid);
      //cout<<mid<<"    "<<dd<<endl;
      if(abs(dd-r)==0){
      	//printf("%.6f \n",mid);
      	//cout<<endl;
      	break;
	  }  
	  else if(dd>r){
	  	high=mid;
	  }
      else{
      	//printf("%.6f rrr \n",mid);
      	//cout<<endl;
      	low=mid;
	  }
   }
   return mid;
}

int main(){
	lli t;
	cin>>t;
	cin>>px>>py>>pz>>qx>>qy>>qz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
	while(t--){
		//cin>>px>>py>>pz>>qx>>qy>>qz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
		//rintf("%f \n",binary(r,0,1000000002));
		cout<<binary(r,0,1000000002)<<endl;
	}
}  
