#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
vector<pair<int,int>> d={{-1,-1},{1,-1},{-1,1},{1,1}};
int n,m;
bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    else return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        vector<vector<int>> ans(n,vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=v[i][j];
                for(int k=0;k<4;k++){
                    int tx=d[k].first+i;
                    int ty=d[k].second+j;
                    while(valid(tx,ty)){
                        sum+=v[tx][ty];
                        
                        tx+=d[k].first;
                        ty+=d[k].second;
                    }
                }
                ans[i][j]=sum;
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mx=max(mx,ans[i][j]);
            }
        }
        cout<<mx<<endl;
    }
    
    return 0;
}