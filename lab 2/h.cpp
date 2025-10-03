#include<iostream>
using namespace std;
#define ll long long
ll n, k;
string s;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

Node* insert(Node* head, int x, int p) {
    Node* newNode = new Node(x);
    if (p == 0) { 
        newNode->next = head;
        return newNode;
    }
    Node* curr = head;
    for (int i = 0; i < p - 1 && curr; i++) curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

Node* remove(Node* head, int p) {
    if (!head) return nullptr;
    if (p == 0) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* curr = head;
    for (int i = 0; i < p - 1 && curr; i++) curr = curr->next;
    Node* toDelete = curr->next;
    curr->next = toDelete->next;
    delete toDelete;
    return head;
}

void print(Node* head) {
    if (!head) {
        cout << -1 << "\n";
        return;
    }
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

Node* replace(Node* head, int p1, int p2) {
    if (!head || p1 == p2) return head;

    Node* prev1 = nullptr, *node1 = head;
    for (int i = 0; i < p1 && node1; i++) {
        prev1 = node1;
        node1 = node1->next;
    }
    if (!node1) return head;

    if (prev1) prev1->next = node1->next;
    else head = node1->next;

    if (p2 == 0) {
        node1->next = head;
        return node1;
    }
    Node* curr = head;
    for (int i = 0; i < p2 - 1 && curr; i++) curr = curr->next;
    node1->next = curr->next;
    curr->next = node1;
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* cyclic_left(Node* head, int x) {
    if (!head || x == 0) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    x %= len;
    if (x == 0) return head;

    Node* curr = head;
    for (int i = 0; i < x - 1; i++) curr = curr->next;
    Node* newHead = curr->next;
    curr->next = nullptr;
    tail->next = head;
    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (!head || x == 0) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    x %= len;
    if (x == 0) return head;

    int left = len - x;
    Node* curr = head;
    for (int i = 0; i < left - 1; i++) curr = curr->next;
    Node* newHead = curr->next;
    curr->next = nullptr;
    tail->next = head;
    return newHead;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;

    while (true) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) break;

        if (cmd == 1) { 
            int x, p;
            cin >> x >> p;
            head = insert(head, x, p);
        } 
        else if (cmd == 2) 
        { 
            int p;
            cin >> p;
            head = remove(head, p);
        } 
        else if (cmd == 3) 
        {
            print(head);
        } 
        else if (cmd == 4) 
        { 
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } 
        else if (cmd == 5) 
            head = reverse(head);
        else if (cmd == 6) 
        {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } 
        else if (cmd == 7) 
        {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
}