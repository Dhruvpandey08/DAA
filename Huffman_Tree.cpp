#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
class Node {
public:
    char data;
    unsigned frequency;
    Node* left;
    Node* right;
    Node(char data, unsigned frequency)
    {
        left = right = nullptr;
        this->data = data;
        this->frequency = frequency;
    }
};
class Compare {
public:
    bool operator()(Node* l, Node* r)
    {
        return (l->frequency > r->frequency);
    }
};
class Huffman {
public:
    void printCodes(Node* root, string str)
    {
        if (!root)
            return;
        if (root->data != '$')
            cout << root->data << ": " << str << "\n";
        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");
    }
    void encode()
    {
        int n;
        cin >> n;
        char data[n];
        int frequency[n];
        for (int i = 0; i < n; ++i) {
            cin >> data[i];
            cin >> frequency[i];
        }
        Node *left, *right, *top;
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for (int i = 0; i < n; ++i)
            pq.push(new Node(data[i], frequency[i]));
        while (pq.size() != 1) {
            left = pq.top();
            pq.pop();
            right = pq.top();
            pq.pop();
            top = new Node('$', left->frequency + right->frequency);
            top->left = left;
            top->right = right;
            pq.push(top);
        }
        printCodes(pq.top(), "");
    }
};
int main()
{
    Huffman huffman;
    huffman.encode();
    return 0;
}