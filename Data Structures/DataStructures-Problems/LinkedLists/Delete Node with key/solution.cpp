#include <bits/stdc++.h>
using namespace std;
typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
Node* insert(Node* head, int data){
    if(head == NULL){
        head = new Node;
        head->data = data;
        head->next = NULL;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* node = new Node;
    node->data = data;
    temp->next = node;
    return head;
}
void print(Node* head){
    if(head == NULL) return;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node* remove(Node* head, int x){
    if(head == NULL) return NULL;
    Node* temp = head, *pre = head;
    if(temp->data == x){
        Node* rem = head;
        head = head->next;
        delete rem;
        return head;
    }
    temp = temp->next;
    while(temp != NULL && temp->data!=x){
        pre = temp;
        temp = temp->next;
    }
    Node* rem = temp;
    pre->next = temp->next;
    delete rem;
    return head;
}
int main(){
    Node* head = NULL;
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        head = insert(head, t);
    }
    int x;
    cin >> x;
    head = remove(head, x);
    print(head);
    return 0;
}