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
        vector<int> og(n);
        for(int i=0;i<n;i++) cin>>og[i];
        bool already=true;
        int pos=-1;
        for(int i=1;i<n;i++){
            if(og[i-1]>og[i]){
                already=false;
                pos=i;
            }
        }
        if(already) cout<<"YES"<<endl;
        else{
            vector<int> first,second;
            for(int i=0;i<pos;i++){
                first.push_back(og[i]);
            }
            for(int i=pos;i<n;i++){
                second.push_back(og[i]);
            }
            sort(og.begin(),og.end());
            second.insert(second.end(),first.begin(),first.end());
            bool check=true;
            for(int i=0;i<n;i++){
                if(og[i]!=second[i]){
                    check=false;
                    break;
                }
            }
            if(check) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}