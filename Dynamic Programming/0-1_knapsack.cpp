

//Striver style code

int help(int i,vector<int> weight,vector<int> value,int maxWeight,int n,vector<vector<int>> &dp)
{
	if (i==0)
	{
		if (weight[i]<=maxWeight)
		return value[i];
		else
		return 0;
	}
	if (dp[i][maxWeight]!=-1)
	return dp[i][maxWeight];
	int take=0,nottake=0;
	nottake=0+help(i-1,weight,value,maxWeight,n,dp);
	if (weight[i]<=maxWeight)
	take=value[i]+help(i-1,weight,value,maxWeight-weight[i],n,dp);
	return dp[i][maxWeight]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return help(n-1,weight,value,maxWeight,n,dp);
}



//Aditya Varma style code




//1. Recursive Approach
int knapSack(int w, int wt[], int val[], int n) 
    { 
       //Base Case
       if(n==0 || w==0) return 0;
       
        //Choice Diagram Code 
        //1. Choice to include item or not
        if(wt[n-1] <= w){
            return max(val[n-1] + knapSack(w-wt[n-1], wt, val, n-1), 0+knapSack(w,wt,val,n-1));
        }

       //2. No choice
        else if(wt[n-1] > w){
            return 0 + knapSack(w,wt,val,n-1);
        }
   }

//2. Memoize above recursive code (top-down)

int knapSack(int w, int wt[], int val[], int n){
        vector<vector<int> > t(n+1, vector<int>(w+1, -1));
        return fun(w, wt, val, n, t);
    }
    int fun(int w, int wt[], int val[], int n, vector<vector<int>>& t) 
    { 
      //Base Case
      if(n<=0 || w<=0) return 0;
       
      //Check if result exists already
      if(t[n][w] != -1) return t[n][w];
       
        //If result doesn't exist
        //Choice Diagram Code 
        //1. Choice to include item or not
        if(wt[n-1] <= w){
            t[n][w] = max(val[n-1] + fun(w-wt[n-1], wt, val, n-1, t), 0+fun(w,wt,val,n-1, t));
            return t[n][w];
        }
        
        //2. No choice
        else if(wt[n-1] > w){
            t[n][w] = 0 + fun(w,wt,val,n-1, t);
            return t[n][w];
        }
        
    }

//3. Bottom Up Approach - Dynamic Programming
int knapSack(int w, int wt[], int val[], int n) 
    {
        int t[n+1][w+1];
        
        //Initialize matrix
        for(int i=0; i<w+1; i++) t[0][i] = 0;
        for(int j=0; j<n+1; j++) t[j][0] = 0;
        
        //Choice Diagram to code
        for(int i = 1; i<n+1; i++){
            for(int j=1; j<w+1; j++){
                //1. In case of choice
                if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], 0+t[i-1][j]);
                }
                //2. No choice
                else if(wt[i-1] > j){
                    t[i][j] = 0+t[i-1][j];
                }
            }
        }
        return t[n][w];
    }
