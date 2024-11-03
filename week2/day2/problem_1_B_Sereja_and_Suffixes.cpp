#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,pos;
    cin>>n>>pos;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    set<int> s; 
    //because we need unique value so set is the best option

    vector<int> total(n+1);
    //we have to save the set size into another array according to their indexes.
    for(int i=n;i>=1;i--){
        s.insert(v[i]);
        total[i]=s.size();
    }
    while(pos--){
        int x;
        cin>>x;
        cout<<total[x]<<endl;
    }
    return 0;
}
