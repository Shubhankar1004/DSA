//similar as find number of islands and works in time complexity of O(rows) * O(col)


class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newcolor,int k)
    {
        if (i<0 || j<0 || i>=image.size() || j>=image[0].size())
        return;
        if (image[i][j]!=k || image[i][j]==newcolor)
        return;
        image[i][j]=newcolor;
        dfs(image,i-1,j,newcolor,k);
        dfs(image,i+1,j,newcolor,k);
        dfs(image,i,j-1,newcolor,k);
        dfs(image,i,j+1,newcolor,k);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        // Code here 
        
        int k=image[sr][sc];
        //if (image[sr][sc]==1)
        dfs(image,sr,sc,newColor,k);
        return image;
    }
};
