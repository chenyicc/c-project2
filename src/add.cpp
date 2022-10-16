#include"function.h"

using namespace std;
string  add(string a,string b,int hp1,int hp2)
{
    int l=max(int(a.length())-hp1,int(b.length())-hp2);
    int aa[l];
    int bb[l];
    int c[l];
    int ll=max(hp1-1,hp2-1)+1;
    int aaa[ll];
    int bbb[ll];
    int cc[ll];
    for(int i=0;i<l;i++)
    {
        aa[i]=0;
    }
    for(int i=0;i<l;i++)
    {
        bb[i]=0;
    }
    for(int i=0;i<l;i++)
    {
        c[i]=0;
    }
    for(int i=0;i<ll;i++)
    {
        aaa[i]=0;
    }
    for(int i=0;i<ll;i++)
    {
        bbb[i]=0;
    }
    for(int i=0;i<ll;i++)
    {
        cc[i]=0;
    }
    for(int i=0;i<l;i++)
    {
        if(hp1+i<a.length())
        {
            aa[i]=a[hp1+i]-48;
        }
    }
    for(int i=0;i<l;i++)
    {
        if(hp2+i<b.length())
        {
            bb[i]=b[hp2+i]-48;
        }
    }
    for(int i=0;i<ll;i++)
    {
        if(hp1-2-i>=0)
        {
            aaa[ll-1-i]=a[hp1-2-i]-48;
        }
    }
    for(int i=0;i<ll;i++)
    {
        if(hp2-2-i>=0)
        {
            bbb[ll-1-i]=b[hp2-2-i]-48;
        }
    }
    int j=0;
    for(int i=0;i<l;i++)
    {
        if(aa[l-1-i]+bb[l-1-i]+j<10)
        {
            c[l-1-i]=aa[l-1-i]+bb[l-1-i]+j;
            j=0;
        }
        else
        {
           
            c[l-1-i]=aa[l-1-i]+bb[l-1-i]+j-10;
            j=1;
            
        }
    }
    
    
    for(int i=0;i<ll;i++)
    {
        if(aaa[ll-1-i]+bbb[ll-1-i]+j<10)
        {
            cc[ll-1-i]=aaa[ll-1-i]+bbb[ll-1-i]+j;
            j=0;
        }
        else
        {
            cc[ll-1-i]=aaa[ll-1-i]+bbb[ll-1-i]+j-10;
            j=1;
        }
    }
    char pb[l+1];
    for(int i=0;i<l;i++)
    {
        pb[i]=c[i]+48;
    }
    pb[l]='\0';
    string pbs=pb;
    if(cc[0]!=0)
    {
        char r[ll+1];
        for(int i=0;i<ll;i++)
        {
            r[i]=cc[i]+48;
        }  
            r[ll]='\0';
            string rr=r;
        return rr+"."+pbs;
    }
    else
    {
        char r[ll];
        for(int i=0;i<ll-1;i++)
        {
            r[i]=cc[i+1]+48;
        }  
            r[ll-1]='\0';
            string rr=r;
            return rr+"."+pbs;

    }
}