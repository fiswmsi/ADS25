#include<iostream>
using namespace std;
#define ll long long
ll n, k;
string s;

struct Node {
    string name;
    Node* next;
    Node(string n) {
        name = n;
        next = nullptr;
    }
};

struct LL {
    Node* head;
    Node* tail;
    ll cnt;

    LL() 
    {
        head = nullptr;
        tail = nullptr;
        cnt = 0;
    }

    void addLL(string n)
     {
        if (head != nullptr && head->name == n) {
            return;
        }
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
        cnt++;
    }

    void printLL() {
        cout << "All in all: " << cnt << endl << "Students:" << endl;
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->name << endl;
            curr = curr->next;
        }
    }
};

int main() 
{

    cin >> n;
    LL list;

    for (int i = 0; i < n; i++) {

        cin >> s;
        list.addLL(s);
    }

    list.printLL();
}