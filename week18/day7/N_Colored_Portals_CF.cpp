#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
vector<string> p={"BG","BR","BY","GR","GY","RY"};
void mohaimin(){
    int n,q;
    cin>>n>>q;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    vector<vector<int>> mp(6);
    for(int i=0;i<n;i++){
        if(s[i]=="BG") mp[0].push_back(i);
        if(s[i]=="BR") mp[1].push_back(i);
        if(s[i]=="BY") mp[2].push_back(i);
        if(s[i]=="GR") mp[3].push_back(i);
        if(s[i]=="GY") mp[4].push_back(i);
        if(s[i]=="RY") mp[5].push_back(i);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        set<char> st;
        for(char c:s[x]) st.insert(c);
        for(char c:s[y]) st.insert(c);
        if(st.size()<4){    
            //suppose BR & GR so set=BGR <4 means directly connected
            cout<<abs(x-y)<<ln;
            continue;
        }
        if(y<x) swap(x,y);
        int l=-1,r=n;
        for(int i=0;i<6;i++){
            if(p[i]==s[x] || p[i]==s[y]) continue;
            
            //checking the nearest left value of X
            auto it=lower_bound(mp[i].begin(),mp[i].end(),x);
            if(it!=mp[i].begin()){  //if there is a value then check
                it--;
                l=max(l,*it);
            }

            //checking the nearest right value of X
            auto it2=upper_bound(mp[i].begin(),mp[i].end(),x);
            if(it2!=mp[i].end()){   //if there is a value then check
                r=min(r,*it2);
            }
        }
        if(l==-1 && r==n){  //no way to reach
            cout<<-1<<ln;
            continue;
        }
        if(l==-1){  //only right value exist so calculating distance
            cout<<abs(x-r)+abs(y-r)<<ln;
            continue;
        }
        if(r==n){   //only left value exist so calculating distance
            cout<<abs(x-l)+abs(y-l)<<ln;
            continue;
        }
        //since both are exist so checking which one giving the minimum
        //answer
        int ans=min((abs(x-r)+abs(y-r)),(abs(x-l)+abs(y-l)));
        cout<<ans<<ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
since there are only 6 possible strings: BG BR BY GR GY RY
lets put them into a vector of string p-> 0  1  2  3  4  5       index

then we'll take input on a vector of string. 
then we'll declare a vector of vector<int> mp which will be a 6 size
and just like string p, we'll push back their index on mp[color]
(here we put 0 to 5 for color BG to RY.)
now each color has their appearing indexes on their own vector. 

now lets take queries. 
intially we are doing x--,y-- just to adjust it to our 0-based indexing

1) we'll add x's color & y's color into a set. if there is any common
then the size of combined color won't reach 4. if it doesn't reach 4
then there is a direct connected among x & y. So we'll just print their
abs distance. 

2)if y<x then to reduce coding part we'll just swap the x & y. 

now we are taking l=-1 & r=n to keep the track of nearest left & right
value of X. 
3) we'll start the loop from 0 to 5 & check if p[i]==s[x]/s[y] cause
we need to avoid them. then for other 4 automatic ascending sorted
vector, we'll check lower_bound of x & upper_bound of x on each of them. 
if iterator of lower_bound has something then it-- will give us a value
and we'll do a l=max(l,*it) to get the nearest left value of x. 
if iterator of upper_bound has something then it2 will give us a value
and we'll do a r=min(r,*it2) to get the nearest right value of x. 

after the loop from 0 to 5 ends,
4) if l=-1 & r=n remained that means there is no way to go x to y cause
we couldn't find a 3rd index. so print -1 & continue.

5) if l=-1 but r!=n that means there is a right nearest value of x exists
so we'll calculate the abs distance from x to r + y to r & print it & continue.

6) if r=n bit l!=-1 that means there is a left nearest value of x exists
so we'll calculate the abs distance from x to l + y to l & print it & continue.

7) if both are changed then we'll calculate (x to l + y to l) & also
(x to r + y to r) then whoever is the minimum will be printed. 

this is how we'll do for all queries which will take 4*log(N) 
so total time complexity will be Q*4*log(N) 
*/
