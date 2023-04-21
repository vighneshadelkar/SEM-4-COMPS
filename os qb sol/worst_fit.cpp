// Vighnesh's cpp code for worst fit ;)
#include <bits/stdc++.h>

using namespace std;

void worst_fit(int blockSize[], int process[], int n, int m)
{
    int alloc[n];
    for (int i = 0; i < n; i++)
    {
        alloc[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int worst = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= process[i])
            {
                if (worst == -1)
                {
                    worst = j;
                }
                else if (blockSize[worst] < blockSize[j])
                {
                    worst = j;
                }
            }
        }

        if (worst != -1)
        {
            alloc[i] = worst;
            blockSize[worst] -= process[i];
        }
    }

    cout << "process no "
         << "process Size "
         << "block allocated"
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t\t" << process[i] << "\t\t";
        if (alloc[i] != -1)
        {
            cout << alloc[i] + 1 << "\n";
        }
        else
        {
            cout << "not allocated"
                 << "\n";
        }
    }
}

int main()
{
    int n, m;
    int blockSize[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(process) / sizeof(process[0]);
    worst_fit(blockSize, process, n, m);
    return 0;
}