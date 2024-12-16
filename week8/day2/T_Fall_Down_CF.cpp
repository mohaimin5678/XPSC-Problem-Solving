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
        int n,m;
        cin>>n>>m;
        vector<vector<char>> v(n,vector<char> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(v[i][j]=='*'){
                    int row=i;
                    while(row+1<n){
                        if(v[row+1][j]!='o' && v[row+1][j]!='*'){
                            v[row][j]='.';
                            v[row+1][j]='*';
                        }
                        else break;
                        row++;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<v[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}