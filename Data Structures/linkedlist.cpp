#include<iostream>

using namespace std;

typedef struct node {
    int value;
    struct node *next;
} node;

node* createNewNode(int value) {
    node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> value = value;
    newNode -> next = NULL;
    return newNode;
}

node* insert(node *head, int value) {
    node *newNode = createNewNode(value);
    while (head -> next != NULL) {
        head = head -> next;
    }
    head -> next = newNode;
    return head;
}

void print(node *linkedList) {
    node *temp = linkedList;
    while (temp != NULL) {
        cout << temp -> value << " ";
        temp = temp -> next;
    }
}

int main() {
    
    node *linkedList = NULL;

    for (int i = 0; i < 2; i++) {
        int in;
        cin >> in;
        if (linkedList == NULL) {
            linkedList = createNewNode(in);    
        } else {
            linkedList = insert(linkedList, in);
        }
    }
    print(linkedList);
    return 0;
}