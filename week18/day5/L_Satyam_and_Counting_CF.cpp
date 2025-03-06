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
    vector<pair<int,int>> zero,one;
    set<int> a,b;
    while(n--){
        int x,y;
        cin>>x>>y;
        if(y==0){
            zero.push_back({x,y});
            a.insert(x);
        }
        else{
            one.push_back({x,y});
            b.insert(x);
        }
    }
    sort(zero.begin(),zero.end());
    sort(one.begin(),one.end());
    // for(auto [x,y]:one){
    //     cout<<x<<" "<<y<<ln;
    // }
    ll cnt=0;
    int l=0,r=0;
    while(l<zero.size() && r<one.size()){
        if(zero[l].first==one[r].first){
            // cnt+=(one.size()-1);
            cnt+=l;
            cnt+=r;
            cnt+=(zero.size()-l-1);
            cnt+=(one.size()-r-1);
            l++,r++;
        }
        else if(zero[l].first<one[r].first) l++;
        else if(one[r].first<zero[l].first) r++;
    }
    for(int x:a){
        int f=x-1,s=x+1;
        if(b.find(f)!=b.end() && b.find(s)!=b.end()){
            cnt++;
        }
    }
    for(int x:b){
        int f=x-1,s=x+1;
        if(a.find(f)!=a.end() && a.find(s)!=a.end()){
            cnt++;
        }
    }
    cout<<cnt<<ln;
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