#include <iostream>
 
using namespace std;
struct node{
    int data;
    struct node *next;
};
 
void addnode(struct node* head,int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    if (*head==NULL){
        *head=temp;
    }
    else{
        struct node* p=*head;
        while (p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
    return head;
}
 
int main(){
    int n,x;
    cin>>n;
    struct node* head=NULL;
    while (n--){
        cin>>x;
        addnode(*head,x);
    }
    node p=head;
    while (p->next!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}
