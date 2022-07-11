vector<int> findSpiral(Node *root)
{
   //Your code here
   vector<int> ans;
   if(root==NULL){
       return ans;
   }
   deque<Node*> dq;
   dq.push_back(root);
   ans.push_back(root->data);
   int check = 1;
   while(dq.empty()==false){
       int count = dq.size();
       if(check%2==0){
           for(int i = 0;i<count;i++){
               Node *temp = dq.back();
               dq.pop_back();
               if(temp->right!=NULL){
                     dq.push_front(temp->right);
                     ans.push_back(temp->right->data);
               }
               if(temp->left!=NULL){
                     dq.push_front(temp->left);
                     ans.push_back(temp->left->data);
               }
           }
       }
       else{
           for(int i = 0;i<count;i++){
               Node *temp = dq.front();
               dq.pop_front();
               if(temp->left!=NULL){
                     dq.push_back(temp->left);
                     ans.push_back(temp->left->data);
               }
               if(temp->right!=NULL){
                     dq.push_back(temp->right);
                     ans.push_back(temp->right->data);
               }
           }
       }
       check++;
   }
   return ans;
}
