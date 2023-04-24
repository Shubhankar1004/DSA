class Solution {
public:
    // This function generates the first numRows of Pascal's Triangle and returns it as a 2D vector of integers.
vector<vector<int>> generate(int numRows) {
    // Initialize an empty 2D vector
    vector<vector<int>> ans;

    // Iterate numRows times to generate each row of Pascal's Triangle
    for(int i=0;i<numRows;i++)
    {
        // Create a new row of integers with i+1 elements, all initialized to 1
        vector<int> newRow(i+1,1);

        // Loop through each element in the newRow vector, starting from the second element, until the second-last element
        for(int col=1;col<i;col++)
        {
            // Calculate the value of the current element by adding the corresponding elements from the previous row
            // Specifically, the element in the i-th row and col-th column is equal to the sum of the (i-1)th row and col-th column
            // and the (i-1)th row and (col-1)th column
            newRow[col] = ans[i-1][col] + ans[i-1][col-1];
        }

        // Push the newRow vector into the ans vector
        ans.push_back(newRow);
    }

    // Return the ans vector
    return ans;
}

};
