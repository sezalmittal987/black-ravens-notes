int Solution::maximumGap(const vector<int> &A) {
    int maxdis=-1;
    int i,j;
    int sz=A.size();
    int *lmin= new int[sz];
    int *rmax= new int[sz];
    lmin[0]=A[0];
    for(i=1;i<sz;i++)
        lmin[i]=min(A[i],lmin[i-1]);
    rmax[sz-1]=A[sz-1];
    for(i=sz-2;i>=0;i--)
        rmax[i]=max(A[i],rmax[i+1]);
    
    i=0;j=0;
    while(i<sz && j<sz)
    {
        if(lmin[i]<=rmax[j])
        {
            maxdis=max(maxdis,j-i);
            j++;
        }
        else
            i++;
    }
    return maxdis;
}