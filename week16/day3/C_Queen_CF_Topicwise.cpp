#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,root;
    cin>>n;
    vector<int> g[n+1];   //adjacency list
    vector<int> bad(n+1); //particular node er bad children koyta
    vector<int> a(n+1);   //particular node nije bad kina tar jonno
    for(int i=1;i<=n;i++){
        int p,c;
        cin>>p>>c;
        // int u=p,v=i;
        if(p!=-1) g[p].push_back(i);    //parent e children push
        else root=i;

        if(c==1){
            bad[p]++;  //parent er jonnow store hoye gelo bad childs gula
            a[i]=1;    //nijeo bad sheta set kora hoilo
        }
    }
    vector<int> del;
    for(int i=1;i<=n;i++){
        if(i==root) continue;   //cause root kokhono delete hobe na

        //tar shob child bad & she nijeo bad
        if(g[i].size()==bad[i] && a[i]==1){
            del.push_back(i);
        }
    }
    if(del.size()==0) cout<<-1<<ln;
    else{
        for(int x:del) cout<<x<<" ";
        cout<<ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        mohaimin();
    }
}
/*
ekta 1 to N er tree hobe jetay input e -1 dewa ache mane oita root bojhabe
nahole P er value jeta hobe sheta hobe ith node er parent & she good(0)
or bad(1) child sheta bolbe C. Amader shei node gulo ke delete korte
hobe jara tader parent ke respect kore na & tader shob child o tader ke
respect kore na. Leaf node er khetre shudhu she bad holei delete kore
dibo. 

OBSERVATION: respecting node shobgula out of calculation thakbe jehetu
era kokhono delete hobe na. So amra check korbo bad nodes der (means
she tar parent ke respect kore na) & check korbo tar nijer bad children
koyta. jodi tar total children==bad children hoy tahole delete kore 
dibo. 
*/
