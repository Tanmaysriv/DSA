class Solution {
public:
    Node* reverse(Node* head) {
        if (!head || !head->next) return head; // empty list or single node

        Node* curr = head;
        Node* temp = NULL;

        // Swap next and prev for all nodes
        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev; // move to "next" node (which is prev now)
        }

        // temp will be at the old head, so the new head is temp->prev
        if (temp != NULL) {
            head = temp->prev;
        }

        return head;
    }
};
