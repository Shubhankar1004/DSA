
class Solution{
  public:
  //vector<int>v;
  int l=-1,flag=1;
    bool level(Node *root,int lev)
    {
        if (root->left==NULL && root->right==NULL)
        {
            //v.push_back(lev);
            if (l==-1)
            l=lev;
            else
            {
                if (lev!=l)
                flag=0;
            }
            
            
        }
        else
        {
            if (root->left)
            level(root->left,lev+1);
            if (root->right)
            level(root->right,lev+1);
        }
    }
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        if (root==NULL)
        return 1;
        level(root,1);
        /*if (v.size()==1)
        return 1;
        else
        {
            for(int i=0;i<v.size()-1;i++)
            {
                if (v[i]!=v[i+1])
                return 0;
            }
            return 1;
        }*/
        return flag;
    }
};
