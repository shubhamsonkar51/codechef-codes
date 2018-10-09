#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
int gcd(int a, int b) 
{ 
    if (a == b) 
        return a; 
  
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}  
int lc(int a, int b) 
{ 
    return (a*b)/gcd(a, b); 
} 

int main(){
    lli t;
    cin>>t;
    while(t--){
        lli h1,w1,h2,w2;
        cin>>h1>>w1;
        string a,b;
        cin>>a;
        cin>>h2>>w2;
        cin>>b;
        lli arr1[h1][w1], arr2[h2][w2];
        if(h1==1||h2==1||w1==1||w2==1){
        	for(int i=0;i<h1;i++){
            for(int j=0;j<w1;j++){
                if(a[((((i+1)-1)*w1)+(j+1))-1]=='1')
                    arr1[i][j]=1;
                else
                    arr1[i][j]=0;
                //cout<<arr1[i][j];
            }
            //cout<<endl;
        }
        for(int i=0;i<h2;i++){
            for(int j=0;j<w2;j++){
                if(b[((((i+1)-1)*w2)+(j+1))-1]=='1')
                    arr2[i][j]=1;
                else
                    arr2[i][j]=0;
                //cout<<arr2[i][j];
            }
            //cout<<endl;
        }
        int lcm1=lc(h1,h2);
        int lcm2=lc(w1,w2);
        lli uarr1[lcm1][lcm2], uarr2[lcm1][lcm2];
        int ww1=lcm2/(w1),hh1=lcm1/h1,ww2=lcm2/w2,hh2=lcm1/h2;
        for(int x=0;x<h1;x++)
        for(int i=0;i<w1;i++){
        	int e=arr1[x][i];
        	for(int j=hh1*x;j<hh1*(x+1);j++){
        		for(int k=ww1*i;k<ww1*(i+1);k++)
        			uarr1[j][k]=e;
			}
		}
		/*
		for(int i=0;i<lcm1;i++){
            for(int j=0;j<lcm2;j++){
                cout<<uarr1[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;*/
        for(int x=0;x<h2;x++)
        for(int i=0;i<w2;i++){
        	int e=arr2[x][i];
        	for(int j=hh2*x;j<hh2*(x+1);j++){
        		for(int k=ww2*i;k<ww2*(i+1);k++)
        			uarr2[j][k]=e;
			}
		}
		/*for(int i=0;i<lcm1;i++){
            for(int j=0;j<lcm2;j++){
                cout<<uarr2[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;*/
		int sum=0;
		for(int i=0;i<lcm1;i++){
            for(int j=0;j<lcm2;j++){
                if(uarr1[i][j]==uarr2[i][j])
                	sum++;
            }
        }
        cout<<sum<<endl;
		}
		else{
			for(int i=0;i<h1;i++){
            for(int j=0;j<w1;j++){
                if(a[((((i+1)-1)*w1)+(j+1))-1]=='1')
                    arr1[i][j]=1;
                else
                    arr1[i][j]=0;
                //cout<<arr1[i][j];
            }
            //cout<<endl;
        }
        for(int i=0;i<h2;i++){
            for(int j=0;j<w2;j++){
                if(b[((((i+1)-1)*w2)+(j+1))-1]=='1')
                    arr2[i][j]=1;
                else
                    arr2[i][j]=0;
                //cout<<arr2[i][j];
            }
            //cout<<endl;
        }
        
        
        int lcm1=lc(h1,h2);
        int lcm2=lc(w1,w2);
        //lli uarr1[lcm1][lcm2], uarr2[lcm1][lcm2];
        int la=(lcm1*lcm2)/(h1*w1);
        int lb=(lcm1*lcm2)/(h2*w2);
        string aa="",bb="";
        for(int i=0;i<a.length();i++){
        	for(int j=1;j<=la;j++){
        		aa+=a[i];
			}
		}
		for(int i=0;i<b.length();i++){
        	for(int j=1;j<=lb;j++){
        		bb+=b[i];
			}
		}
		int sum=0;
		for(int i=0;i<(lcm1*lcm2);i++)
			if(aa[i]==bb[i])
				sum++;
		/*//cout<<aa<<endl<<bb<<endl<<endl;
		for(int i=0;i<lcm1;i++){
            for(int j=0;j<lcm2;j++){
                if(aa[((((i+1)-1)*lcm2)+(j+1))-1]=='1')
                    uarr1[i][j]=1;
                else
                    uarr1[i][j]=0;
                //cout<<arr1[i][j];
            }
            //cout<<endl;
        }
		
		for(int i=0;i<lcm1;i++){
            for(int j=0;j<lcm2;j++){
                if(bb[((((i+1)-1)*lcm2)+(j+1))-1]=='1')
                    uarr2[i][j]=1;
                else
                    uarr2[i][j]=0;
                //cout<<arr2[i][j];
            }
            //cout<<endl;
        }
		
		
		
		
		
		
		
		/*
        int ww1=lcm2/(w1),hh1=lcm1/h1,ww2=lcm2/w2,hh2=lcm1/h2;
        for(int x=0;x<h1;x++)
        for(int i=0;i<w1;i++){
        	int e=arr1[x][i];
        	for(int j=hh1*x;j<hh1*(x+1);j++){
        		for(int k=ww1*i;k<ww1*(i+1);k++)
        			uarr1[j][k]=e;
			}
		}
		/*
		for(int i=0;i<lcm1;i++){
            for(int j=0;j<lcm2;j++){
                cout<<uarr1[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        for(int x=0;x<h2;x++)
        for(int i=0;i<w2;i++){
        	int e=arr2[x][i];
        	for(int j=hh2*x;j<hh2*(x+1);j++){
        		for(int k=ww2*i;k<ww2*(i+1);k++)
        			uarr2[j][k]=e;
			}
		}
		/*for(int i=0;i<lcm1;i++){
            for(int j=0;j<lcm2;j++){
                cout<<uarr2[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
		int sum=0;
		for(int i=0;i<lcm1;i++){
            for(int j=0;j<lcm2;j++){
                if(uarr1[i][j]==uarr2[i][j])
                	sum++;
            }
        }*/
        cout<<sum<<endl;
		
		}
        
		
    }
}  
