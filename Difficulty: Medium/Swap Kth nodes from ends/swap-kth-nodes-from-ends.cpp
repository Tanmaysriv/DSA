class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Count nodes
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // If k is more than number of nodes
        if (k > n) return head;

        // If kth node from beginning and end are same
        if (2*k - 1 == n) return head;

        // Find kth node from beginning
        Node* x_prev = nullptr;
        Node* x = head;
        for (int i = 1; i < k; i++) {
            x_prev = x;
            x = x->next;
        }

        // Find kth node from end
        Node* y_prev = nullptr;
        Node* y = head;
        for (int i = 1; i < n - k + 1; i++) {
            y_prev = y;
            y = y->next;
        }

        // If x_prev exists, link it to y
        if (x_prev) x_prev->next = y;
        // If y_prev exists, link it to x
        if (y_prev) y_prev->next = x;

        // Swap next pointers
        Node* tempNext = x->next;
        x->next = y->next;
        y->next = tempNext;

        // Change head if needed
        if (k == 1) head = y;
        if (k == n) head = x;

        return head;
    }
};
