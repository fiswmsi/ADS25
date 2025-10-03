#include<iostream>
using namespace std;
#define ll long long
ll n, k;
struct Node {
    int value;
    int freq;
    Node* next;
    Node(int v) {
        value = v;
        freq = 1;
        next = nullptr;
    }
};

struct LL {
    Node* head = nullptr;

    void addLL(ll v) 
    {
        Node* curr = head;
        while (curr) {
            if (curr->value == v) {
                curr->freq++;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(v);
        newNode->next = head;
        head = newNode;
    }

    ll maxFreq() 
    {
        ll maxF = 0;
        Node* curr = head;

        while (curr) {
            if (curr->freq > maxF) maxF = curr->freq;
            curr = curr->next;
        }

        return maxF;
    }

    void printModes() 
    {
        ll m = maxFreq();

        for (Node* i = head; i; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->value < j->value) {
                    swap(i->value, j->value);
                    swap(i->freq, j->freq);
                }
            }
        }

        Node* curr = head;

        while (curr) {
            if (curr->freq == m) cout << curr->value << " ";
            curr = curr->next;
        }
    }
};

int main() {
    cin >> n;

    LL list;

    for (int i = 0; i < n; i++) {
        cin >> k;
        list.addLL(k);
    }

    list.printModes();
    return 0;
}