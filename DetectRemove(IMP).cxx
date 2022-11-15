#include<iostream>
#include<map>
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
/*
bool detect(node* head){
	if(head==NULL){
			return false;
	}
	map<node* , bool> visited;
	node* temp=head;
	while(temp!=NULL){
			if(visited[temp]==true){
				return true;
			}
			visited[temp]=false;
			temp=temp->next;
	}
	return false;
}
*/
			

node* floyd(node* head){
	if(head==NULL){
		return NULL;
	}
	node* slow=head;
	node* fast= head;
	while(slow!=NULL && fast!=	NULL){
			fast=fast->next;
			if(fast!=NULL){
				fast=fast->next;
			}
			slow=slow->next;
			if(slow==fast){
				return slow;
			}
	}
	return NULL;
}


	

node* getNode(node* head){
	if(head==NULL){
		return NULL;
	}
	node* intersection=floyd(head);
	
	if(intersection==NULL){
		return NULL;
	}
	
	node* slow=head;
	node* fast=intersection;
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next;
		}
		return slow;
	}
	
	node* removeLoop(node* head){
	if(head==NULL){
		return NULL;
	}
	node* temp=getNode(head);
	node* temp1=temp;
	while(temp1->next!=temp){
		temp1=temp1->next;
	}
	temp1->next=NULL;
	return head;
}	

int main(){
	node * node1=new node(10);
	node*	head=node1;
	node* tail=node1;
	insertAtTail(tail,12);
	insertAtHead(head,20);
	insertAtTail(tail,50);
	insertAtTail(tail,100);
	insertAtPosition(head,tail,4,1000);
	deletenode(head,4);
	cout<<head->data<<endl;
	cout<<tail->data<<endl;
	print(head);
	tail->next=head->next;
	
	
	if(floyd(head)!=NULL){
		cout<<"loop is present..."<<endl;
	}
	else{
		cout<<"loop is not present..."<<endl;
	}
	
	node* sol=getNode(head);
	cout<<"new node present at: "<<sol->data<<endl;
	
	node* sol1=removeLoop(head);
	print(head);

}

	
	
	