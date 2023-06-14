#include <bits/stdc++.h> 
int mod=1e9+7;
#define ll long long
ll f(int i,int j,int isTrue,string &exp,vector<vector<vector<ll>>>&dp){
    if(i>j)return 0;
    if(i==j){
        if(isTrue){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    ll ways=0;
    for(int k=i+1;k<=j-1;k+=2){
        ll lt=f(i,k-1,1,exp,dp);
        ll lf=f(i,k-1,0,exp,dp);
        ll rt=f(k+1,j,1,exp,dp);
        ll rf=f(k+1,j,0,exp,dp);
        if(exp[k]=='&'){
            if(isTrue){
                ways+=(lt*rt)%mod;
            }
            else{
                ways+=((lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod)%mod;
            }
        }
        else if(exp[k]=='|'){
            if(isTrue){
                ways+=((lt*rf)%mod+(lf*rt)%mod+(lt*rt)%mod)%mod;
            }
            else{
                ways+=(lf*rf)%mod;
            }
        }
        else{
            if(isTrue){
                ways+=((lf*rt)%mod+(lt*rf)%mod)%mod;
            }
            else{
                ways+=((lf*rf)%mod+(lt*rt)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue]=ways%mod;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.size();
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return f(0,n-1,1,exp,dp);
}
