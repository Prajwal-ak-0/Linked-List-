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
	

node* solve(node* &first,node* second){
	node* curr1=first;
	node* curr2=second;
	node*	next1=curr1->next;
	node*	next2=curr2->next;
	
	if(first->next==NULL){
		first->next=second;
		return first;
	}
	
	while(next1!=NULL && curr2!=NULL){
		if( (curr1->data<=curr2->data) && (next1->data>=curr2->data)){
			curr1->next=curr2;
			next2=curr2->next;
			curr2->next=next1;
			
			curr1=curr2;
			curr2=next2;
			
			
		}
		else{
			curr1=next1;
			next1=next1->next;
			
			if(next1==NULL){
				curr1->next=curr2;
				return first;
			}
		}
	}
	return first;
}
	
	
	

node* merge(node* first,node* second){
	if(first==NULL){
		return second;
	}
	else if(second==NULL){
		return first;
	}
	
	if(first->data<=second->data){
			return solve(first,second);
	}
	else if(second->data<first->data){
			return solve(second,first);
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
	node* node2=new node(20);
	node* tail1=node2;
	node*head1=node2;
	insertAtTail(tail1,40);
	insertAtTail(tail1,60);
	print(head1);
	node* ans=merge(node1,node2);
	print(ans);
	
}
	
	
	