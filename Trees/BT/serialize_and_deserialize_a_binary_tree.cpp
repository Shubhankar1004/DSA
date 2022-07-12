class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>v;
        if (root==NULL)
        {
            v.push_back(-1);
            return v;
        }
        
        queue<Node*>q;
        q.push(root);
        //int lev=0;
        while(!q.empty())
        {
            //lev++;
            Node *t=q.front();
            q.pop();
            if (t==NULL)
            {
                v.push_back(-1);
                continue;
            }
            v.push_back(t->data);
            //if (t->left)
            q.push(t->left);
            //if (t->right)
            q.push(t->right);
        }
        //for (auto x:v)
        //cout<<x<<endl;
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if (A.size()==0)
       return NULL;
       Node *root=new Node(A[0]);
       queue<Node*>q;
       
       //Node *t=root;
       q.push(root);
       A.erase(A.begin());
       while(!q.empty())
       {
           Node* t=q.front();
           q.pop();
           int ans=A[0];
           A.erase(A.begin());
           if (ans==-1)
           t->left=NULL;
           else
           {
               t->left=new Node(ans);
               q.push(t->left);
           }
           ans=A[0];
           A.erase(A.begin());
           if (ans==-1)
           t->right=NULL;
           else
           {
               t->right=new Node(ans);
               q.push(t->right);
           }
       }
       return root;
    }

};
