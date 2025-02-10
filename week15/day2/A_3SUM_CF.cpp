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
    map<int,int> frq;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        frq[x%10]++;
    }
    for(auto [x,y]:frq){
        if(y>3) y=3;
        for(int i=1;i<=y;i++){
            v.push_back(x);
        }
    }
    // for(int x:v) cout<<x<<" ";
    for(int i=0;i<v.size()-2;i++){
        for(int j=i+1;j<v.size()-1;j++){
            for(int k=j+1;k<v.size();k++){
                if((v[i]+v[j]+v[k])%10==3){
                    cyes;
                    return;
                }
            }
        }
    }
    cno;
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
we can calculate the last digits only & also calculating [1 1 1]
& calculating [1 1 1 1] means same cause both will answer 3. 
same goes for every other digits. calculating atmost 3 of each will
be enough. now total digits are 10 & highest we're taking 3 of each
so vector size will be highest 30. so O(N^3) loop won't be a problem. 
*/