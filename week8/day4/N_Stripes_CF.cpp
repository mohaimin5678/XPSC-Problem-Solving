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
        char c[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>c[i][j];
            }
        }
        char ans='.';
        for(int i=0;i<8;i++){
            int cnt=0;
            for(int j=0;j<8;j++){
                if(c[i][j]=='R') cnt++;
            }
            if(cnt==8){
                ans='R';
                break;
            }
        }
        if(ans=='.'){
            for(int j=7;j>=0;j--){
                int cnt=0;
                for(int i=0;i<8;i++){
                    if(c[i][j]=='B') cnt++;
                }
                if(cnt==8){
                    ans='B';
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}