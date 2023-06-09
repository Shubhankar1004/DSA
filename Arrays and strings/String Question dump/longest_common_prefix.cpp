//In the following approach if there are m chars max and everytime you have to make at worst m comparisons then time complexity will be O(m*n)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans =strs[0];
        for (auto it:strs)
        {
            if (ans=="") //intersection of strings compared till now is blank
            return ans;
            string s=it;
            string temp=""; //accumulating common prefix
            int mini=min(s.size(),ans.size());
            for (int i=0;i<mini;i++)
            {
                if (s[i]==ans[i])
                temp+=s[i];//accumulating common prefix
                else
                {
                    ans=temp;//if doesnt match then ans=common part till now
                    break;
                }
            }
            ans=temp;// this line is needed coz if later string is common but smaller then else case will not be entered and ans will not be rewritten. eg [a,ab] -> dry run with ans=temp not here.
        }
        return ans;
    }
};


//better soln -> just sort and check only the first and last statements as only those comparisons are required
//TC of O(nlogn)+O(m)

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};
