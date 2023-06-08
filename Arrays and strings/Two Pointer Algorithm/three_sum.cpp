// //Following soln works in O(n*n*log n) and SC of O(n) and gives TLE
// //Have put this question in arrays for the following brute soln usin 2 sum type ka concept.  
//Refer to next soln for the optimal 2 pointer approach
//
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) 
//     {
//         set<vector<int>> t;
//         unordered_map<int,int> m;
//         for (int i=0;i<nums.size();i++)
//         {
//             m[nums[i]]=i;
//         }   
//         for (int i=0;i<nums.size();i++)
//         {
//             int a=nums[i];
//             for (int j=0;j<nums.size();j++)
//             {
//                 if (i==j)
//                 continue;
//                 int sum=-a;
//                 int target=sum-nums[j];
//                 if (m.find(target)!=m.end() and m.find(target)->second!=j and m.find(target)->second!=i)
//                 {
//                     vector<int> temp;
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(nums[m.find(target)->second]);
//                     sort(temp.begin(),temp.end());
//                     t.insert(temp);
//                 }

//             }
//         } 
//         vector<vector<int>> ans;
//         for (auto it:t)
//         {
//             ans.push_back(it);
//         }
//         return ans;
//     }
// };

// The following soln is a 2 pointer soln
// This soln works in O(n*n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());int a=1e9;
        for (int i=0;i<nums.size()-2;i++)
        {
            if (nums[i]==a) //because for this nums[i] you have recorded all triplets
            continue;
            a=nums[i];
            int low=i+1;int high=nums.size()-1;
            int sum=-a;int mark1=1e9,mark2=1e9; // mark1 and mark2 are basically 2nd and 3rd pointers of the triplet -> kept so that for 1 nums[i] same 2 elements are not added to form a triplet
            while (low<high)
            {
                if (nums[low]+nums[high]<sum)
                {
                    low++;
                }
                else if (nums[low]+nums[high]>sum)
                {
                    high--;
                }
                else if (nums[low]+nums[high]==sum)
                {
                    if (nums[low]==mark1 and nums[high]==mark2)
                    {
                        low++;high--;
                    }
                    else
                    {
                        mark1=nums[low]; // keep a mark to remember that this triplaet has already been added
                        mark2=nums[high];
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        low++;
                        high--;
                    }
                }
            }

        }  
        return ans;
    }
};
