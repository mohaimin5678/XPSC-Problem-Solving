#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,left,right;
        cin>>n>>left>>right;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        // for(int x:v) cout<<x<<" ";
        // cout<<endl;
        ll ans=0;
        for(int i=0;i<n;i++){
            auto it1 = lower_bound(v.begin()+i+1,v.end(),left-v[i]) - v.begin();
            auto it2 = upper_bound(v.begin()+i+1,v.end(),right-v[i]) - v.begin();
            // cout<<"for "<<v[i]<<" "<<v[it1]<<"---"<<v[it2]<<"-->  ";
            // cout << it1 << " " << it2 << endl;
            int p=it2-it1;
            ans+=p;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
using the upper & lower bound here. 
we'll sort the vector & for every i, we'll use the lower
bound of (left-v[i]) from i+1 to end & check which index fill 
up the condition. ans1
then we'll use upper bound of (right-v[i]) from i+1 to end &
check which index fill up the condition. ans2 
then we'll subtruct the ans2-ans1 & add the value to answer. 
testcase explanation: 
5 5 8
5 1 2 4 3
sorting the vector: 1 2 3 4 5
           idx->    0 1 2 3 4
for 1, lower(from index 1 to end & target=5-1=4) result=3
    upper(from index 1 to end & target=8-1=7) result=5
so the number of pairs can be possible is 5-3=2 (1,4) & (1,5)
ans=2

for 2, lower(from index 2 to end & target=5-2=3) result=2
    upper(from index 2 to end & target=8-2=6) result=5
so the number of pairs can be possible is 5-2=3 (2,3),(2,4)&(2,5)
ans=2+3=5

for 3, lower(from index 3 to end & target=5-3=2) result=3
    upper(from index 3 to end & target=8-3=5) result=5
so the number of pairs can be possible is 5-3=2 (3,4) & (3,5)
ans=5+2=7

for 4, lower(from index 4 to end & target=5-4=1) result=4
    upper(from index 4 to end & target=8-4=4) result=4
so there will be no pair possible since 4+5>8. 
ans=7+0=7

for 5, lower(from index 5 to end & target=5-5=0) result=5
    upper(from index 5 to end & target=8-5=3) result=5
so there will be no pair possible. 
ans=7+0=7
final answer 7
*/