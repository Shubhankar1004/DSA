class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        map<int,vector<int>>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while (!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node *t=it.first;
            int line=it.second;
            m[line].push_back(t->data);
            if (t->left)
            q.push({t->left,line-1});
            if (t->right)
            q.push({t->right,line+1});
        }
        for (auto i:m)
        {
            for (auto j:i.second)
            {
                ans.push_back(j);
                break;
            }
        }
        return ans;
    }

};



//bottom


class Solution {
  public:
    vector <int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int>ans;
        map<int,vector<int>>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while (!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node *t=it.first;
            int line=it.second;
            m[line].push_back(t->data);
            if (t->left)
            q.push({t->left,line-1});
            if (t->right)
            q.push({t->right,line+1});
        }
        for (auto i:m)
        {
            ans.push_back(i.second[i.second.size()-1]);
        }
        return ans;
    
    }
};
