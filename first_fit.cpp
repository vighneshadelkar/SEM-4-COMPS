//Vighnesh's cpp code for first fit ;)
#include <bits/stdc++.h>

using namespace std;

void first_fit(int blockSize[], int process[], int m, int n)
{
    int alloc[n];
    int frag = 0, diff;

    for (int i = 0; i < n; i++)
    {
        alloc[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= process[i])
            {
                alloc[i] = j;
                blockSize[j]-=process[i];
                break;
            }
        }
    }

    // print allocated array
    cout<<"process no process size blocks llocated"<<"\n";
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
    int process[] = {10, 20, 30, 40};
    int m, n;
    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(a) / sizeof(a[0]);
    first_fit(blockSize, a, m, n);
    return 0;
}