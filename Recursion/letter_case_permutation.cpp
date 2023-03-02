class Solution {
public:
    void perm(string s,string op,set<string> &k)
    {
        if (s.length()==0)
        {
            k.insert(op);
            return;
        }
        string op1=op;
        string op2=op;
        if (isupper(s[0]))
            op2+=tolower(s[0]);
        else if(islower(s[0]))
            op2+=toupper(s[0]);
        else
            op2+=s[0];
        op1+=s[0];
        s.erase(s.begin()+0);
        perm(s,op1,k);
        perm(s,op2,k);
    }
    vector<string> letterCasePermutation(string s) 
    {
        set<string>k;
        
        string op="";
        perm(s,op,k);
        vector<string>v(k.begin(),k.end());
        return v;
    }
};
