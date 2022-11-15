#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
};
void print(node* &head){
	if(head==NULL){
		cout<<"Linked list is empty..."<<endl;
	}
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

void insertAtHead(node* &head, int d){
	node* temp=new node(d);
	temp->next=head;
	temp->prev=NULL;
	head=temp;
}

int getLength(node* &head){
	if(head==NULL){
		return 0;
	}
	int cnt=0;
	node* temp=head;
	while(temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}

void insertAtTail(node* &tail,int d){
	node* temp=new node(d);
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}

void insertAtPosition(node* &head,node* &tail, int position,int d){
	if(position==1){
		insertAtHead(head,d);
	}
	node* temp=head;
	int cnt=1;
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL){
		insertAtTail(tail,d);
	}
	else{
	
		node* insert=new node(d);
		insert->next=temp->next;
		temp->next=insert;
		insert->prev=temp;
	}
}

void deleteNode(node* &head,int position){
	if(position==1){
		node* temp=head;
		temp->prev=NULL;
		head=temp->next;
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
		curr->prev=NULL;
		delete curr;
	}
}

int main(){
	node* node1=new node(10);
	node* head=node1;
	node* tail=node1;
	print(head);
	insertAtHead(head,20);
	print(head);
	cout<<getLength(head)<<endl;
	insertAtTail(tail,30);
	print(head);
	insertAtPosition(head,tail,4,40);
	print(head);
	insertAtPosition(head,tail,2,100);
	print(head);
	deleteNode(head,2);
	print(head);
	
	
		
	
	
	
}
	