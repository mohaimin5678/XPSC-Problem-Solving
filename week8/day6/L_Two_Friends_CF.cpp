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
        vector<int> v(n+1);
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            mp[i]=v[i];
        }
        int mn=INT_MAX;
        for(int i=1;i<=n;i++){
            int j=i;
            int x=mp[j];
            int cnt=1;
            while(x!=i){
                j=x;
                x=mp[j];
                cnt++;
                if(cnt==3) break;
            }
            mn=min(mn,cnt);
        }
        cout<<mn<<endl;
    }
    return 0;
}
/*
5
3 1 2 5 4

1 2 3 4 5-->idx

1->3 
2->1 
3->2 
4->5
5->4 

here 4's bestfriend is 5 & same 5's bestfriend is 4. So inviting these
2 will be enough.

since all we can do is giving invitation, not necessary we have to give
all of them invitation. So if we already gave 3 invitation, we'll simply
break the loop. 
NOTE: highest invitation will always be 3. not more than that & atleast
2 invitation. 

*/