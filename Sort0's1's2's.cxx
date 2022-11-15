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

 void insertattail(node* &tail, node* temp){
 	tail->next=temp;
 	tail=temp;
 }

node* sort(node* head){
	node* zerohead=new node(-1);
	node* zerotail=zerohead;
	node* onehead=new node(-1);
	node* onetail=onehead;
	node* twohead=new node(-1);
	node* twotail=twohead;
	
	node* temp=head;
	
	while(temp!=NULL){
		int value=temp->data;
		if(value==0){
			insertattail(zerotail,temp);
		}
		else if(value==1){
			insertattail(onetail,temp);
		}
		else{
			insertattail(twotail,temp);
		}
	temp=temp->next;
	}
	
	if(onetail->next!=NULL){
		zerotail->next=onehead->next;
		onetail->next=twohead->next;
		twotail->next=NULL;
	}
	else{
		zerotail->next=twohead->next;
	}
	
	head=zerohead->next;
	
	delete zerohead;
	delete onehead;
	delete twohead;
	
	return head;
}
	


/*node* sort(node* &head){
	int zerocount=0;
	int onecount=0;
	int twocount=0;
	
	node* temp=head;
	
	while(temp!=NULL){
		int value=temp->data;
		if(value==0){
			zerocount++;
			
		}
		else if(value==1){
			onecount++;

		}
		else{
			twocount++;
		}
		temp=temp->next;
	}
	
	temp=head;
	
	while(temp!=NULL){
		if(zerocount!=0){
			temp->data=0;
			zerocount--;
		}
		else if(onecount!=0){
			temp->data=1;
			onecount--;
		}
		else{
			temp->data=2;
			twocount--;
		}
		temp=temp->next;
	}
	return head;
}
*/
	

int main(){
	node * node1=new node(0);
	node* head=node1;
	node* tail=node1;
	insertAtTail(tail,0);
	insertAtTail(tail,2);
	insertAtTail(tail,0);
	insertAtTail(tail,1);
	insertAtTail(tail,2);
	print(head);
	/*
	node* ans=sort(head);
	*/
	node* ans=sort(head);
	
	print(ans);
}
	
	
	