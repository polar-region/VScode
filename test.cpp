#include<bits/stdc++.h>
using namespace std;

int strHash(string s){
    reverse(s.begin(),s.end());
    int sum =0;
    for(int i=0;i<3;i++){
        sum+=(s[i]-'A')*pow(32,i);
    }
    return sum;
}

int main()
{
    int Hash[1009]; //记录原始数据在hash表中
    int a[500]; // 记录原始数据
    int N,P,i,j,key;
    int pos;
    string str;
    while((scanf("%d%d",&N,&P))!=EOF)
    {
        for(i = 0; i < P;i++)
        {
            Hash[i] = -1;//一组无重复数据的正整数,没有占去的位置用-1表示
        }
        for(i=0;i<N;i++)//输入数据
        {
            cin>>str;
            a[i] = strHash(str);
            pos = a[i] % P; // hash函数
            if(Hash[ pos ] == -1)
            {
                Hash[ pos ] = a[i];
            }
            else
            {
                for(j=1;j <(int)sqrt(P);j++)
                {
                    pos = (a[i]+j*j)%P;//先向后探测
                    if(Hash[pos] == -1)
                    {
                        Hash[pos] = a[i];
                        break;
                    }
                    pos = (a[i]-j*j)%P;//向前探测
                    if(Hash[pos] == -1)
                    {
                        Hash[pos] = a[i];
                        break;
                    }
                }
            }
        }
        for(i=0;i<N;i++)
        {
            pos = a[i] % P;
            if(Hash[pos] == a[i])
            {
                if(i == N-1)
                    printf("%d\n",pos);
                else
                    printf("%d ",pos);
            }
 
            else
            {
                for(j = 1;j<(int)sqrt(P);j++)
                {
                    pos = (a[i]+j*j)%P;
                    if(Hash[pos] == a[i])
                    {
                        if(i == N-1)
                            printf("%d\n",pos);
                        else
                            printf("%d ",pos);
                        break;
                    }
                    pos = (a[i]-j*j)%P;
                    if(Hash[pos] == a[i])
                    {
                        if(i == N-1)
                            printf("%d\n",pos);
                        else
                            printf("%d ",pos);
                        break;
                    }
                }
            }
        }
 
    }
    return 0;
}