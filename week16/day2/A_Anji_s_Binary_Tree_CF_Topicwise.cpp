#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=3e5+9;
vector<int> g[maxN],operations(maxN);
string s;
void dfs(int u){
    if(g[u][0]!=0){     //left child
        int v=g[u][0];
        if(s[u-1]!='L'){
            operations[v]=operations[u]+1;
        }
        else operations[v]=operations[u];
        dfs(v);
    }
    if(g[u][1]!=0){     //right child
        int v=g[u][1];
        if(s[u-1]!='R'){
            operations[v]=operations[u]+1;
        }
        else operations[v]=operations[u];
        dfs(v);
    }
}
void mohaimin(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){      //remove previous testcase data
        g[i].clear();
        operations[i]=0;
    }
    cin>>s;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        g[i].push_back(l);
        g[i].push_back(r);
    }
    dfs(1);
    // for(int i=1;i<=n;i++){
    //     if(g[i][0]==0 && g[i][1]==0){
    //         cout<<i<<" "<<operations[i]<<ln;
    //     }
    // }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        if(g[i][0]==0 && g[i][1]==0){
            ans=min(ans,operations[i]);
        }
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
question: string dewa thakbe, N number of pair er input dewa thakbe
jegula 1 to N porjonto er left & right child bole dibe. 0 dile no
child(can be for only left/right or both). s[i] hobe (i+1)th node er 
command je kon dike jabo. Target is to go to a leaf node & to reach
there if we need to change the command, then what is the minimum 
number of command changes needed to reach a leaf node?

observation: jehetu amra jani na kon leaf e jaite koyta operation
change kora lagbe so amra shob leaf er jonnoi dfs apply kore kore jabo
then shob leaf node er perspective e shekhane reach korte koyta operation
change korte hoise oita theke minimum ta receive korbo. 

constraint onujayi size nibo maxN er. then ekta vector of vector nibo
& ekta single vector nibo jekhane 2tar size e hobe maxN. 
string ta globally declare korbo since DFS e use korte hobe.
N size er loop 1 to N chalaiya left & right child niye nibo. 
since root 1 so dfs e initially 1 diye pathabo. 
DFS e dekhbo left child !=0 kina, na thakle V te left child store korbo
then check korbo oi U er opposite e je char ta ache sheta L kina
jodi thake tahole to change hobe na otherwise amader operation +1 kore
next value tar jonno dfs e V pathaite hobe. 
same right child er jonno dekhbo. 
*/
