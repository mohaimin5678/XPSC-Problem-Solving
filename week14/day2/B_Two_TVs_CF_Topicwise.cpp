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
    map<int,int> dif;
    while(n--){
        int l,r;
        cin>>l>>r;
        dif[l]++;
        dif[r+1]--;
    }
    ll sum=0;
    // for(auto [key,value]:dif){
    //     cout<<key<<" ";
    // }
    // cout<<ln;
    for(auto [key,value]:dif){
        sum+=value;
        if(sum>2){
            cno;
            return;
        }
    }
    cyes;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
}
/*
they'll provide us queries of N tv shows where l=starting &
r=ending time. Now we have 2 TVs, can we watch all shows in these
2 TVs? (suppose a show end at 4 & 2nd show starts at 4 then 2nd 
show can't be play on same TV because 1st show needs to be end at
4)

so our observation: In every min, how many shows are running?
if in a minute, there is 1 show running then we can watch it on
any TV. 
if in a minute, there is 2 shows running then we can watch it on 
2 TVs. 
if in a minute, there is 3/3+ shows running then we can't watch
all of them in 2 TVs. 

so using difference array we can solve this. 
from each query, we'll do dif[l]++ & dif[r+1]-- then we'll do
prefix sum after all queries end. 
if any prefix sum value goes >2 then answer is no. else yes. 

testcase: 
3 
1 2
2 3
4 5
             1 2  3  4 5  6
initial dif=[0 0  0  0 0  0]
after {1 2}=[1 0 -1  0 0  0]
after {2 3}=[1 1 -1 -1 0  0]
after {4 5}=[1 1 -1  0 0 -1]
            ----------------
prefix sum = 1 2  1  1 1  0

here only 2nd min has 2 shows running & we can watch them on 2 
TVs. And since there is no min exists which has 3/3+ shows running
so final answer is YES. 

NOTE: since l,r constraint is 10^9 so we can't use vector here. 
     thats why we're using map. it will work also because when
     we'll traverse, it will only calculate those numbers which
     will make an impact on the prefix sum. If we see the given
     example, in 1 2 3 4 5 6... only 1 2 3 4 6 are changing the
     prefix sum cause operations was on them. 5 had no operation
     so it didn't do anything on the prefix sum & it won't be on
     map too.
*/
