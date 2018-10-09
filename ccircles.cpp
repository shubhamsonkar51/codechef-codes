#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
int tree[10000000] = {0};
int lazy[10000000] = {0};
void updateRangeUtil(int si, int ss, int se, int us, 
                     int ue, int diff) 
{ 
    if (lazy[si] != 0) 
    {  
        tree[si] += (se-ss+1)*lazy[si]; 
        if (ss != se) 
        {
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        }
        lazy[si] = 0; 
    }  
    if (ss>se || ss>ue || se<us) 
        return ; 
    if (ss>=us && se<=ue) 
    { 
        tree[si] += (se-ss+1)*diff;
        if (ss != se) 
        { 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
    tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 
void updateRange(int n, int us, int ue, int diff) 
{ 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
int getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 
    if (lazy[si] != 0) 
    {  
        tree[si] += (se-ss+1)*lazy[si]; 
        if (ss != se) 
        { 
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    if (ss>se || ss>qe || se<qs) 
        return 0; 
    if (ss>=qs && se<=qe) 
        return tree[si]; 
    int mid = (ss + se)/2; 
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 
int getSum(int n, int qs, int qe) 
{ 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtil(0, n-1, qs, qe, 0); 
} 
void constructSTUtil(int arr[], int ss, int se, int si) 
{ 
    if (ss > se) 
        return ; 
    if (ss == se) 
    { 
        tree[si] = arr[ss]; 
        return; 
    } 
    int mid = (ss + se)/2; 
    constructSTUtil(arr, ss, mid, si*2+1); 
    constructSTUtil(arr, mid+1, se, si*2+2); 
  
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
} 
void constructST(int arr[], int n) 
{  
    constructSTUtil(arr, 0, n-1, 0); 
}


double dbp(int x1, int y1, int x2, int y2){
    return sqrt(pow(abs(x2-x1),2)+pow(abs(y2-y1),2));
}//distance btween points
double minD(int x1,int y1,int r1, int x2, int y2, int r2){
    double d=dbp(x1,y1,x2,y2);
    
    if(d<=abs(r1+r2)&&d>=abs(r1-r2))
        return 0;
    else if(d<abs(r1-r2))
        return r1>r2?(r1-(d+r2)):(r2-(d+r1));
    
    return (d-(r1+r2));
}
double maxD(int x1,int y1,int r1, int x2, int y2, int r2){
    double d=dbp(x1,y1,x2,y2);
    //cout<<d<<endl<<abs(r1-r2)<<" "<<2*r1<<" "<<2*r2<<endl;
    if(d<abs(r1-r2))
        return r1+r2+d;
    else if(d==abs(r1-r2))
        return r1>r2?2*r1:2*r2;
    else if(d==r1+r2)
        return 2*(r1+r2);
    else
        return d+r1+r2;
        
}

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int cx[n+1],cy[n+1],cr[n+1],qd[q+1];
        for(int i=1;i<=n;i++){
            cin>>cx[i]>>cy[i]>>cr[i];
        }
        for(int i=1;i<=q;i++){
            cin>>qd[i];
        }
        int nn=1000005;
        int arr[nn]={0};
        constructST(arr,nn);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int min=ceil(minD(cx[i],cy[i],cr[i],cx[j],cy[j],cr[j]));
                int max=floor(maxD(cx[i],cy[i],cr[i],cx[j],cy[j],cr[j]));
                updateRange(nn, min[i][j], max[i][j], 1);
            }
        }
        for(int i=1;i<=q;i++){
            cout<<getSum(nn,qd[i],qd[i])<<endl;
        }
    }
    return 0;
}  
