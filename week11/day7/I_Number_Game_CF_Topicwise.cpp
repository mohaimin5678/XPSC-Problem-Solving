#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    multiset<int> ml;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ml.insert(x);
    }
    auto check=[&](int k){
        multiset<int> x;
        x=ml;
        for(int i=1;i<=k;i++){
            if(x.empty()) return false;
            int target=k-i+1;
            auto it=x.upper_bound(target);
            if(it==x.begin()){
                return false;
            }
            else{
                --it;
                x.erase(it);

            }
            if(!x.empty()){
                auto it=x.begin();
                int val=*it;
                x.erase(it);
                x.insert(val+target);
            }
        }
        return true;
    };

    int l=0,r=101,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
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
    return 0;
}
/*
the best way to solve this problem is to make them into ascending
order. Using multiset will provide us the advantage of ascending
sorted array. 
we'll make a binary search on answer where we'll provide k(mid)
into check function, if it returns true then we'll move right to
check maximum. Else we'll move left to check if for any lesser
value of k provides the answer. 

inside check function: 
we'll use a copy multiset & we'll loop through 1 to k. 
inside loop: we'll check if the ml is empty or not, if empty then 
return false. 
the target is k-i+1 & we'll check its exist on the ml or not. 
if the upper bound of target is ml.begin() then it means there is
no value equal/lower than target, all of them are bigger than target. 
So return false. 
if the upper bound of target isn't ml.begin() then it means --it is
equal or a bit lower than equal.Then we'll erase it. (alice move)
After erasing we'll check if the ml is empty or not, if not then
we'll take the lowest value & erase it, then add lpwest value+target
into the ml. 

if all of the false returning condition left untriggered during the
whole loop then after the loop ends, return true. 

*/