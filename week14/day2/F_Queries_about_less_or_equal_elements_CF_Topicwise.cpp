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
// template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//for multiset
template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void mohaimin(){
    int n,q;
    cin>>n>>q;
    pbds<int> p;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        p.insert(x);
    }
    while(q--){
        int x;
        cin>>x;
        cout<<p.order_of_key(x+1)<<" ";
    }
    cout<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
}
/*
they will provide us 2 array(1st as an array & 2nd as queries). 
we have to check for every query that how many values from 1st
array is <= to that query. 
testcase: 
5 5
1 2 1 2 5
3 1 4 1 5   -->query
---------- 
4 2 4 2 5   --> answers for each queries. 

its just slightly different from pbds.order_of_key() but we'll 
solve this problem using it. order_of_key(value) returns a count
which is strictly less than the particular value. 
so for this given array it would return:- 
1 2 1 2 5
3 1 4 1 5
----------
4 0 4 0 4
which is not equal to the desired answer. Now if we just pass 
order_of_key(value+1) then it'll return the count which is strictly
less than the particular value+1 (which automatically include the
value itself too). 
now:- 
1 2 1 2 5

3 1 4 1 5   -->queries
4 2 5 2 6   -->value we are passing into order_of_key() function
----------
4 2 4 2 5   --> answers for each queries. which we want. 
*/