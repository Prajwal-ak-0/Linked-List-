// USING STACK   O(N) O(N)

bool isPalindrome(Node *head)
{
    stack<int> s;
    Node *temp = head;
    while (temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }

    while (head != NULL)
    {
        if (s.top() != head->data)
        {
            return 0;
        }
        else
        {
            head = head->next;
            s.pop();
        }
    }
    return 1;
}

// BRUTE FORCE OR NAIVE METHOD O(N) O(1)

Node *rev(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw; // Missing semicolon here
    }

    head = prev;
    return head;
}

bool isPalindrome(Node *head)
{
    int cnt = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (cnt % 2 == 0)
    {
        Node *dum = head;
        int mid = cnt / 2;
        int i = 0;
        while (i < mid)
        {
            dum = dum->next;
            i++;
        }

        Node *r = rev(dum);
        while (r != NULL)
        {
            if (r->data != head->data)
            {
                return 0;
            }
            else
            {
                r = r->next;
                head = head->next;
            }
        }
        return 1;
    }
    else
    {
        Node *dum = head;
        int mid = cnt / 2;
        int i = 0;
        while (i <= mid)
        {
            dum = dum->next;
            i++;
        }

        Node *r = rev(dum);
        while (r != NULL)
        {
            if (r->data != head->data)
            {
                return 0;
            }
            else
            {
                r = r->next;
                head = head->next;
            }
        }
        return 1;
    }
}