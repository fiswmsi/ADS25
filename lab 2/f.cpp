#include<iostream>
using namespace std;
#define ll long long
ll n, k;
string s;

struct Node 
{
    ll data;
    Node* next;
    Node(ll d) {
        data = d;
        next = nullptr;
    }
};

struct LL 
{
    Node* head;

    LL() 
    {
        head = nullptr;
    }

    void appLL(ll n) 
    {
        Node* newNode = new Node(n);
        if (!head) 
        {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }

    void insertAt(ll pos, ll n) 
    {
        Node* newNode = new Node(n);
        if (pos == 0) 
        { 
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void printLL() 
    {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main() {
    cin >> n;
    LL list;

    for (int i = 0; i < n; i++) 
    {
        cin >> k;
        list.appLL(k);
    }
    ll data, pos;

    cin >> data >> pos;

    list.insertAt(pos, data);
    list.printLL();
}