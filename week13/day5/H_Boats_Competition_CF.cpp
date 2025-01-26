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
    vector<int> v(n);
    map<int,int> frq;
    for(int i=0;i<n;i++){
        cin>>v[i];
        frq[v[i]]++;
    }
    sort(v.begin(),v.end());
    map<int,int> sum;
    map<int,bool> vis;
    for(auto x:frq){
        vis[x.first]=true;
        for(auto y:frq){
            if(vis[y.first] && x.first!=y.first){
                continue;
            }
            else if(x.first==y.first){
                sum[x.first+y.first]+=(y.second/2);
            }
            else{
                int mn=min(x.second,y.second);
                sum[x.first+y.first]+=mn;
            }
        }
    }
    int cnt=0;
    for(auto x:sum){
        cnt=max(cnt,x.second);
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
/*
lets check 2 testcases:
6
1 1 3 4 2 2
frq[1]=2, frq[2]=2, frq[3]=1, frq[4]=1

outer loop first round:- 
1 is visited & inner loop is also 1 so,
sum[1+1]=2/2=1 so sum[1]=1      ---(else if part)
now inner loop 2 so,
sum[1+2]=min(2,2)=2 so sum[3]=2 ---(else part)
now inner loop 3 so,
sum[1+3]=min(2,1)=1 so sum[4]=1 ---(else part)
now inner loop 4 so,
sum[1+4]=min(2,1)=1 so sum[5]=1 ---(else part)

outer loop 2nd round:- 
2 is visited & inner loop is 1 which is also visited,
so since 2!=1 so continue;                   ---(if part)
now inner loop 2 so,
sum[2+2]=2/2=1 so sum[4]+=1 so sum[4]=2      ---(else if part)
now inner loop 3 so,
sum[2+3]=min(2,1)=1 so sum[5]+=1 so sum[5]=2 ---(else part)
now inner loop 4 so,
sum[2+4]=min(2,1)=1 so sum[6]=1              ---(else part)

outer loop 3rd round:- 
3 is visited & inner loop is 1 which is also visited,
so since 3!=1 so continue;                   ---(if part)
now inner loop 2 which is also visited,
so since 3!=2 so continue;                   ---(if part)
now inner loop 3 so,
sum[3+3]=1/2=0 so sum[6]=0                   ---(else if part)
now inner loop 4 so,
sum[3+4]=min(1,1)=1 so sum[7]=1              ---(else part)

outer loop 4th round:- 
4 is visited & inner loop is 1 which is also visited,
so since 4!=1 so continue;                   ---(if part)
now inner loop 2 which is also visited,
so since 4!=2 so continue;                   ---(if part)
now inner loop 3 which is also visited,
so since 4!=3 so continue;                   ---(if part)
now inner loop 4 so,
sum[4+4]=1/2=0 so sum[8]=0                   ---(else if part)

now the highest sum's frequency is 2 which is the maximum possible
equal sum pairs. 
scenario 1- sum=4 with {1,3} & {2,2}
scenario 2- sum=5 with {1,4} & {3,2}
*/