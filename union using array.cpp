#include<bits/stdc++.h>
#include<string.h>
int main()
{
    char a[20],b[20],s[20],g[20];
    int l1,l2,f=0,n;
    cout<<"Enter A string";
    cin>>a;
    cout<<"enter b string";
    cin>>b;
    l1=strlen(a);
    l2=strlen(b);
    int i,j,p=0,q=0;
    cout<<"INTERSECTION"<<endl;
    for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;i++)
        {
            if(a[i]==b[j])
            {
                cout<<a[i]<<" ";
            }
        }
    }
    while(a[p]!='\0')
    {
        g[p]=a[p];
        p++;
    }
    for(i=0;i<l2;i++)
    {
        f=0;
        for(j=0;j<l1;j++)
        {
            if(b[i]==a[j])
            {
                f=1;
            }
        }
        if(f==0)
        {
            g[p]=b[i];
            p++;
        }
    }
    cout<<endl<<"union"<<endl;
    for(i=0;i<p;i++)
    {
        cout<<g[i]<<" ";
    }
    cout<<endl<<"difference";
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<a[i]<<"and"<<b[i];
        }
    }

}
