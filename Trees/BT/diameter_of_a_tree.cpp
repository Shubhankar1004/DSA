//Brute force in O(n2)


class Solution {
  public:
  
    int height(Node *root)
    {
        if (root==NULL)
        return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return(1+max(lh,rh));
    }
  
    void diam(Node *root,int &h)
    {
        if (root==NULL)
        return;
        int h1=height(root->left);
        int h2=height(root->right);
        h=max(h,h1+h2+1);
        diam(root->left,h);
        diam(root->right,h);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) 
    {
        // Your code here
        int fin=0;
        diam(root,fin);
        return fin;
    }
};


//Optimised



class Solution {
  public:
  
    int answer(Node* &root, int &h){
       if(root==NULL) return 0;
       int l = answer(root->left, h);
       int r = answer(root->right, h);
       h = max(l+r+1,h);
       
       return max(l,r)+1;
       
   }
   // Function to return the diameter of a Binary Tree.
   int diameter(Node* root) {
       // Your code here
       int h = INT_MIN;
       answer(root, h);

       
   return h; 
       
   }
};

