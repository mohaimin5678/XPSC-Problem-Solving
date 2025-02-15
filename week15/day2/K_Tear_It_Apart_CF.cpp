#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    string s;
    cin>>s;
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    int ans=INT_MAX;
    for(auto [x,y]:mp){
        int dis=0;
        int largest=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]!=x){
                dis++;
            }
            else{
                largest=max(largest,dis);
                dis=0;
            }
        }
        largest=max(largest,dis);
        int op=0;
        while(largest>0){
            op++;
            largest/=2;
        }
        ans=min(op,ans);
    }
    cout<<ans<<ln;
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
we need to find the biggest distance & calculate how many operation
it will be needed to erase them. using log2(dis) won't work because
log2(1)=0 which won't help to solve this problem. 
so we'll check for all existing characters & for each characters we'll
check the biggest distance among them & calculate the operations. 
then for answer we'll take the one that took minimum numbers of 
operations. 
*/
