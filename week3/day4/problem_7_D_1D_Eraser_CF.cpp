#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int start=-1,end=-1;;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                start=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                end=i;
            }
        }
        
        int op=0;
        for(int i=start;i<=end;){
            if(s[i]=='B'){
                i+=k;
                op++;
            }
            else i++;
        }
        cout<<op<<endl;
    }
    return 0;
}