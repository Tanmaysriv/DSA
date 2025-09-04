class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head) return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        int count = 0;
        Node* temp = head;

        // Step 1: Count available nodes (can be < k also)
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        // Step 2: Reverse the counted nodes (always reverse, even if count < k)
        curr = head;
        count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Recursively reverse the rest
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        return prev; // New head
    }
};
