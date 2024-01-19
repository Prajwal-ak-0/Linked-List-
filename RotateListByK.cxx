//Rotate a Linked List
// Input:
// N = 8
// value[] = {1, 2, 3, 4, 5, 6, 7, 8}
// k = 4
// Output: 5 6 7 8 1 2 3 4

Node *rotate(Node *head, int k)
{
    int i = 1;
    Node *temp = head;
    Node *tail = head;
    while (i < k)
    {
        i++;
        temp = temp->next;
    }

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
}