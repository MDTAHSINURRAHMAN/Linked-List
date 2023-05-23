#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
    return new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "prev_node can't be NULL";
        return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    push(&head, 8);
    Node *prev_node = push(&head, 3);
    push(&head, 4);
    cout << "Doubly Linked List is: ";
    printList(head);

    insertAfter(prev_node, 23);
    printList(head);
}