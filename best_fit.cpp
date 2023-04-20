//Vighnesh's cpp code for  best fit ;)
#include<bits/stdc++.h>

using namespace std;

void best_fit(int blockSize[],int process[],int m,int n)
{
    int alloc[n];
    // assign each index -1
    for(int i=0;i<n;i++)
    {
        alloc[i]=-1;
    }

    // calculate index for process whic is best for block
    for(int i=0;i<n;i++)
    {
        int best=-1;
        for(int j=0;j<m;j++)
        {
            if(blockSize[j]>=process[i])
            {
                if(best==-1)
                {
                    best=j;
                }
                else if(blockSize[best] > blockSize[j])
                {
                    best=j;
                }
            }
        }
        if(best !=-1)
        {
            alloc[i]=best;
            blockSize[best]-=process[i];
        }
    }

    cout<<"process no process size blockn llocated"<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<i+1<<"\t\t\t"<<process[i]<<"\t\t\t";              
        if (alloc[i] != -1)
        {
            cout << alloc[i] + 1 << "\n";
        }
        else
        {
            cout << "block not allocated" << "\n";
        }
    }
}
int main()
{
    int blockSize[] = {20, 30, 40, 10};
    int process[] = {20, 10, 30, 40};
    int m, n;
    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(a) / sizeof(a[0]);
    best_fit(blockSize, a, m, n);
    return 0;
}