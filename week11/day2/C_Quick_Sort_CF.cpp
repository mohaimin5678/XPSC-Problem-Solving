#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int track=1;
    for(int i=0;i<n;i++){
        if(v[i]==track) track++;
    }
    
    track--;
    // cout<<track<<"   ";
    float ans=ceil((n-track*1.0)/k*1.0);
    // cout<<ans<<"   ";
    int res=ans;
    cout<<res<<endl;
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
we'll check how many of them are already in a sorted order. 
then remaining unsorted elements will be divided by the k & the 
ceil value of that will be the answer. 
*/