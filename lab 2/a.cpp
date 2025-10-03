#include<iostream>
using namespace std;
#define ll long long
ll n, k;
string s;

struct Node 
{
    ll value;
    Node* next;

    Node(ll v) {
        value = v;
        next = nullptr;
    }
};

struct LL
{
    Node* head;
    Node* tail;

    LL() 
    {
        head = nullptr;
        tail = nullptr;
    }

    void appLL(ll v) 
    {
        Node* newNode = new Node(v);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int ni(ll k) 
    {
        if (!head) return -1;
        Node* curr = head;
        int index = 0;
        int nearest = 0;
        ll bestDiff = llabs(curr->value - k);

        while (curr) {
            ll diff = llabs(curr->value - k);
            if (diff < bestDiff) {
                bestDiff = diff;
                nearest = index;
            }
            curr = curr->next;
            index++;
        }
        return nearest;
    }
};

int main() 
{
    cin >> n;

    LL list;
    for (int i = 0; i < n; i++) 
    {
        cin >> k;
        list.appLL(k);
    }

    cin >> k;

    cout << list.ni(k) << "\n";
}