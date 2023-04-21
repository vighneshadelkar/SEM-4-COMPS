// fifo page replacement
#include <bits/stdc++.h>

using namespace std;

int frames = 3;

int main()
{
    int values[] = {1, 2, 3, 1, 4, 5, 2}, pagehits = 0;

    int pages = sizeof(values) / sizeof(values[0]);

    cout << "incoming value"
         << "frame1"
         << "frame2"
         << "frame3" << endl;

    int temp[frames];
    for (int i = 0; i < frames; i++)
    {
        temp[i] = -1;
    }

    for (int i = 0; i < pages; i++)
    {
        int s = 0;
        for (int j = 0; j < frames; j++)
        {
            if (values[i] == temp[j])
            {
                s++;
                pagehits--;
            }
        }
        pagehits++;

        // first allocation to frames
        if ((pagehits <= frames) && s == 0)
        {
            temp[i] = values[i];
        }
        else if (s == 0)
        {
            temp[(pagehits - 1) % frames] = values[i];
        }

        cout << values[i] << "\t\t";
        for (int k = 0; k < frames; k++)
        {
            if (temp[k] != -1)
            {
                cout << temp[k]<<"\t" ;
            }
            else
            {
                cout << " - ";
            }
        }
        cout << endl;
    }

    return 0;
}
