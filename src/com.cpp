#include"function.h"
#include <math.h>
#include<iostream>

string com(string a)
{   
    if(strstr(a.c_str(),"sqrt")!=NULL|strstr(a.c_str(),"len")!=NULL|strstr(a.c_str(),"sca")!=NULL)
    {
        ;
    }
    else
    {
        for(int i=0;i<a.length();i++)
        {
            if(isalpha(a[i]))
            {
                return "Please input a number";
            }
        }
    }
    int j=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='(')
        {
            int s=1;
            for(int i1=i+1;i1<a.length();i1++)
            {
                if(a[i1]=='(')
                {
                    s++;
                    
                }
                else if(a[i1]==')')
                {
                    s--;
                }
                if(s==0)
                {
                    j=i1;
                    break;
                }
            }
           
            string t=a.substr(i+1,j-i-1);
            t=com(t);
            a.erase(i,j-i+1);
            a.insert(i,t);
            a=com(a);
            break;

        }
        else if(a[i]=='s'&&a[i+1]=='q')
        {
            int s=1;
            for(int i1=i+5;i1<a.length();i1++)
            {
                if(a[i1]=='(')
                {
                    s++;
                }
                else if(a[i1]==')')
                {
                    s--;
                }
                if(s==0)
                {
                    j=i1;
                    break;
                }
            }
            string t=a.substr(i+5,j-i-5);
            a.erase(i,j-i+1);
            double ina=atof(t.c_str());
            double inb=sqrt(ina);
            a.insert(i,to_string(inb));
            a=com(a);
            break;
        }
        else if(a[i]=='c')
        {
            int s=1;
            for(int i1=i+5;i1<a.length();i1++)
            {
                if(a[i1]=='(')
                {
                    s++;
                }
                else if(a[i1]==')')
                {
                    s--;
                }
                if(s==0)
                {
                    j=i1;
                    break;
                }
            }
            string t=a.substr(i+5,j-i-5);
            a.erase(i-1,j-i+1);
            t=com(t);
            int sc=0;
            for(int ll=0;ll<t.length();ll++)
            {
                if(t[ll]=='.')
                {
                    sc=t.length()-1-ll;
                    break;
                }
            }
            a=to_string(sc);
            break;
        }
        else if(a[i]=='n')
        {
            int s=1;
            for(int i1=i+5;i1<a.length();i1++)
            {
                if(a[i1]=='(')
                {
                    s++;
                }
                else if(a[i1]==')')
                {
                    s--;
                }
                if(s==0)
                {
                    j=i1;
                    break;
                }
            }
            string t=a.substr(i+5,j-i-5);
            a.erase(i-2,j-i+1);
            t=com(t);
            if(t[0]=='0'&t[1]=='.')
            {
                a=to_string(t.length()-2);
                break;
            }
            else
            {
                int sc=t.length();
                for(int ll=0;ll<t.length();ll++)
                {
                    if(t[ll]=='.')
                    {
                        sc=t.length()-1;
                        break;
                    }
               
                }
            
                a=to_string(sc);
                break;
            }
        }
        else if(a[i]=='^')
        {
            bool ll=false;
            for(int i1=i+1;i1<a.length();i1++)
            {
                if(a[i1]=='(')
                {
                   ll=true;
                }
            }
            if(ll)
            {
                continue;
            }
            int b1=-1;
            int b2=a.length();
            int ii=0;
            int iii=0;
            for(int j=i-1;j>=0;j--)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b1=j;
                    break;
                }
            }
            string aa;
            aa.resize(i-1-b1);
            for(int j=0;j<aa.length();j++)
            {
                aa[j]=a[b1+1+j];
            }
            for(int j=i+1;j<a.length();j++)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b2=j;
                    break;
                }
            }
            string bb;
            bb.resize(b2-i-1);
            for(int j=0;j<bb.length();j++)
            {
                bb[j]=a[i+1+j];
            }
            double ina=atof(aa.c_str());
            double inb=atof(bb.c_str());
            double inc=pow(ina,inb);
            a.erase(b1+1,b2-b1-1);
            a.insert(b1+1,to_string(inc));
            a=com(a);
            break;
        }
        else if(a[i]=='*')
        {
            bool ll=false;
            for(int i1=i+1;i1<a.length();i1++)
            {
                if(a[i1]=='('|a[i1]=='^')
                {
                   ll=true;
                }
            }
            if(ll)
            {
                continue;

            }
            int b1=-1;
            int b2=a.length();
            int ii=0;
            int iii=0;
            for(int j=i-1;j>=0;j--)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b1=j;
                    break;
                }
               
            }
            string aa;
            aa.resize(i-1-b1);
            for(int j=0;j<aa.length();j++)
            {
                aa[j]=a[b1+1+j];
            }
            for(int j=i+1;j<a.length();j++)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b2=j;
                    break;
                }
            }
            string bb;
            bb.resize(b2-i-1);
            for(int j=0;j<bb.length();j++)
            {
                bb[j]=a[i+1+j];
            }
            double ina=atof(aa.c_str());
            double inb=atof(bb.c_str());
            double inc=ina*inb;
            a.erase(b1+1,b2-b1-1);
            a.insert(b1+1,to_string(inc));
            a=com(a);
            break;
        }
        else if(a[i]=='%')
        {
            bool ll=false;
            for(int i1=i+1;i1<a.length();i1++)
            {
                if(a[i1]=='('|a[i1]=='^')
                {
                   ll=true;
                }
            }
            
            if(ll)
            {
                continue;
            }
            int b1=-1;
            int b2=a.length();
            int ii=0;
            int iii=0;
            for(int j=i-1;j>=0;j--)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b1=j;
                    break;
                }
               
            }
            string aa;
            aa.resize(i-1-b1);
            for(int j=0;j<aa.length();j++)
            {
                aa[j]=a[b1+1+j];
            }
            for(int j=i+1;j<a.length();j++)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b2=j;
                    break;
                }
            }
            string bb;
            bb.resize(b2-i-1);
            for(int j=0;j<bb.length();j++)
            {
                bb[j]=a[i+1+j];
            }
            int ina=atoi(aa.c_str());
            int inb=atoi(bb.c_str());
            int inc=ina%inb;
            a.erase(b1+1,b2-b1-1);
            a.insert(b1+1,to_string(inc));
            a=com(a);
            break;
            
        }
        else if(a[i]=='/')
        {
            bool ll=false;
            for(int i1=i+1;i1<a.length();i1++)
            {
                if(a[i1]=='('|a[i1]=='^')
                {
                   ll=true;
                }
            }
            int b1=-1;
            int b2=a.length();
            int ii=0;
            int iii=0;
            for(int j=i-1;j>=0;j--)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b1=j;
                    break;
                }
               
            }
            string aa;
            aa.resize(i-1-b1);
            for(int j=0;j<aa.length();j++)
            {
                aa[j]=a[b1+1+j];
            }

            for(int j=i+1;j<a.length();j++)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b2=j;
                    break;
                }
            }
            string bb;
            bb.resize(b2-i-1);
            for(int j=0;j<bb.length();j++)
            {
                bb[j]=a[i+1+j];
            }
            double ina=atof(aa.c_str());
            double inb=atof(bb.c_str());
            double inc=ina/inb;
            a.erase(b1+1,b2-b1-1);
            a.insert(b1+1,to_string(inc));
            a=com(a);
            break;
        }
        else if(a[i]=='+')
        {
            bool ll=false;
            bool ht=false;
            for(int i1=i+1;i1<a.length();i1++)
            {
                if(a[i1]=='*'|a[i1]=='/'|a[i1]=='('|a[i1]=='^'|a[i1]=='%')
                {
                    ll=true;
                }
            }
            
            if(ll)
            {
                continue;
            }
            int b1=-1;
            int b2=a.length();
            int ii=0;
            int iii=0;
            for(int j=i-1;j>=0;j--)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b1=j;
                    break;
                }
               
            }
            string aa;
            aa.resize(i-1-b1);
            int hp1=i-1-b1+1;
            for(int j=0;j<aa.length();j++)
            {
                aa[j]=a[b1+1+j];
                if(aa[j]=='.')
                {
                ht=true;
                hp1=j+1;
                }
            }
            for(int j=i+1;j<a.length();j++)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b2=j;
                    break;
                }
            }
             
            string bb;
            bb.resize(b2-i-1);
            int hp2=b2-i-1+1;
            for(int j=0;j<bb.length();j++)
            {
                bb[j]=a[i+1+j];
                if(bb[j]=='.')
                {
                    ht=true;
                    hp2=j+1;
                }
              
            }
            if(ht)
            {
                string ss=add(aa,bb,hp1,hp2);
                a.erase(b1+1,b2-b1-1);
                a.insert(b1+1,ss);
                a=com(a);
                break;
            }
            int ina=atoi(aa.c_str());
            int inb=atoi(bb.c_str());
            int inc=ina+inb;
            a.erase(b1+1,b2-b1-1);
            a.insert(b1+1,to_string(inc));
            a=com(a);
            break;
        }
        else if(a[i]=='-')
        {
            if(i==0)
            {
                continue;
            }
            bool ll=false;
            for(int i1=i+1;i1<a.length();i1++)
            {
                if(a[i1]=='*'|a[i1]=='/'|a[i1]=='('|a[i1]=='^'|a[i1]=='%')
                {
                   ll=true;
                }
            }
            if(ll)
            {
                continue;
            }
            int b1=-1;
            int b2=a.length();
            int ii=0;
            int iii=0;
            for(int j=i-1;j>=0;j--)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b1=j;
                    break;
                }
               
            }
            string aa;
            aa.resize(i-1-b1);
            for(int j=0;j<aa.length();j++)
            {
                aa[j]=a[b1+1+j];
            }

            for(int j=i+1;j<a.length();j++)
            {
                if((a[j]<48|a[j]>57)&a[j]!='.')
                {
                    b2=j;
                    break;
                }
            }
            string bb;
            bb.resize(b2-i-1);
            for(int j=0;j<bb.length();j++)
            {
                bb[j]=a[i+1+j];
            }
            double ina=atof(aa.c_str());
            double inb=atof(bb.c_str());
            double inc=ina-inb;
            a.erase(b1+1,b2-b1-1);
            a.insert(b1+1,to_string(inc));
            a=com(a);
            break;
        }
    }
    
    return a;
}