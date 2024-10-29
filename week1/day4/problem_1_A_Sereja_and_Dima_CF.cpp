#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    deque<int> dq(n);
    for(int i=0;i<n;i++){
        cin>>dq[i];
    }
    int sereja=0,dima=0,i=1;
    while(!dq.empty()){
        int left=dq.front();
        int right=dq.back();
        int mx=max(left,right);
        if(i%2==1) sereja+=mx;
        else dima+=mx;
        if(mx==left) dq.pop_front();
        else dq.pop_back();
        i++;
    }
    cout<<sereja<<" "<<dima<<'\n';
    return 0;
}