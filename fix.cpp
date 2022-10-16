#include"function.h"

#include <iostream>
string fix(string a)
{
    bool p=false;
        for(int i=0;i<a.length();i++)
        {
            if(a[a.length()-1-i]=='.')
            {
                p=true;
                break;
            }
        }
        if(p)
        {
            for(int i=0;i<a.length();i++)
            {
                if(a[a.length()-1-i]!='0')
                {
                    if(a[a.length()-1-i]=='.')
                    {
                        a=a.substr(0,a.length()-1-i);
                        break;
                    }
                    else
                    {
                    a=a.substr(0,a.length()-i);
                    break;
                    }

                }
            }
        }
    return a;
}