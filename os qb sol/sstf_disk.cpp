// Vighnesh's code for sstf ;)
#include <bits/stdc++.h>

using namespace std;
int  getDiffrence(int process[], int diff[], int head, int n)
{
    for (int i = 0; i < n; i++)
    {
        diff[i] = abs(process[i] - head);
    }
}

int getMinIndex(int process[],int diff[],int head,int n)
{
    int index = -1, min = INT_MAX;
    getDiffrence(process,diff,head,n);
    for (int i = 0; i < n; i++)
    {
        if (min > diff[i])
        {
            min = diff[i];
            index = i;
        }
    }
    cout << index << endl;
    // int &min=*min_element(process,process+5 );
    return index;
}

void sstf(int process[], int head, int n)
{
    int diff[n];
    int index;

    // getMinIndex(process,diff,head,n);
    int seek_count = 0;
    for (int i = 0; i < 5; i++)
    {
        int dist;
        // getDiffrence(process, diff, head, n);
        index = getMinIndex(process,diff,head,n);
        for (int i = 0; i < n; i++)
        {
            diff[i] = 0;
        }
        dist = abs(head - process[index]);
        seek_count += dist;
        cout << process[index] << "->";
        head = process[index];
    }
    cout << "\n"
         << seek_count;
}

int main()
{
    int process[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n, head;
    n = sizeof(process) / sizeof(process[0]);
    head = 50;
    sstf(process, head, n);
    return 0;
}