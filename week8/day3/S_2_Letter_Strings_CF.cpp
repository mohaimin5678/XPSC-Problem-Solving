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
        map<pair<char,char>,int> mp;
        for(char c='a';c<='k';c++){
            for(char d='a';d<='k';d++){
                mp[{c,d}]=0;
            }
        }
        vector<pair<char,char>> v(n);
        for(int i=0;i<n;i++){
            char a,b;
            cin>>a>>b;
            v[i].first=a;
            v[i].second=b;
            mp[{a,b}]++;
        }
        ll cnt=0;
        for(int i=0;i<n;i++){
            char x=v[i].first;
            char y=v[i].second;
            for(char a='a';a<='k';a++){
                if(a!=y){
                    if(mp[{x,a}]!=0){
                        cnt+=mp[{x,a}];
                    }
                }
            }
            for(char b='a';b<='k';b++){
                if(b!=x){
                    if(mp[{b,y}]!=0){
                        cnt+=mp[{b,y}];
                    }
                }
            }
        }
        cout<<cnt/2<<endl;
        // for(auto x:mp){
        //     auto a=x.first;
        //     int v=x.second;
        //     cout<<a.first<<a.second<<" "<<v<<endl;
        // }
    }
    return 0;
}
/*
first we took all possible pairs in map since constraint is not
that big. after that we took each pairs & increase their frequency.
after that we use 1 loop for 1st element & 2nd loop for the 2nd
element & use if not to count their own pair on the loop. 
since we are traversing full vector of pairs, the result will be
twice the original count cause (ab,aa) will be count for both ab
& aa. So we just have to print the count/2 & that will be the answer.
*/