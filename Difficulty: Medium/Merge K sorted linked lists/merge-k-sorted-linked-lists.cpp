#include <queue>
using namespace std;

/* 
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> pq;

        // Push the head of each list into the min-heap
        for (auto head : arr) {
            if (head != NULL) pq.push(head);
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        // Process the heap
        while (!pq.empty()) {
            Node* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};
