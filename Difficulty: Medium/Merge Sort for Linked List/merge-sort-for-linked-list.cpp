class Solution {
public:
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        
        Node* result;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }
    
    // Function to find the middle of the linked list
    Node* getMiddle(Node* head) {
        if (!head) return head;
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    // Main merge sort function
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
        
        // Find the middle
        Node* middle = getMiddle(head);
        Node* nextOfMiddle = middle->next;
        
        // Split the list into two halves
        middle->next = nullptr;
        
        // Recursive sorting of both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextOfMiddle);
        
        // Merge the two sorted halves
        return merge(left, right);
    }
};
