// 
#include<bits/stdc++.h>

using namespace std;

void scan(int process[],int head,int n,int direction)
{
    int complete=0,best,done[n],head_movement=0;
    while(complete<n)
    {
        int index=-1;
        if(direction==0)
        {
            best=INT_MIN;
        }
        else
        {
            best=INT_MAX;
        }
        for(int i=0;i<n;i++)
        {
            if(!done[i])
            {
                if(direction==0 && process[i]>best && process[i]<head)
                {
                    index=i;
                    best=process[i];
                }
                if(direction==1 && process[i]<best && process[i]>head)
                {
                    index=i;
                    best=process[i];
                }
            }
        }

        if(index >= 0)
        {
            complete++;
            done[index] = true;
            head_movement += abs(head - best);
            cout<<process[index]<<"->";
            head = process[index];
        }
        else
        {
            if (direction == 0)
            {
                cout << "0"<<"->";
            }
            else
            {
                cout << "199"<<"->";
            }
            direction = 1 - direction;
        }
    }
    cout<<"\n"<<head_movement;
}

int main()
{
    int process[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head=50,n,direction=1;
    n = sizeof(process) / sizeof(process[0]);
    scan(process,head,n,direction);
    return 0;
}