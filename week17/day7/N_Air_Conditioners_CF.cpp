#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) v[i]=INT_MAX;
    vector<int> idx;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        idx.push_back(x-1);
    }
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        v[idx[i]]=x;
    }
    ll mn=INT_MAX;
    for(int i=0;i<n;i++){       //start to end
        mn=min(mn+1,v[i]);
        v[i]=mn;
    }
    for(int i=n-1;i>=0;i--){    //end to start
        mn=min(mn+1,v[i]);
        v[i]=mn;
    }
    for(int x:v) cout<<x<<" ";
    cout<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
they are giving us the cell numbers, ac numbers
then the ac's positions 
then ac temperatures

using testcase 1 as example to understande the process of solving
this problem:- 
6 2
2 5
14 16

now lets keep all cell's temperature as INT_MAX
so v=[ INT_MAX INT_MAX INT_MAX INT_MAX INT_MAX INT_MAX ]
since 0-based indexing so ac index=[2-1 5-1]=[ 1 4 ]
now putting ac temperature on their respective index. 

we'll initially start this from start to end---
so v=[ INT_MAX 14 INT_MAX INT_MAX 16 INT_MAX ]
          0    1     2       3    4     5
now mn=INT_MAX so mn=min(INT_MAX+1, v[0])=INT_MAX so v[0]=INT_MAX
so v=[ INT_MAX 14 INT_MAX INT_MAX 16 INT_MAX ]
          0    1     2       3    4     5

mn=INT_MAX so mn=min(INT_MAX+1,v[1])=14 so v[1]=14
so v=[ INT_MAX 14 INT_MAX INT_MAX 16 INT_MAX ]
          0    1     2       3    4     5

mn=14 so mn=min(14+1,v[2])=15 so v[2]=15
so v=[ INT_MAX 14 15 INT_MAX 16 INT_MAX ]
          0    1  2     3    4     5

mn=15 so mn=min(15+1,v[3])=16 so v[3]=16
so v=[ INT_MAX 14 15 16 16 INT_MAX ]
          0    1  2   3  4     5

mn=16 so mn=min(16+1,v[4])=16 so v[4]=16
so v=[ INT_MAX 14 15 16 16 INT_MAX ]
          0    1  2   3  4     5

mn=16 so mn=min(16+1,v[5])=17 so v[5]=17
so v=[ INT_MAX 14 15 16 16 17 ]
          0    1  2   3  4  5

now we'll start the from end to start---
mn=17 so mn=min(16+1,v[5])=17 so v[5]=17
so v=[ INT_MAX 14 15 16 16 17 ]
          0    1  2   3  4  5

mn=17 so mn=min(17+1,v[4])=16 so v[4]=16
so v=[ INT_MAX 14 15 16 16 17 ]
          0    1  2   3  4  5

mn=16 so mn=min(16+1,v[3])=16 so v[3]=16
so v=[ INT_MAX 14 15 16 16 17 ]
          0    1  2   3  4  5

mn=16 so mn=min(16+1,v[2])=15 so v[2]=15
so v=[ INT_MAX 14 15 16 16 17 ]
          0    1  2   3  4  5

mn=15 so mn=min(15+1,v[1])=14 so v[1]=14
so v=[ INT_MAX 14 15 16 16 17 ]
          0    1  2   3  4  5

mn=14 so mn=min(14+1,v[0])=15 so v[0]=15
so v=[ 15 14 15 16 16 17 ]
        0 1  2   3  4  5

so this is how the final vector will create. This is a logical
implementation problem. 
*/