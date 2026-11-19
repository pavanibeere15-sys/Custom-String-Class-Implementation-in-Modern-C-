#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
class String
{
        int l;
        public:
        char *s;
        String()
        {
                s=0;
        }
        String(const char *s1)
        {
                l=strlen(s1);
                s=new char[l+1];
                strcpy(s,s1);
        }
        String(const String &s1)
        {
                l=s1.l;
                s=new char[l+1];
                strcpy(s,s1.s);
        }
        ~String()
        {
                if(s!=0)
                delete []s;
        }
        String operator=(String s2)
        {
                if(this== &s2)
                        return *this;
                delete []s;
                l=s2.l;
                s=new char[l+1];
                strcpy(s,s2.s);
                return *this;
        }
        String operator +(String s2)
        {
                String t;
                delete []t.s;
                t.l=l+s2.l;
                t.s=new char[t.l+1];
                strcpy(t.s,s);
                strcat(t.s,s2.s);
                return t;
        }
        char & operator [](int i)
        {
                cout<<"operator []"<<endl;
                return s[i];
        }
        bool operator==(String s2)
        {
                return strcmp(s,s2.s)==0;
        }
        bool operator !=(String s2)
        {
                return strcmp(s,s2.s)!=0;
        }
        bool operator<(String s2)
        {
                return strcmp(s,s2.s)<0;
        }
        bool operator>(String s2)
        {
                return strcmp(s,s2.s)>0;
        }
        bool operator <=(String s2)
        {
                return strcmp(s,s2.s)<=0;
        }
        bool operator >=(String s2)
        {
                return strcmp(s,s2.s)>=0;
        }
        friend ostream &operator <<(ostream &s2,String &s1);
        friend istream &operator >>(istream &in,String &s1);
        friend void strcpy(String &s1,String &s2);
        friend void strncpy(String &s1,String &s2,int n);
        friend void str_rev(String &s1);
        friend void str_upr(String &s1);
        friend void str_lwr(String &s1);
        friend int str_chr(String &s1,char ch);
        friend int strr_chr(String &s1,char ch);
        friend void str_len(String &s1);
        friend void str_str(String &s1,char *s);
        friend void str_cmp(String &s1,String &s2);
        friend void strn_cmp(String &s1,String &s2,int n);
        friend void str_cat(String &s1,String &s2);
        friend void strn_cat(String &s1,String &s2,int n);
};
void strn_cat(String &s1,String &s2,int n)
{
        int i,l;
        l=strlen(s1.s);
        for(i=0,l;i<n &&s1.s[i];i++)
        {
                s1.s[i+l]=s2.s[i];
        }
        s1.s[i+l]='\0';
        cout<<s1.s<<endl;
}
void str_cat(String &s1,String &s2)
{
        int i,j;
        int l=strlen(s1.s);
        for(i=0,l;s1.s[i];i++)
        {
              s1.s[i+l]=s2.s[i];
        }
        s1.s[i+l]='\0';
         cout<<s1.s<<endl;
}
void strn_cmp(String &s1,String &s2,int n)
{
        int i,j;
        for(i=0;i<n && s1.s[i] && s2.s[i];i++)
        {
                if(s1.s[i]!=s2.s[i])
                        break;
        }
                if(s1.s[i]==s2.s[i])
                        cout<<"both the strings are equal upto n:\n";

                        else
                        cout<<"both the strings are not equal upto n:\n";
}
void str_cmp(String &s1,String &s2)
{
        int i,j;
        for(i=0;s1.s[i] && s2.s[i];i++)
        {
                        if(s1.s[i]!=s2.s[i])
                                break;
        }
        if(s1.s[i]==s2.s[i])
                cout<<"both are same:"<<endl;
        else
                cout<<"both are not same:"<<endl;
}
void str_str(String &s1,char *s2)
{
        cout<<"enter the sub string:\n";
        cin>>s2;
        int i,j,f=0;
        for(i=0;s1.s[i];i++)
        {
                if(s1.s[i]==s2[0])
                {
                        for(j=0;s2[j];j++)
                        {
                                if(s1.s[i+j]!=s2[j])
                                        break;
                        }
                        if(s2[j]=='\0')
                        {
                                f=1;
                                break;
                        }
                }
        }
                if(f==1)
                        cout<<"sub string present:"<<endl;
                                                               else
                        cout<<"sub string is not present:"<<endl;
}
void str_len(String &s1)
{
        int len;
        for(len=0;s1.s[len];len++);
        cout<<"length of the string:"<<len<<endl;
}
int strr_chr(String &s1,char ch)
{
        int i,e,f=1;
        cout<<"enter the char:"<<endl;
        cin>>ch;
        for(i=0;s1.s[i];i++)
        {
                if(s1.s[i]==ch)
                {
                        e=i;
                        f=0;
                }
        }
        if(f==1)
        {
                cout<<"char is not present:"<<endl;

        }
        else
                cout<<"char is present"<<endl;
}
int str_chr(String &s1,char ch)
{
        int i;
        cout<<"enter the char:\n";
        cin>>ch;
        for(i=0;s1.s[i];i++)
        {
            if(s1.s[i]==ch)
                    return i;
        }
        return -1;
}
void str_lwr(String &s1)
{
        int i;
        for(i=0;s1.s[i];i++)
        {
                if(s1.s[i]>='A' && s1.s[i]<='Z')
                        s1.s[i]+=32;
        }
        cout<<s1.s<<endl;
}
void str_upr(String &s1)
{
        int i;
        for(i=0;s1.s[i];i++)
        {
                if(s1.s[i]>='a' && s1.s[i]<='z')
                        s1.s[i]-=32;
        }
        cout<<s1.s<<endl;
}
void str_rev(String &s1)
{
        int l,i,j;
        l=strlen(s1.s);
        for(i=0,j=l-1;i<j;i++,j--)
        {
                char t=s1.s[i];
                s1.s[i]=s1.s[j];
                s1.s[j]=t;
        }
          cout<<s1.s<<endl;
}
void strcpy(String &s1,String &s2)
{
        int len,i;
        for(i=0;s1.s[i];i++)
        {
                s2.s[i]=s1.s[i];
        }
        s2.s[i]='\0';
        cout<<s2.s<<endl;
}
void strncpy(String &s1,String &s2,int n)
{
        int i;
        for(i=0;i<n&&s1.s[i];i++)
        {
                s2.s[i]=s1.s[i];
        }
        s2.s[i]='\0';
        s2.l=i;
        cout<<s2.s<<endl;

}
ostream &operator <<(ostream &out,String &s1)
{
        out<<s1.s<<endl;
        return out;
}
istream & operator >>(istream &in,String &s1)
{
        std::string t;
        ifstream fin("DATA");
        if(fin)
        {
          getline(fin,t);
          fin.close();
        }
        else
        {
        in>>t;
        }
        delete []s1.s;
        s1.l=t.length();
        s1.s=new char[s1.l+1];
        ::strcpy(s1.s,t.c_str());
        return in;
}
int main()
{
        String s1("vector"),s;
        String s2("india"),s4;
        String s3=s1+s2;
        cout<<s3;
        cout<<"enter string for >>:\n";
        cin>>s4;
 if(s1==s2)
                cout<<"both are equal"<<endl;
        else if(s1!=s2)
                cout<<"both are not equal"<<endl;

        int n,i,pos,n1,n2;
        char ch;

        cout<<"strcpy function:\n";
        strcpy(s2,s1);

       cout<<"strncpy function for particular print:\n";
        cout<<"enter the n:\n";
        cin>>n;
        strncpy(s1,s2,n);

         cout<<"string upper case:\n";
        str_upr(s1);

        cout<<"string reverse_function:\n";
        str_rev(s1);

        cout<<"string lower case:\n";
        str_lwr(s1);

       cout<<"str_chr function for searching the char:\n";
        i=str_chr(s1,ch);
        if(i==-1)
                cout<<"char is not present:"<<endl;
        else
                cout<<"char is present"<<i<<endl;

        cout<<"strr_chr function:\n";
        strr_chr(s1,ch);

        str_len(s1);

       cout<<"substring function:\n";
        str_str(s1,s2.s);

        cout<<"strcmp function for comparing:\n";
        cout<<"enter the s2:\n";
        cin>>s2;
        str_cmp(s1,s2);

        cout<<"strncmp function for particular n comparision:\n";
        cout<<"enter the n1:\n";
        cin>>n1;
        strn_cmp(s1,s2,n1);

        cout<<"str_cat function:\n";
        str_cat(s1,s2);

        cout<<"strn_cat function:\n";
        cout<<"enter the n2 value:\n";
        cin>>n2;
        strn_cat(s1,s2,n);

}
