#include<iostream>
#include<string>
using namespace std;
#define ll long long
ll n, k, t, T;
string s;

struct Node 
{
    char ch;
    Node* prev;
    Node* next;
    Node(char c) 
    {
        ch = c;
        prev = next = NULL;
    }
};

struct DLL 
{
    Node* head;
    Node* tail;
    Node* map[26]; 

    DLL() 
    {
        head = tail = NULL;
        for (int i = 0; i < 26; i++) map[i] = NULL;
    }

    void add(char c) 
    {
        Node* newNode = new Node(c);
        if (!head)
            head = tail = newNode;
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        map[c - 'a'] = newNode;
    }

    void remove(char c) 
    {
        Node* node = map[c - 'a'];
        if (!node) 
            return;

        if (node == head) 
            head = head->next;
        if (node == tail)   
            tail = tail->prev;
        if (node->prev)     
            node->prev->next = node->next;
        if (node->next) 
            node->next->prev = node->prev;

        map[c - 'a'] = NULL;
        delete node;
    }

    char front() 
    {
        if (!head) return '#';
        return head->ch;
    }

    void clearAll() 
    {
        while (head) 
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        tail = NULL;
        for (int i = 0; i < 26; i++) 
            map[i] = NULL;
    }
};

int main() {

    cin >> T;

    while (T--) {

        cin >> n;

        int freq[26] = {0};
        DLL dll;

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            freq[c - 'a']++;

            if (freq[c - 'a'] == 1) {
                dll.add(c);
            } else if (freq[c - 'a'] == 2) {
                dll.remove(c);
            }

            char ans = dll.front();
            if (ans == '#') cout << -1;
            else cout << ans;
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
        dll.clearAll();
    }
}