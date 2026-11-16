/* Structure of doubly linked list Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
  public:
    vector<vector<int>> displayList(Node *head) {
        // code here
        vector<int> forward;
            vector<int> backward;

            if (head == NULL) return {forward, backward};

            Node* curr = head;

            // Forward traversal
            while (curr->next != NULL) {
                forward.push_back(curr->data);
                curr = curr->next;
            }
            forward.push_back(curr->data);

            // Backward traversal
            while (curr != NULL) {
                backward.push_back(curr->data);
                curr = curr->prev;
            }

            return {forward, backward};
     }
};