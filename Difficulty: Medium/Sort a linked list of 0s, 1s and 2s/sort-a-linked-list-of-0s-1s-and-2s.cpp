class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        int count[3] = {0, 0, 0};
        Node* temp = head;

        // Count 0s, 1s and 2s
        while (temp) {
            count[temp->data]++;
            temp = temp->next;
        }

        // Overwrite the data in sorted order
        temp = head;
        int i = 0;
        while (temp) {
            if (count[i] == 0) i++;
            else {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }
        return head;
    }
};
