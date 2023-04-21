// Vighnesh's cpp code for worst fit ;)
#include<bits/stdc++.h>

using namespace std;

// sort according to priority
void sortPriority(int a[][3],int temp,int temp2,int temp3)
{
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(a[j][2]<a[i][2])
            {
                // priority sort
                temp=a[i][2];
                a[i][2]=a[j][2];
                a[j][2]=temp;

                // sort burst time
                temp2=a[i][1];
                a[i][1]=a[j][1];
                a[j][1]=temp2;

                // sort index
                temp3=a[i][0];
                a[i][0]=a[j][0];
                a[j][0]=temp3;
            }
        }
    }
}

void sortIndex(int a[][3],int wt[],int tat[],int temp,int temp2,int temp3)
{
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(a[j][0]<a[i][0])
            {
                // priority sort
                temp=a[i][2];
                a[i][2]=a[j][2];
                a[j][2]=temp;

                // sort burst time
                temp2=a[i][1];
                a[i][1]=a[j][1];
                a[j][1]=temp2;

                // sort index
                temp3=a[i][0];
                a[i][0]=a[j][0];
                a[j][0]=temp3;

                int temp4,temp5;

                // sort waiting time accorind to index
                temp4=wt[i];
                wt[i]=wt[j];
                wt[j]=temp4;

                // sort turnaround time accorind to index
                temp5=tat[i];
                tat[i]=tat[j];
                tat[j]=temp5;
            }
        }
    }
}

int main()
{
    int a[5][3],temp,temp2,temp3;

    for(int i=0;i<5;i++)
    {
        cout<<"enter burst time for "<<i+1<<endl;
        cin>>a[i][1];
        cout<<"enter priority of process "<<i+1<<endl;
        cin>>a[i][2];
        a[i][0]=i+1;
    }
    sortPriority(a,temp,temp2,temp3);

    int wt[5];

    // waiting time 
    wt[0]=0;
    for(int i=1;i<5;i++)
    {
        wt[i]=wt[i-1]+a[i-1][1];
    }

    // turnaround time
    int tat[5];
    {
        for(int i=0;i<5;i++)
    {
        tat[i]=wt[i]+a[i][1];
    }
    }

    sortIndex(a,wt,tat,temp,temp2,temp3);
    cout<<"index"<<"\t\t"<<"burst time"<<"\t\t"<<"priority"<<"\t\t"<<"waiting time"<<"\t\t"<<"turnaround time"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i][0]<<"\t\t\t"<<a[i][1]<<"\t\t\t"<<a[i][2]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<endl;
    }
    return 0;
}