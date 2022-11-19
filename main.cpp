#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
string generateRand(int n)
{   vector<int>vec;
    string result;
    srand((unsigned int) time(0));
    for(int i=1;i<=n;i++)
    {
        vec.push_back(i);
        vec[i]=rand()%2;
        result.push_back(vec[i]+'0');
    }
    return result;
}
string lcs(string &a,string &b)
{
    int m=a.size();
    int n=b.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int index=dp[m][n];
    string temp(index+1,'\0');
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            temp[index-1]=a[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    return temp;
}
string longPal(string &str)
{
    string rev=str;
    reverse(rev.begin(),rev.end());
    return lcs(str,rev);
}
string NRZL(string s)
{  string str="";
   for(int i=0;i<s.size();i++)
      {      if(s[i]=='1')
               str=str+"2";
            if(s[i]=='0')
               str=str+"1";
      }
return str;
}
string NRZI(string s)
{
   string str="";
   if(s[0]=='0')
      str=str+'1';
   else if(s[0]=='1')
      str=str+'2';

for(int i=1;i<s.size();i++)
 {  if(s[i]=='1'&&str[i-1]=='2')
      str=str+'1';
   else if(s[i]=='1' && str[i-1]=='1')
      str=str+'2';
   else
      str=str+str[i-1];
 }

   return str;
}
string MANCHESTER(string s)
{  string str="";
   for(int i=0;i<s.size();i++)
        {    if(s[i]=='1')
                { str=str+"21";
                }
            if(s[i]=='0')
                { str=str+"12";
                }
         }

   return str;
}
void DIFMAN(string s)
{
    int n=s.size();

    int a=20,flag=0;
    if(s[0]=='0')
        {   rectangle(a,100,a+20,200);
            outtextab(a+18,25,"0");
            setcolor(0);
            line(a,100,a+20,100);
            line(a,100,a,200);
            setcolor(4);
            line(a+20,100,a+40,100);
            flag=0;
        }
        else if(s[0]=='1')
        {
            rectangle(a,100,a+20,200);
            outtextab(a+18,25,"1");
            setcolor(0);
            line(a,200,a+20,200);
            line(a,100,a,200);
            setcolor(4);
            line(a+20,200,a+40,200);
            flag=1;
        }
        a=a+40;
    for(int i=1;i<n;i++)
    {  if(s[i]=='0')
        {if(flag==0)
        {   rectangle(a,100,a+20,200);
            outtextab(a+18,25,"0");
            setcolor(0);
            line(a,100,a+20,100);
            line(a,100,a,200);
            setcolor(4);
            line(a+20,100,a+40,100);
        }
        else if(flag==1)
        {
            rectangle(a,100,a+20,200);
            outtextab(a+18,25,"1");
            setcolor(0);
            line(a,200,a+20,200);
            line(a,100,a,200);
            setcolor(4);
            line(a+20,200,a+40,200);
        }
        a=a+40;
    }
    else if(s[i]=='1')
    {
        if(flag==1)
        {   rectangle(a,100,+20,200);
            outtextab(a+18,25,"1");
            setcolor(0);
            line(a,100,a+20,100);
            line(a,100,a,200);
            setcolor(4);
            line(a+20,100,a+40,100);
            flag=0;
        }
        else if(flag==0)
        {
            rectangle(a,100,a+20,200);
            outtextab(a+18,25,"1");
            setcolor(0);
            line(a,200,a+20,200);
            line(a,100,a,200);
            setcolor(4);
            line(a+20,200,a+40,200);
            flag=1;
        }
        a=a+40;
    }}
    settextstyle(0,1,2);
    outtextab(0,200,"amplitude");
}
void AMI(string s)
{
    int n=s.size();
    int a=20,flag=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {line(a,100,a+40,100);
        outtextab(a+18,30,"0");
        }
        else if(s[i]=='1')
        {
            if(flag==0)
            {
             rectangle(a,50,a+40,100);
             outtextab(a+18,30,"1");
             setcolor(0);
             line(a,100,a+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(a,100,a+40,150);
            outtextab(a+18,30,"1");
            setcolor(0);
            line(a,100,a+40,100);
            setcolor(4);
            flag=0;
            }
        }
        a=a+40;
    }
    settextstyle(1,1,1);
    outtextab(0,150,"amplitude");
}
void B8ZS(string s,int &flag1,int &a)
{
    int flag;
    int n=s.size();
    for(int i=0;i<n;i++)
    {   if(i==3||i==7)
         {
             if(flag1==0)
                flag=1;
             else
                flag=0;
         }
         if(i==4||i==6)
         {  flag=flag1;
         }
        if(s[i]=='0'&& i!=4 && i!=3 && i!=6 && i!=7)
        {line(a,100,a+40,100);
        outtextab(a+18,30,"0");
        }
        else
        {
            if(flag==0)
            {
             rectangle(a,50,a+40,100);
             outtextab(a+18,30,"0");
             setcolor(0);
             line(a,100,a+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(a,100,a+40,150);
            outtextab(a+18,30,"0");
            setcolor(0);
            line(a,100,a+40,100);
            setcolor(4);
            flag=0;
            }
        }
        a=a+40;
    }
    flag1=flag;
    settextstyle(1,1,1);
    outtextab(0,150,"amplitude");
        }
void AMIB8ZS(string s)
{
    int n=s.size();
    if(n==8)
    {  int a=20,flag=0;
        if(s=="11001111")
        {
          B8ZS(s,flag,a);
        }
        else
            AMI(s);
    }
    else if(n<8)
        AMI(s);
    else
    {
        int a=20,flag=0;
    for(int i=0;i<n;i++)
    { if(s[i]=='0')
        {
            string substring=s.substr(i,8);
            if(substring=="00000000")
            {B8ZS(substring,flag,a);
             i=i+7;
             continue;}


        }
        settextstyle(1,0,1);
        if(s[i]=='0')
        {line(a,100,a+40,100);
        outtextab(a+18,30,"0");
        }
        else if(s[i]=='1')
        {
            if(flag==0)
            {
             rectangle(a,50,a+40,100);
             outtextab(a+18,30,"1");
             setcolor(0);
             line(a,100,a+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(a,100,a+40,150);
            outtextab(a+18,30,"1");
            setcolor(0);
            line(a,100,a+40,100);
            setcolor(4);
            flag=0;
            }
        }
        a=a+40;
    }
    settextstyle(1,1,1);
    outtextab(0,150,"amplitude");
    }
}
void HDB3(string s,int &flag1,int &a,int sum)
{
    int flag,n;
    n=s.size();
    for(int i=0;i<n;i++)
    {   if(sum%2==0)
        {if(i==0||i==3)
         {
             flag=flag1;
         }}
         else
         {if(i==3)
           {if(flag1==0)
             flag=1;
             else
                flag=0;
         }}
        if(s[i]=='0'&& i!=3 && i!=0 ||(i==0 && (sum%2!=0 )))
        {line(a,100,a+40,100);
        outtextab(a+18,30,"0");
        }
        else
        {
            if(flag==0)
            {
             rectangle(a,50,a+40,100);
             outtextab(a+18,30,"0");
             setcolor(0);
             line(a,100,a+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(a,100,a+40,150);
            outtextab(a+18,30,"0");
            setcolor(0);
            line(a,100,a+40,100);
            setcolor(4);
            flag=0;
            }
        }
            a=a+40;
    }
    flag1=flag;
    settextstyle(1,1,1);
    outtextab(0,150,"amplitude");

}
void AMIHDB3(string s)
{
    int n=s.size();
        int a=20,flag=0,sum=0;
    for(int i=0;i<n;i++)
    {    if(s[i]=='0')
        {
            string sub=s.substr(i,4);
            if(sub=="0000")
                {HDB3(sub,flag,a,sum);
                 i=i+3;
                 continue;
                }
        }
        settextstyle(1,0,1);
        if(s[i]=='0')
        {line(a,100,a+40,100);
        outtextab(a+18,30,"0");
        }
        else if(s[i]=='1')
        {   sum++;
            if(flag==0)
            {
             rectangle(a,50,a+40,100);
             outtextab(a+18,30,"1");
             setcolor(0);
             line(a,100,a+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(a,100,a+40,150);
            outtextab(a+18,30,"1");
            setcolor(0);
            line(a,100,a+40,100);
            setcolor(4);
            flag=0;
            }
        }
        a=a+40;
    }
    settextstyle(1,1,1);
    outtextab(0,150,"amplitude");
}
int main()
{
    int gd=DETECT,gm,choice,scramb;
    char ch;
    initgraph(&gd,&gm,(char*)"");
    setcolor(4);
    setfillstyle(2,5);
    settextstyle(1,0,1);
    string s,s1;
    s=generateRand(15);
    s1=longPal(s);
    cout<<s<<" "<<s1<<"\n";
    cout<<"Enter Line encoding scheme-\n1)NRZ-L\n2)NRZ-I\n3)MANCHESTER\n4)DIFFERENTIAL MANCHESTER\n5)AMI";
    cin>>choice;
    if(choice==1)
    {
        NRZL(s1);
    }
    else if(choice==2)
    {
        NRZI(s1);
    }
    else if(choice==3)
    {
        MANCHESTER(s1);
    }
    else if(choice==4)
    {
        DIFMAN(s1);
    }
    else if(choice==5)
    {
        cout<<"Require Scrambling (Y/N)?";
        cin>>ch;
        if(ch=='Y')
        {
            cout<<"Type of scrambling:\n1)B8ZS\n2)HDB3";
            cin>>scramb;
            if(scramb==1)
               AMIB8ZS(s1);
            else
            {
              AMIHDB3(s1);
            }

        }
        else
        {
          AMI(s1);
        }
    }

    getch();
    closegraph();
}
