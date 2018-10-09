#include <iostream>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
int minVal(int x, int y) { return (x&y); }
int getMid(int s, int e) {  return s + (e -s)/2;  }
bool isSq(int a){
	int aa=(int)sqrt(a);
	if(aa*aa==a)
		return true;
	return false;
}






int getSumUtil(int *sqst, int ss, int se, int qs, int qe, int si) 
{ 
    if (qs <= ss && qe >= se) 
        return sqst[si]; 
    if (se < qs || ss > qe) 
        return 0; 
    int mid = getMid(ss, se); 
    return getSumUtil(sqst, ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(sqst, mid+1, se, qs, qe, 2*si+2); 
}
 
int getSum(int *sqst, int n, int qs, int qe) 
{ 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtil(sqst, 0, n-1, qs, qe, 0); 
}
 
int constructSTUtil1(int arr[], int ss, int se, int *sqst, int si, int *st)
{
    if (ss == se)
    {
        sqst[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    sqst[si] =  (constructSTUtil1(arr, ss, mid, sqst, si*2+1, st)+
                     constructSTUtil1(arr, mid+1, se, sqst, si*2+2, st));
    if(isSq(st[si]))
    	++sqst[si];
    return sqst[si];
}

int *constructST1(int arr[], int n, int *st)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
 
    int *sqst = new int[max_size]; 
    constructSTUtil1(arr, 0, n-1, sqst, 0, st);
 
    return sqst;
}






















int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
 
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
int RMQ(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
 
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
 
    int *st = new int[max_size]; 
    constructSTUtil(arr, 0, n-1, st, 0);
 
    return st;
}
 
 

int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int arr[n],sq[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(isSq(arr[i]))
				sq[i]=1;
			else
				sq[i]=0;
		}
		int *st = constructST(arr, n);
		int *sqst = constructST1(sq, n, st);
		for(int i=0;i<(2*(int)pow(2, (int)(ceil(log2(n)))) - 1);i++){
			cout<<st[i]<<" "<<i<<endl;
		}
		cout<<endl;
		for(int i=0;i<(2*(int)pow(2, (int)(ceil(log2(n)))) - 1);i++){
			cout<<sqst[i]<<" "<<i<<endl;
		}
		for(int i=0;i<q;i++){
			int l,r;
			cin>>l>>r;
			cout<<getSum(sqst, n, l-1, r-1)<<endl;
		}
	}
}  

