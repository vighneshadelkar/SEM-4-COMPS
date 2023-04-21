// Vioghnesh's code for fcfs disk scheduling ;)
#include<bits/stdc++.h>
using namespace std;

void fcfs_disk(int a[],int head,int n)
{
    int cur=head;
    int dist,seek_count=0;

    for(int i=0;i<n;i++)
    {
        dist=abs(cur-a[i]);
        cur=a[i];
        seek_count+=dist;
    }

    // seek order
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"->";
    }

    cout<<"total seek dist: "<<seek_count;
}
int main()
{
    int a[]={176, 79, 34, 60, 92, 11, 41, 114};
    int n;
    n=sizeof(a)/sizeof(a[0]);
    int head=50;
    fcfs_disk(a,head,n);
    return 0;
}