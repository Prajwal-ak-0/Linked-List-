#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		
		node(int data){
			this->data=data;
			this->next=NULL;
			
		}
};

node* reverse(node* &head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* curr=head;
	node* prev=NULL;
	node* forward=NULL;
	while(curr!=NULL){
		forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
	}
	return prev;
}
void print(node* &head){
	if(head==NULL){
		cout<<"emepty"<<endl;
	}
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" " ;
		temp=temp->next;
	}
}

/*recursive approach....

void reverse(node* &head, node* curr, node* prev){
	if(curr==NULL){
		head=prev;
		return;
	}
	node* forward=curr->next;
	reverse(head,forward,curr);
	curr->next=prev;
}
node* fun(node* &head){
		node* curr=head;
		node* prev=NULL;
		reverse(head,curr,prev);
		return head;
	}
		

*/
		
int main(){
	node* node1=new node(10);
	node* head=node1;
	node*	ans=reverse(head);
	print(head);
}