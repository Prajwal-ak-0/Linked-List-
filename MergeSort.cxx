#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;

	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(node *&head, int d)
{
	node *temp = new node(d);
	temp->next = head;
	head = temp;
}

void insertAtTail(node *&tail, int d)
{
	node *temp = new node(d);
	tail->next = temp;
	tail = temp;
}

void insertAtPosition(node *head, node *tail, int position, int d)
{
	if (position == 1)
	{
		insertAtHead(head, d);
	}
	node *temp = head;
	int cnt = 1;

	while (cnt < position - 1)
	{
		temp = temp->next;
		cnt++;
	}

	if (temp->next == NULL)
	{
		insertAtTail(tail, d);
	}

	node *insert = new node(d);
	insert->next = temp->next;
	temp->next = insert;
}

void print(node *&head)
{
	if (head == NULL)
	{
		cout << "list is empty..." << endl;
	}

	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
	cout << endl;
}

void deletenode(node *&head, int position)
{
	if (position == 1)
	{
		node *temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		node *curr = head;
		node *prev = NULL;
		int cnt = 1;
		while (cnt < position)
		{
			prev = curr;
			curr = curr->next;
			cnt++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}

node *getMid(node *head)
{
	node *fast = head->next;
	node *slow = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node *merge(node *left, node *right)
{
	if (left == NULL)
	{
		return right;
	}
	if (right == NULL)
	{
		return left;
	}

	node *ans = new node(-1);
	node *temp = ans;

	while (left != NULL && right != NULL)
	{
		if (left->data < right->data)
		{
			temp->next = left;
			temp = left;
			left = left->next;
		}
		else
		{
			temp->next = right;
			temp = right;
			right = right->next;
		}
	}
	while (left != NULL)
	{
		temp->next = left;
		temp = left;
		left = left->next;
	}
	while (right != NULL)
	{
		temp->next = right;
		temp = right;
		right = right->next;
	}
	ans = ans->next;
	return ans;
}

node *mergeSort(node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	node *mid = getMid(head);

	node *left = head;
	node *right = mid->next;
	mid->next = NULL;

	left = mergeSort(left);
	right = mergeSort(right);

	node *result = merge(left, right);
	return result;
}

int main()
{
	node *node1 = new node(10);
	node *head = node1;
	node *tail = node1;
	insertAtTail(tail, 200);
	insertAtHead(head, 100);
	insertAtTail(tail, 50);
	insertAtTail(tail, 100);
	insertAtTail(tail, 30);
	insertAtPosition(head, tail, 4, 1000);
	deletenode(head, 4);
	print(head);
	node *sol = mergeSort(head);
	print(sol);
}
