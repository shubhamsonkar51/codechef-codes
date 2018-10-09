#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
lli f[2][10];
lli SumOfDigit(lli n){
	lli sum=0;
	while(n!=0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
struct node{
	lli data;
	lli len;
	struct node* left;
	struct node* right;
};
struct node* newNode(lli data,lli l) 
{ 
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data; 
  node->len = l;
  node->left = NULL; 
  node->right = NULL; 
  return (node); 
} 
void make(lli d, lli l,struct node *head){
	if(l<=15){
		if((head->data)<10){
			if(f[0][head->data]){
				f[1][head->data]=min(f[1][head->data],l);
			}
			else{
				f[0][head->data]=1;
				f[1][head->data]=l;
			}
			head->right=newNode(head->data+d,l+1);
			make(d,l+1,head->right);	
		}
		else{
			head->left=newNode(SumOfDigit(head->data),l+1);
			head->right=newNode(head->data+d,l+1);
			make(d,l+1,head->left);
			make(d,l+1,head->right);
		}	
	}
}
int main(){
	lli t;
	cin>>t;
	while(t--){
		for(int i=0;i<10;i++){
            f[0][i]=0; 
            f[1][i]=0;
        }
		lli n,d;
		cin>>n>>d;
		struct node* root=newNode(n,0);
		struct node* temp=root;
		make(d,0,root);
		for(int i=0;i<10;i++){
			if(f[0][i]){
				cout<<i<<" "<<f[1][i]<<endl;
				break;
			}
		}
	}
}  
