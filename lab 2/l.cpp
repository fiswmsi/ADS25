#include<iostream>
#include<string>
using namespace std;
#define ll long long
ll n, k, t, T;
string s;


struct Node 
{
    int val;
    Node* next;
    Node(int v) 
    {
        val = v;
        next = NULL;
    }
};

struct LL 
{
    Node* head;
    Node* tail;

    LL() 
    {
        head = tail = NULL;
    }

    void appendLL(int v) 
    {
        Node* newNode = new Node(v);
        if (!head) 
            head = tail = newNode;
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int mSS() {
        if (!head) 
            return 0; 

        int current_sum = head->val;
        int max_sum = head->val;

        Node* curr = head->next;

        while (curr) 
        {
            current_sum = max(curr->val, current_sum + curr->val);

            if (current_sum > max_sum)
                max_sum = current_sum;
            curr = curr->next;
        }

        return max_sum;
    }
};

int main() {

    cin >> n;

    LL list;
    for (int i = 0; i < n; i++) {
        cin >> k;
        list.appendLL(k);
    }

    cout << list.mSS() << "\n";
}