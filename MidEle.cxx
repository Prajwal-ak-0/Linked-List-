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
int getlength(node* &head){
	int len=0;
	node* temp=head;
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}
	return len;
}
node* getmid(node* &head){
	int len=getlength(head);
	int pos=(len/2)+1;
	cout<<"position of mid element is "<<pos<<endl;
	int ans=len/2;
	int cnt=0;
	node* temp=head;
	while(cnt<ans){
		temp=temp->next;
		cnt++;
	}
	return temp;
}

/*

node* fun(node* &head){
	if(head==NULL || head->next ==NULL){
		return head;
	}
	if(head->next->next==NULL){
		return head->next;
	}
	node* fast=head->next;
	node* slow=head;
	while(fast!=NULL){
		fats=fast->next;
		if(fats!=NULL){
			fats=fast->next;
		}
		slow=slow->next;
	}
	return slow;
}
		

*/


int main(){
	node* node1=new node(10);
	node* head=node1;
	node*	ans=getmid(head);
	cout<<ans->data;
}