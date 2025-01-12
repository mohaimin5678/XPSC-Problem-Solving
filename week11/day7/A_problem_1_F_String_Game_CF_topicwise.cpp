#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t,s;
    cin>>t>>s;
    int n=t.size(),m=s.size();
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]--;     //to make it 0 based index
    }
    bool flag=false;
    auto check=[&](int del){
        vector<bool> bad(n);
        for(int i=0;i<=del;i++){
            bad[v[i]]=true;
        }

        int j=0;
        for(int i=0;i<n;i++){
            if(!bad[i] && t[i]==s[j]){
                j++;
            }
            if(j==m){
                flag=true;
                return true;
            }
        }
        return false;
    };
    int l=0,r=n-1,mid,ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<(flag ? ans+1 : ans)<<endl;
    return 0;
}
/*
problem: 2ta string diye dibe & 1ta vector. 
T string theke vector er index wise character delete kore kore
S string banaite hobe. Notice korte hobe jate beshi character
delete na hoye jay jate pore ar S build kora impossible hoye jay. 
Target hocche maximum koto character delete kore S build kora jabe
sheta find out kora. 

now: 
vector er index gula -1 kore 0 based indexing e niye ashlam. 

given testcase: 
ababcba
abb
5 3 4 1 7 6 2
4 2 3 0 6 5 1   -> 0 based indexing
0 1 2 3 4 5 6   -> operations

now l=0,r=6 so mid=3
inside check funtion with del=3: 
i=0 so v[i]=4 & bad[v[i]]=bad[4]=true.     ababcba
                                               t
i=1 so v[i]=2 & bad[v[i]]=bad[2]=true.     ababcba
                                             t t
i=2 so v[i]=3 & bad[v[i]]=bad[3]=true.     ababcba
                                             ttt
i=3 so v[i]=0 & bad[v[i]]=bad[0]=true.     ababcba
                                           t ttt
so after operations the string left is bba
from which we can't make S. So return false. 

now l=0,r=2 so mid=1
inside check funtion with del=1:
i=0 so v[i]=4 & bad[v[i]]=bad[4]=true.     ababcba
                                               t
i=1 so v[i]=2 & bad[v[i]]=bad[2]=true.     ababcba
                                             t t
so after operations the string left is abbba
from which we can make S. So returm true. And made flag=true. 
ans=1

now l=2,r=2 so mid=2
inside check funtion with del=2:
i=0 so v[i]=4 & bad[v[i]]=bad[4]=true.     ababcba
                                               t
i=1 so v[i]=2 & bad[v[i]]=bad[2]=true.     ababcba
                                             t t
i=2 so v[i]=3 & bad[v[i]]=bad[3]=true.     ababcba
                                             ttt
so after operations the string left is abba
from which we can make S. So returm true. And flag=true already. 
ans=2

now l=2, r=1 so loop break;
now ans=2 for 0 based index. 
they want 1 based index answer so ans=3;

*/