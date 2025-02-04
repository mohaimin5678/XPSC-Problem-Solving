#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace __gnu_pbds;
using namespace std;
//for set
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//for multiset
// template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void mohaimin(){
    int n;
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pq.push({x,y});
    }
    vector<int> v;
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        v.push_back(x.second);
        // cout<<x.first<<" "<<x.second<<ln;
    }
    // for(int x:v) cout<<x<<" ";
    // cout<<ln;
    pbds<int> p;
    ll gret=0;
    for(int i=n-1;i>=0;i--){
        gret+=p.order_of_key(v[i]);
        p.insert(v[i]);
    }
    cout<<gret<<ln;
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
They'll provide us N amount of distinct starting & ending points. 
We need to calculate how many meetups will occur among N people. 
if someone's endpoint is less than another person's starting point, then
we'll never meet each other. So lets take all pairs in ascending order
based on their starting point. 
then we'll put all ending points into a vector & start checking from
behind into a pbds that how many ending points are lower than current
ending points because to reach this ending point, the person will pass
through those lower ending point & there he'll meet those persons. 
so we'll calculate them. 

testcase: 
6
2 6
3 9
4 5
1 8
7 10
-2 100

lets sort those pairs based on their starting point:- 
-2 100
1 8
2 6 
3 9
4 5
7 10

as we can see {2 6} will never meet {7 10} because ending point is lower
than 2nd pair's starting point. This is why we did the sorting. 

now v=[100 8 6 9 5 10]
doing inversion count using p.order_of_key() will give us the answer. 
v=[100 8 6 9 5 10]
                i      p.order_of_key(10)=0  ans=0
             i         p.order_of_key(5)=0   ans=0
           i           p.order_of_key(9)=1   ans=1
         i             p.order_of_key(6)=1   ans=1+1=2
       i               p.order_of_key(8)=2   ans=2+2=4
    i                  p.order_of_key(100)=5 ans=4+5=9
*/