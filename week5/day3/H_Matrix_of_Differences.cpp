#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m=n*n;
        set<int> s;
        for(int i=1;i<=m;i++){
            s.insert(i);
        }
        // cout<<*s.begin()<<" "<<*s.end()<<endl;
        int grid[n][n];
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=n-1;j>=0;j--){
                    if(j%2==0){
                        auto it=prev(s.end());
                        grid[i][j]=*it;
                        s.erase(it);
                    }
                    else{
                        auto it=s.begin();
                        grid[i][j]=*it;
                        s.erase(it);
                    }
                }
            }
            else{
                for(int j=0;j<n;j++){
                    if(j%2==0){
                        auto it=s.begin();
                        grid[i][j]=*it;
                        s.erase(it);
                    }
                    else{
                        auto it=prev(s.end());
                        grid[i][j]=*it;
                        s.erase(it);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}