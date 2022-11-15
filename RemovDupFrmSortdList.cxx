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

node* reverse(node* head,int k){
		if(head==NULL || head->next==NULL){
			return head;
		}
		
		node* curr=head;
		node* prev=NULL;
		node* forward=NULL;
		int cnt=0;
		while(curr!=NULL && cnt<k){
			forward=curr->next;
			curr->next=prev;
			prev=curr;
			curr=forward;
		}
		if(forward!=NULL){
			head->next=reverse(forward,k);
		}
		return prev;
	}		
	
	node* duplicate(node* head){
		if(head==NULL ){
			return head;
 		}
		node* curr=head;
		while(curr!=NULL){
			if( (curr->next!=NULL) && (curr->data==curr->next->data) ) {
				node* temp1=curr->next->next;
				node* temp=curr->next;
				delete(temp);
				curr->next=temp1;
			}
			else{
				curr=curr->next;
			}
		}
		return head;
	}
		

int main(){
	node * node1=new node(20);
	node*	head=node1;
	node* tail=node1;
	insertAtTail(tail,30);
	insertAtHead(head,20);
	insertAtTail(tail,50);
	insertAtTail(tail,90);
	insertAtTail(tail,90);
	insertAtTail(tail,100);
	insertAtPosition(head,tail,4,1000);
	deletenode(head,4);
	print(head);
	node* sol=duplicate(head);
	print(head);
}
	
	
	