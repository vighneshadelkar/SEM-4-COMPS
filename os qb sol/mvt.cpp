#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ms, process[5], alloc[5], extf = 0;

    for (int i = 0; i < 5; i++)
    {
        alloc[i] = -1;
    }

    cout << "enter the memory size (in Bytes):" << endl;
    cin >> ms;

    // cout<<"enter the block size (in Bytes):"<<endl;
    // cin>>bs;

    // nob=ms/bs;
    
    int cms=ms;
    for (int i = 0; i < 5; i++)
    {
        cout << "enter size each process requires(in Bytes):" << endl;
        cin >> process[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (ms > process[i])
        {
            alloc[i] = 1;
            ms -= process[i];
            // intf+=abs(bs-process[i]);
        }
    }

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        if (alloc[i] == 1)
        {
            sum += process[i];
        }
    }
    
    extf = cms - sum;
    cout << "Process NO \t"
         << "memory required\t"
         << "allocation" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << "\t\t\t" << process[i] << "\t\t\t";
        if (alloc[i] == 1)
        {
            cout << "allocated" << endl;
        }
        else
        {
            cout << "not allocated" << endl;
        }
    }

    // cout<<"internal fragmentation: "<<intf<<endl;
    cout << "external fragmentation: " << extf << endl;

    return 0;
}