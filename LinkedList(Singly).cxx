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

void insertAtHead(node* &head,int d){
	node* temp=new node(d);
	temp->next=head;
	head=temp;
}

void insertAtTail(node* &tail,int d){
	node*	temp=new node(d);
	tail->next=temp;
	tail=temp;
}

void insertAtPosition(node* head,node* tail,int position,int d){
	if(position==1){
		insertAtHead(head,d);
	}
	node *temp=head;
	int cnt=1;
	
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	
	if(temp->next==NULL){
		insertAtTail(tail,d);
	}
	
	node* insert=new node(d);
	insert->next=temp->next;
	temp->next=insert;
}

void print(node* &head){
	if(head==NULL){
		cout<<"list is empty..."<<endl;
	}
	
	node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

void deletenode(node* &head,int position){
	if(position==1){
		node* temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
	}
	else{
		node* curr=head;
		node* prev=NULL;
		int cnt=1;
		while(cnt<position){
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}


int main(){
	node * node1=new node(10);
	node*	head=node1;
	node* tail=node1;
	insertAtTail(tail,20);
	insertAtHead(head,0);
	insertAtTail(tail,50);
	insertAtTail(tail,100);
	insertAtTail(tail,200);
	insertAtPosition(head,tail,4,1000);
	deletenode(head,4);
	print(head);
	
}
	
	
	