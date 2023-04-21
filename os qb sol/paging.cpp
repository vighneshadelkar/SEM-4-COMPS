#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ms,fs,nof,ps,nop;
    cout<<"enter memory size (IN GB)"<<endl;
    cin>>ms;
    // ms=pow(2,(30+ms));

    cout<<"enter frame size (IN MB)"<<endl;
    cin>>fs;

    fs=log2(fs)

    cout<<"enter process size (IN KB)"<<endl;
    cin>>ps;

    ps=log2(ps);

    ms=log2(ms);

    nof=log2(pow(2,30+ms))-log2(pow(2,20+fs));

    nop=log2(pow(2,(20+fs)))-log2(pow(2,10+ps));

    cout<<"no of frames: "<<nof<<endl;
    cout<<"no of pages: "<<nop<<endl;

    cout<<"logical address bits: "<<10+log2(fs)<<endl;

    cout<<"physical address bits: "<<20+log2(ms)<<endl;

    int page_table[nop];

    for(int i=0;i<nop;i++)
    {
        int page_no,frame_no;
        cout<<"enter page no";
        cin>>page_no;
        cout<<"enter frame no";
        cin>>frame_no;

        page_table[page_no]=frame_no;
    }

    cout<<"page no"<<"frame no"<<"valid bit"<<endl;
    for (int i = 0; i < nop; i++)
    {
        cout<<i+1<<"\t"<<page_table[i]<<"\t"<<((page_table[i]?"1":"0"));
    }
    

    cout<<nof;

    // int fs[]
    return 0;
}