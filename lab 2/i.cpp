#include<iostream>
using namespace std;
#define ll long long
ll n, k;
string s;

struct Node 
{
    string book;
    Node* prev;
    Node* next;

    Node(string b) 
    {
        book = b;
        prev = next = nullptr;
    }
};

struct DLL 
{
    Node* head;
    Node* tail;

    DLL() 
    {
        head = tail = nullptr;
    }

    void add_front(string book) 
    {
        Node* newNode = new Node(book);

        if (!head)
            head = tail = newNode;
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "ok\n";
    }

    void add_back(string book) 
    {
        Node* newNode = new Node(book);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok\n";
    }

    void erase_front() 
    {
        if (!head) 
        {
            cout << "error\n";
            return;
        }

        cout << head->book << "\n";

        Node* temp = head;
        head = head->next;

        if (head) 
            head->prev = nullptr;
        else 
            tail = nullptr;

        delete temp;
    }

    void erase_back() 
    {
        if (!tail) 
        {
            cout << "error\n";
            return;
        }
            
        cout << tail->book << "\n";

        Node* temp = tail;
        tail = tail->prev;

        if (tail) 
            tail->next = nullptr;
        else 
            head = nullptr;

        delete temp;
    }

    void front() 
    {
        if(head) 
            cout << head->book << "\n";
        else    
            cout << "error\n";
    }

    void back() 
    {
        if (tail) 
            cout << tail->book << "\n";
        else    
            cout << "error\n";
    }

    void clear() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        head = tail = nullptr;
        cout << "ok\n";
    }
};

int main() {

    DLL dll;
    string cmd;

    while (cin >> cmd) 
    {
        if (cmd == "add_front") 
        {
            string book;
            cin >> book;
            dll.add_front(book);
        } 
        else if (cmd == "add_back") 
        {
            string book;
            cin >> book;
            dll.add_back(book);
        } 
        else if (cmd == "erase_front")
            dll.erase_front();
        else if (cmd == "erase_back")
            dll.erase_back();
        else if (cmd == "front")
            dll.front();
        else if (cmd == "back")
            dll.back();
        else if (cmd == "clear")
            dll.clear();
        else if (cmd == "exit") {
            cout << "goodbye\n";
            break;
        }
    }
}