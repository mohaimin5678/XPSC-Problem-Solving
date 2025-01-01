#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll sum;
    cin>>sum;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<pair<ll,int>> all;
    for(int i=0;i<n;i++){
        all.push_back({v[i],i+1});
    }
    sort(all.begin(),all.end());
    // for(auto x:all) cout<<x.first<<" --> "<<x.second<<endl;
    ll rem;
    bool flag=false;
    vector<int> three;
    for(int i=0;i<n-2;i++){
        rem=sum-all[i].first;
        int l=i+1,r=n-1;
        while(l<r){
            if((all[l].first+all[r].first)==rem){
                three.push_back(all[i].second);
                three.push_back(all[l].second);
                three.push_back(all[r].second);
                flag=true;
                break;
            }
            else if((all[l].first+all[r].first)<rem){
                l++;
            }
            else if((all[l].first+all[r].first)>rem) r--;
        }
        if(flag) break;
    }

    if(flag){
        sort(three.begin(),three.end());
        for(int x:three) cout<<x<<" ";
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
/*
we'll simply sort the whole vector. then we'll start doing a nested loop
to check which 2 will be equal to the remaining sum. 
if l+r<rem means we need bigger value than current l so l++;
if l+r>rem means we need smaller value than current r so r--;
we'll track the answer using flag & then add them into a different vector
which will be sorted to provide the answer. 
*/