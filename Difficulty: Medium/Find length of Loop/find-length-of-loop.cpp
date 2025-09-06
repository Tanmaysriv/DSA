/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int lengthOfLoop(Node *head) {
        // Code here
        Node* slow=head;
        Node* fast=head;
        // int count=0;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int count =1;
                Node* temp = slow;
                while(temp->next!=slow)
                {
                    temp=temp->next;
                    count++;
                }
                return count;
            }
            
        }
        return 0;
    }
};