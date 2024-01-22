// Input: 
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers 
// so they appear first and 17,15,9 are odd 
// numbers that appear later.

Node* divide(int N, Node *head){
        Node* temp = head;
        Node* ans_head = new Node(-1);
        Node* ans_tail = ans_head;
        
        
        
        while(temp != NULL){
            if(temp->data % 2 == 0){
                if(ans_head->data == -1){
                    ans_head->data = temp->data;
                }else{
                    Node* Temp = new Node(temp->data);
                    ans_tail->next = Temp;
                    ans_tail = Temp;
                }
            }
            temp = temp->next;
        }
        
        Node* a = head;
        while(a != NULL){
            if(a->data % 2 != 0){
                if(ans_head->data == -1){
                    ans_head->data = a->data;
                }else{
                    Node* Temp = new Node(a->data);
                    ans_tail->next = Temp;
                    ans_tail = Temp;
                }
            }
            a = a->next;
        }
        
        return ans_head;
    }