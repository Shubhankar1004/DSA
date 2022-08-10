//using extra space (array ka code)
void permutations(vector<int> nums,vector<int>& ds,vector<bool>& mp,vector<vector<int>> &ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(mp[i] != true){
                ds.push_back(nums[i]);
                mp[i]=true;
                permutations(nums,ds,mp,ans);
                ds.pop_back();
                mp[i]=false;
            }    
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> mp(nums.size(),false);
        vector<vector<int>> ans;
        vector<int> ds;
        permutations(nums,ds,mp,ans);
        return ans;
    }




//without using extra space (string ka code)
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    set<string>ans;
		    int i=0;
		    perm(ans,S,i);
		    //sort(ans.begin(),ans.end());
		    vector<string>v(ans.begin(),ans.end());
		    //unique(ans.begin(),ans.end());
		    return v;
		}
		
		void perm(set<string>&ans,string s,int ind)
		{
		    if (ind==s.length())
		    {
		        ans.insert(s);
		        return;
		    }
		    for (int i=ind;i<s.length();i++)
		    {
		        swap(s[i],s[ind]);
		        perm(ans,s,ind+1);
		        swap(s[i],s[ind]);
		        
		    }
		}
};







//easier way using next_permutation(v.begin(),v.end()) which returns a bool value 1 if next permutation greater than previous one is possible and stores the permutation
//irrespective of bool returned in the particular vector



class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(), S.end());
     vector<string> v;
     v.push_back(S);
     while(next_permutation(S.begin(), S.end()))
     {
         v.push_back(S);
     }
     return v;
		}
};


