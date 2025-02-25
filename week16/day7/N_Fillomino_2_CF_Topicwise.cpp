#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=505;
vector<vector<int>> v(maxN, vector<int>(maxN));
vector<vector<bool>> vis(maxN, vector<bool>(maxN));
vector<int> dia[maxN];
int n;
bool isValid(int i,int j){
    if(i>=n || j<0) return false;
    else return true;
}
void dfs(int x,int y,int val){
    if(dia[val].size()==val) return;
    v[x][y]=val;
    vis[x][y]=true;
    dia[val].push_back(val);
    if(isValid(x,y-1) && !vis[x][y-1]){
        dfs(x,y-1,val);
    }
    else if(isValid(x+1,y) && !vis[x+1][y]){
        dfs(x+1,y,val);
    }
}
void mohaimin(){
    cin>>n;
    for(int i=0;i<n;i++){
        fill(v[i].begin(),v[i].end(),-1);
        fill(vis[i].begin(),vis[i].end(),false);
    }
    vector<int> given(n);
    for(int i=0;i<n;i++){
        cin>>given[i];
    }
    for(int i=0;i<n;i++){
        int j=i;
        dfs(i,j,given[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]!=-1){
                cout<<v[i][j]<<" ";
            }
            else cout<<" ";
        }
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
easy kothay amader pattern korte hobe. 
tara amader diagonally ki ki value boshbe oita diye dibe (permutation)
diagonal theke er nicher part fill up korte hobe, uporer part niye
amader chinta na korleo hobe. 
then amader oi value boshaite hobe:- 
1) suppose X value hole sheta diagonal e to boshbei
2) left side & down side e milaiya boshbe total X amount bar
testcase 1: 
3
2 3 1

initially diagonal e to boshbe
2
_ 3
_ _ 1

but 2 boshte hobe 2bar. jehetu tar left e jawar jayga nai so she
niche jabe. Now: 
2
2 3
_ _ 1

ekhon 3 boshte hobe 3bar. 1ta already boshe geche & aro 2ta boshate
hobe. But left side to already fillup so down side e jabo & 1ta 3
boshabo:
2
2 3
_ 3 1

aro 1ta 3 boshaite hobe & 2nd 3 er left e jayga ache so oi jaygay
3rd 3 boshay dibo. 
2
2 3
3 3 1

lastly 1 boshaite hobe but 1 already boshe geche 1 bar so etai final
answer. 

approach: 
amra main vector nisi publicly & shob index er value -1 kore 
rakhsi initially also visited track er vector o false diye rakhsi. 
ar check korsi ekta specific value ta koybar boshche. adjacency
list diye jehetu topic er all problem solve korsi tai etai use korsi
but map o use kora jaito. 
then given ekta vector e diagonally boshbe je vector oita nilam
then matrix er diagonal er upor dfs chalailam. 

dfs e diagonal index & kon value ta boshbe oita diye dilam. 
value ta main vector e boshailam & visited true kore dilam & adjacency
list e value tar count barailam. 
BASE CASE: value er adjacency list er size tar shoman hoye gele return. 
tarpor amra age left e check korlam je left valid kina & not visited
kina. both condition fillup korle age left e gelam. oitay dfs na 
kora gele down direction e dfs chalabo & check korbo oitay dfs hoy
kina & hoile down e jabo.

diagonal line e dfs shesh hoye gele amra answer print korb.
-1 chara digit ache eshob value print kore dilam. 
*/