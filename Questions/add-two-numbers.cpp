#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct listnode {
    int val;
    struct listnode *next;
}ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *first = l1, *second = l2;
    ListNode *result = NULL, *head = NULL;
    int carry = 0;
    while (first != NULL && second != NULL) {
        int sum = first -> val + second -> val + carry;
        if (sum > 9) {
            carry = (sum / 10) % 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }
        ListNode *newNode = (ListNode *) malloc(sizeof (ListNode));
        newNode -> val = sum;
        newNode -> next = NULL;
        if (result == NULL && head == NULL) {
            result = newNode;
            head = result;
        } else {
            head -> next = newNode;
            head = head -> next;
        }
        first = first -> next;
        second = second -> next;
    }
    if (first == NULL && second != NULL) {
        first = second;
    }
    while (first != NULL) {
            int sum = first -> val + carry;
            if (sum > 9) {
                sum = sum % 10;
                carry = (sum / 10) % 10;
                cout << "Sum : " << carry;
                cout << "Carry : " << carry;
            } else {
                carry = 0;
            }
            ListNode *newNode = (ListNode *) malloc(sizeof (ListNode));
            newNode -> val = sum;
            newNode -> next = NULL;
            if (result == NULL && head == NULL) {
                result = newNode;
                head = result;
            } else {
                head -> next = newNode;
                head = head -> next;
            }
            first = first -> next;
    }
    cout << "Carry : " << carry;
    if (carry > 0) {
        ListNode *newNode = (ListNode *) malloc(sizeof (ListNode));
        newNode -> val = carry;
        newNode -> next = NULL;
        head -> next = newNode;
    }
    return result;
}

ListNode* getNewNode(int value) {
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    temp -> val = value;
    temp -> next = NULL;
    return temp;
}

int main() {
    
    ListNode *l1 = getNewNode(1);
    //l1 -> next = getNewNode(6);
    // l1 -> next -> next = getNewNode(4);
    
    ListNode *l2 = getNewNode(9);
    l2 -> next = getNewNode(9);
    //l2 -> next -> next = getNewNode(3);

    ListNode *result = addTwoNumbers(l1, l2);
    while(result != NULL) {
        cout << result -> val << " ";
        result = result -> next;
    }
    return 0;
}