#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(s[i]=='0') v.push_back(i);
    }
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            if(ans==-1 || v.size()==0) ans=-1;
            else{
                // cout<<v.back()<<ln;
                ans+= (i-v.back());
                s[v.back()]='1';
                v.pop_back();
                // cout<<v.back()<<ln;
            }
        }
        else if(v.size()!=0 && v.back()==i){
            v.pop_back();
        }
        cout<<ans<<" ";
    }
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
OBSERVATION:
for all 2^i (i from 1 to N), we need to make sure all bits after
ith are zeros. Otherwise there will be reminder when we'll try
to do divisible operation on that number. 

now we are saving all 0's index number on a vector. 
then we'll start from string's back because we do bitwise operations
from 8 4 2 1 <--- this way. 
And we'll do operations when we'll find 1 in a string position. 
so if(s[i]=='1'):---
    1) we'll check if there is any zero left so that we can swap. 
    if there is no zero left then for this index ans=-1 AND since
    previous index's ans is -1 means all from that moment will 
    get -1 as ans because there is no zero left. 
    2) otherwise we'll add ('1' index - closest 0's index) to 
    answer. Why adding to ans? {because problem statement says for
    each i, we need to do independent operation. So suppose we
    need to change 3rd index, then we have to also swap 4th to Nth
    index & make them zeros. Since Nth to 4th's swap count automatically
    including in 3rd index, so we are adding each time we calculate
    the swap operation.} then we'll make that closest 0's index
    to 1. And pop it's index from vector. 
else if(v.size()!=0 && v.back()==i):---
    means s[i]=='0' & if that ith index is also in vector then
    we'll simply remove the index from the vector. Also since 
    there is no swap operation happen, there will be no contribution
    in ans. 

testcase: 
5
10101
v=[1 3]
ans=0
i=4 ----- s[i]=1 so ans=0+(4-3)=1 & s[3]=1 now v=[1] ans=1
10110
i=3 ----- s[i]=1 so ans=1+(3-1)=3 & s[1]=1 now v=[]  ans=1 3 
11100
i=2 ----- s[i]=1 but v is empty so ans=1 3 -1
11100
i=1 ----- s[i]=1 but v is empty so ans=1 3 -1 -1
11100
i=0 ----- s[i]=1 but v is empty so ans=1 3 -1 -1 -1
11100
*/