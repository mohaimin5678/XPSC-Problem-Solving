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
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(v[1]!=v[i]){
            flag=true;
            break;
        }
    }
    if(flag){
        cyes;
        int city=-1;
        for(int i=2;i<=n;i++){
            if(v[1]!=v[i]){
                cout<<1<<" "<<i<<ln;
                city=i;
            }
        }
        for(int i=2;i<=n;i++){
            if(v[1]==v[i]){
                cout<<city<<" "<<i<<ln;
            }
        }
    }
    else cno;
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
jekono 1ta gang er 1ta district ke center e rekhe baki shob different 
gang er districts gulo ke oi center district er shathe connect kore
dibo. Then oi selected gang er ar remaining districts thakle center 
er shathe connected jekono district er shathe connect kore dibo. 
testcase: 
5
1 2 2 1 3       

now indices are districts
lets select 1 as center then
          2
          |
    2----[1]----3
since there is one more 1st gang district remaining so lets connect
it with 3rd gang.
          2
          |
    2----[1]----[3]
                 |
                 1
this is gang representation. 
now v=[1 2 2 1 3]   gangs
index=[1 2 3 4 5]   districts
          3
          |
    2----[1]----[5]
                 |
                 4
so ans: 
YES
1 2
1 3
1 5
5 4
*/