#include"function.h"
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    for(int i=1;i>=0;i++)
    {
        string a;
        string b[10];
        string c;
        getline(cin,a);
        if(strstr(a.c_str(),"=")!=NULL)
        {
            b[0]=a;
            int le=1;
            char lee[10];
            string lle[10];
            for(int i3=1;i3<10;i3++)
            {
                string tt;  
                getline(cin,tt);
                if(strstr(tt.c_str(),"=")==NULL)
                {
                    c=tt;
                    break;
                }
                b[i3]=tt;
                le=i3+1;
            }
            for(int i4=0;i4<le;i4++)
            {
                lee[i4]=b[i4][0];
                lle[i4]=b[i4].substr(2,b[i4].length()-2);
            }
            for(int ii=0;ii<c.length();ii++)
            {
                for(int ii1=0;ii1<le;ii1++)
                {
                    if(c[ii]==lee[ii1])
                    {
                    c.erase(ii,1);
                    c.insert(ii,lle[ii1]);
                    }
       
        
                }
            }
            a=com(c);
        }
        else if(a=="quit")
        {
            break;
        }
        else{a=com(a);}
        if(strstr(a.c_str(),"Please"))
        {
            ;
        }
        else
        {
            a=fix(a);
        }
        cout<<a<<endl;
    }
}
   
