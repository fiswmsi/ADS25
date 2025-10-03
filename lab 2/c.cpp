#include<iostream>
using namespace std;
#define ll long long
ll n, k;
struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(ll N)
    {
        data = N;
        next = nullptr;
        prev = nullptr;
    }
};

struct Ll
{
    Node *head;
    Node *tail;
    ll size;

    Ll()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addN(ll N)
    {
        Node *NewNode = new Node(N); // NewNode -> data = N, NewNode -> next = nullptr

        if(head == NULL && tail == NULL)
        {
            head = tail = NewNode;
        }
        else
        {
            tail -> next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
        }

        size++;
    }

    void del()
    {
        Node *curr = head;

        while(curr && curr -> next)
        {
            Node *temp = curr -> next;
            curr -> next = curr->next->next;
            delete temp;
            curr = curr->next;
            curr -> prev = curr -> prev;
        }
    }

    void printLl()
    {
        while(head)
        {
            cout << head -> data << " ";
            head = head -> next;
        }
    }
    
};

int main()
{
    cin >> n;

    Ll m;

    for(int i = 0; i < n; i++)
    {
        cin >> k;
        m.addN(k);
    }

    m.del();
    m.printLl();
}