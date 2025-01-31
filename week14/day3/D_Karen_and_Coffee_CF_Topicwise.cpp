#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> dif(200002,0);
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        dif[l]++;
        dif[r+1]--;
    }
    vector<int> ans(200002,0);
    for(int i=1;i<=200000;i++){
        dif[i]=dif[i-1]+dif[i];
        ans[i]=ans[i-1]+(dif[i]>=k);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        // cout<<ans[a]<<" "<<ans[b]<<ln;
        cout<<ans[b]-ans[a-1]<<ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
}
/*
they'll provide us N coffee recipes, K as target & Q as queries. 
we'll save the N recipes temperature in difference array. 
And when we'll take the prefix sum of that difference array,
we'll check if the prefix sum value(which is the number of
recipes on that temperature) is atleast K or not. if its >=K 
then the temperature is admissible & we'll increment it's value. 
And we'll do that into another vector ans & same prefix sum way. 
then we'll check Q queries & we'll check the range. 
if it was a normal array we would check as ans[b]-ans[a]+1 but
since its prefix sum so we'll check as ans[b]-ans[a-1] to find
the range. 

testcase: 
3 2 4       N=3, k=2 & Q=4
91 94
92 97
97 99

92 94
93 97
95 96
90 100

90 91 92 93 94 95 96 97 98 99 100
0  1  1  0  0  -1 0  1  -1 0   -1
------------------------------------
0  1  2  2  2  1  1  2  1  1   0       prefix of dif

90 91 92 93 94 95 96 97 98 99 100
--------------------------------------
0  0  1  2  3  3  3  4  4  4   4        ans vector  

dif[91] is 1 which is <k so ans[91]=0
dif[92] is 2 which is ==k so ans[92]=1
dif[93] is 2 which is ==k so ans[93]=ans[92]+1=1+1=2
dif[94] is 2 which is ==k so ans[94]=ans[93]+1=2+1=3
dif[95] is 1 which is <k so ans[95]=ans[94]=3
dif[96] is 1 which is <k so ans[96]=ans[95]=3
dif[97] is 2 which is ==k so ans[97]=ans[96]+1=3+1=4
dif[98] is 1 which is <k so ans[98]=ans[97]=4
dif[99] is 1 which is <k so ans[99]=ans[98]=4
dif[100] is 0 which is <k so ans[100]=ans[99]=4

now 
a=92 & b=94     so ans=ans[94]-ans[92-1]=ans[94]-ans[91]=3-0=3
a=93 & b=97     so ans=ans[97]-ans[93-1]=ans[97]-ans[92]=4-1=3
a=95 & b=96     so ans=ans[96]-ans[95-1]=ans[96]-ans[94]=3-3=0
a=90 & b=100    so ans=ans[100]-ans[90-1]=ans[100]-ans[89]=4-0=4

so final answer: 
3
3
0
4
*/
