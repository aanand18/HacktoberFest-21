#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int k)
    {
        data = k;
        next = NULL;
    }
};

void traverse(Node *head)
{
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *insertatbeg(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;

    temp->next = head;
    return temp;
}

Node *insertatend(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;
    return head;
}

Node *deletehead(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head->next;
    delete head;
    return temp;
}

Node *deleteend(Node *head)
{
    if (head == NULL)
        return NULL;

    if (!head->next)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = NULL;
    return curr;
}

Node *insertpos(Node *head, int x, int pos)
{
    Node *temp = new Node(x);
    if (x == 1)
    {
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
        return head;

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

int search(Node *head, int x)
{
    int pos = 0;
    Node *curr = head;

    while (curr != NULL)
    {
        pos++;
        if (curr->data == x)
            return pos;

        curr = curr->next;
    }

    return -1;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = insertatbeg(head, 0);
    Node *tail = insertatend(head, 100);
    head = deletehead(head);
    tail = deleteend(head);
    head = insertpos(head, 50, 3);
    int pos = search(head, 50);
    cout << pos << endl;
    traverse(head);
    return 0;
}