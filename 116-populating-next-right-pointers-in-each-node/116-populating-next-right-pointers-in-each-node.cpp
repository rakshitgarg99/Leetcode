/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* node) {
        
        if(!node) return node;
        Node* root=node;
        queue<Node*> q;
        q.push(root);
        
//         while(!q.empty()){
//             Node* prev=q.front();
//             q.pop();
//             int size=q.size();
//             if(prev->left)q.push(prev->left);
//             if(prev->right)q.push(prev->right);
            
//             for(int i=0;i<size;i++){
//                 Node* curr=q.front();
//                 q.pop();
                
//                 if(curr->left)q.push(curr->left);
//                 if(curr->right)q.push(curr->right);
//                 prev->next = curr;
//                 curr=prev;
//             }
            
//         }
        
        while(!q.empty()){
            int size=q.size();
            Node* temp=NULL;
            while(size--){
                Node*head = q.front();
                q.pop();
                head->next=temp;
                temp=head;
                
                if(head->right) q.push(head->right);
                if(head->left) q.push(head->left);
            }
        }
        return node;
    }
};