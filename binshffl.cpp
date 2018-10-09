#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define lli long long int
#define MAXN 50001
using namespace std;
lli lsb(lli n){
	lli ans=0;
	while(n%2==0){
		ans++;
		n/=2;
	}
	return ans;
}

lli btod(lli n)
{
    lli num = n;
    lli dec_value = 0; 
    lli base = 1;
    lli temp = num;
    while (temp)
    {
        lli last_digit = temp % 10;
        temp = temp/10;
         
        dec_value += last_digit*base;
         
        base = base*2;
    }
     
    return dec_value;
}


lli count(lli n)
{
  lli count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int main(){
	lli t;
	cin>>t;
	while(t--){
		lli a,b,ab,bb,a0,a1,b0,b1;
		cin>>a>>b;
		
		a=btod(a);
		b=btod(b);
		a1=count(a); ab=((lli)log2(a)+1); a0=ab-a1;
		b1=count(b); bb=((lli)log2(b)+1); b0=bb-b1;
		lli zerob=lsb(b), zeroa=lsb(a);
		if(a==b){
			cout<<"0"<<endl;
			continue;
		}
		if(b==1&&a>1||b==0){
			cout<<"-1"<<endl;
			continue;
		}
		
			if(a1==b1){
				if(ans==0)
					cout<<"2"<<endl;
				else
					cout<<ans<<endl;
			}
			else if(a1<b1){
					cout<<(b1-a1+ans)<<endl;
			}
			else{
				if(a1-b1+1==ans)
					cout<<"1"<<endl;
				else
					cout<<ans+1<<endl;
				
			}
		
	}
}  
