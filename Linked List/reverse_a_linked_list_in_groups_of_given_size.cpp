class Solution
{
    public:
     
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if (head==NULL || k==1 )
        {
            return head;
        }
        node *s=head;
        int inc=k;
        while (s and inc--)
        {
            s=s->next;
            
        }
        
        //reverseee(s,e);
        node *new_head=reverse(s,k);
        node *p=NULL,*c=head,*n;
        while(c!=s)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        head->next=new_head;
        return p;
    }
};
