#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// A Huffman tree node
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

// Comparison function for priority queue
class Compare {
public:
    bool operator()(Node* l, Node* r)
    {
        return (l->frequency > r->frequency);
    }
};

// Huffman coding class
class Huffman {
public:
    // Function to print Huffman codes from the root of the Huffman tree
    void printCodes(Node* root, string str)
    {
        if (!root)
            return;

        if (root->data != '$')
            cout << root->data << ": " << str << "\n";

        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");
    }

    // Huffman coding function
    void encode(char data[], int frequency[], int size)
    {
        Node *left, *right, *top;

        // Create a priority queue to store live nodes of the Huffman tree
        priority_queue<Node*, vector<Node*>, Compare> pq;

        // Create a node for each character and add it to the priority queue
        for (int i = 0; i < size; ++i)
            pq.push(new Node(data[i], frequency[i]));

        // Construct the Huffman tree until there is only one node left in the priority queue
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

        // Print Huffman codes
        printCodes(pq.top(), "");
    }
};

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    char* data = new char[size];
    int* frequency = new int[size];

    cout << "Enter the elements and frequencies:\n";
    for (int i = 0; i < size; ++i) {
        cin >> data[i] >> frequency[i];
    }

    Huffman huffman;
    huffman.encode(data, frequency, size);

    delete[] data;
    delete[] frequency;

    return 0;
}
