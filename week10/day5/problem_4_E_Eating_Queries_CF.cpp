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
        int n,q;
        cin>>n>>q;
        vector<int> v(n),pre(n);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.rbegin(),v.rend());
        
        for(int i=0;i<n;i++){
            if(i==0) pre[i]=v[i];
            else pre[i]=pre[i-1]+v[i];
        }
        // for(auto x:pre) cout<<x<<" ";
        // cout<<endl;
        while(q--){
            int k;
            cin>>k;
            int ans=-1;
            auto it=lower_bound(pre.begin(),pre.end(),k);
            if(it!=pre.end()){
                ans=it-pre.begin();
                cout<<ans+1<<endl;
            }
            else cout<<ans<<endl;
        }
    }
    return 0;
}
/*
target is to find the minimum numbers of candies he needs to 
reach greater than or equal to given key. if he can't after having
all the candies then answer is -1. 

the use of lower bound will be exist in this problem. since this
built in function use binary search to find the lower bound of the
given value. 

To solve this, we need to sort this in a descending order so that
we can always pick the highest values. 
now we'll make a prefix sum array which will be: 
9 14 18 22 25 28 29 30
now suppose we need 10, so upper bound will return an iterator
which is holding a value equal or greater than 10. So it'll return
us 14. if we remove pre.begin() from it then it will be the "number
of index are in the range WITHOUT beginning value". So to include
the beginning value also we'll just +1 with the answer. So ans=2. 

*/