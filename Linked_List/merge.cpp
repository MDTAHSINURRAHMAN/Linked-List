// Merge two linked list
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void append(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

Node *merge(Node *&head1, Node *&head2)
{
    Node *first_head = head1;
    Node *second_head = head2;
    Node *dummy_node = new Node();
    Node *merge_head = dummy_node;

    while (first_head != NULL && second_head != NULL)
    {
        if (first_head->data > second_head->data)
        {
            merge_head->next = second_head;
            second_head = second_head->next;
        }
        else
        {
            merge_head->next = first_head;
            first_head = first_head->next;
        }
        merge_head = merge_head->next;
    }

    while (first_head != NULL)
    {
        merge_head->next = first_head;
        first_head = first_head->next;
        merge_head = merge_head->next;
    }

    while (second_head != NULL)
    {
        merge_head->next = second_head;
        second_head = second_head->next;
        merge_head = merge_head->next;
    }
    return dummy_node->next;
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
    Node *head1 = NULL;
    Node *head2 = NULL;
    int array_1[] = {7, 45, 53, 93, 102};
    int array_2[] = {34, 67, 87};
    for (int i = 0; i < 5; ++i)
    {
        append(&head1, array_1[i]);
    }
    for (int i = 0; i < 3; ++i)
    {
        append(&head2, array_2[i]);
    }

    cout << "First Sorted Linked List is: ";
    printList(head1);
    cout << endl;
    cout << "Second Sorted Linked List is: ";
    printList(head2);
    cout << endl;

    Node *new_head = merge(head1, head2);
    cout << "Two Sorted Linked List Merge: ";
    printList(new_head);
}