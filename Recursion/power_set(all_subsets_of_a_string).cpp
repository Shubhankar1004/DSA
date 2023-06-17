
void help(int i,int n,char input[],string s)
{
    if (i==n)
    {
        cout<<s<<endl;
        return;
    }
    help(i+1,n,input,s+input[i]);
    help(i+1,n,input,s);
}
void printSubsequences(char input[]) 
{
    // Write your code here
    //string s="";
     int len =0;
     while(input[len]!='\0'){
        len++;
    }
    help(0,len,input,"");
}
