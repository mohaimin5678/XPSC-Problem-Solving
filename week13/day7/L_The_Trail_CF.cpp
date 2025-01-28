#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<ll>> v(n, vector<ll> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int x=0,y=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='D'){
            ll sum=0;
            for(int j=0;j<m;j++){
                sum+=v[x][j];
            }
            v[x][y]=0-sum;
            x++;
        }
        else if(s[i]=='R'){
            ll sum=0;
            for(int j=0;j<n;j++){
                sum+=v[j][y];
            }
            v[x][y]=0-sum;
            y++;
        }
    }
    ll total=0;
    for(int j=0;j<m;j++){
        total+=v[n-1][j];
    }
    v[n-1][y]=0-total;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<ln;
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
On input they will provide us a 2D matrix & a path which 
we'll start from (0,0) & endpoint is (n-1,m-1). 
the path is a string which will be consist of only D & R
on the matrix, those cells which indicates the path, their
values will be 0. 

solution approach: 
we'll solve this using 2 loops. 
Outer loop will be on path(given string). 
now in inner loop will be based on if-else condition. 

if s[i]=D, then we'll sum that row & put that index's value as 
(0-sum) why? because our target will be to make the whole row's
sum==0. so if we get sum=6, then that path's index will be -6. 
and since s[i]==D, we'll go suppose from (0,0) to (1,0) & for
that we have to do x++; where x==cur row index & y=cur col index. 

if s[i]=R, then we'll sum that column & put that index's value as
(0-sum) why? because our target will be to make the whole column's
sum==0. so if we get sum=6, then that path's index will be -6. 
and since s[i]==R, we'll go suppose from (0,0) to (0,1) & for
that we have to do y++; where x==cur row index & y=cur col index.

Now if we observe carefully, we are changing the index's value based
on D & R but its on current index. but we have to change all path's
index. Means if they are giving 5 indexes to change, the path string
size is 4! And for that 4, we are changing 4 indexes value. Then 
there is 1 index which is not changing on that nested loop which 
is v[n-1][m-1]. 
so after that nested loop, we'll take another loop & take last 
column/row's sum & put (0-sum) on v[n-1][m-1]. 

testcase: 
3 3
DRRD
0 2 3
0 0 0
3 1 0

x=0,y=0
s[i]=D so row sum of v[0][0]+v[1][0]+v[2][0]=0+2+3=5 
so  v[0][0]=0-5=-5      & x++ so x=1,y=0
-5 2 3
 0 0 0
 3 1 0

s[i]=R so column sum of v[0][0]+v[1][0]+v[2][0]=-5+0+3=-2
so  v[1][0]=0-(-2)=2    & y++ so x=1,y=1
-5 2 3
 2 0 0
 3 1 0

s[i]=R so column sum of v[0][1]+v[1][1]+v[2][1]=2+0+1=3
so  v[1][1]=0-3=-3      & y++ so x=1,y=2
-5  2 3
 2 -3 0
 3  1 0

s[i]=D so row sum of v[1][0]+v[1][1]+v[1][2]=2-3=-1
so  v[1][2]=0-(-1)=1    & x++ so x=2,y=2
-5  2 3
 2 -3 1
 3  1 0

nested loop break;

now for v[x][y]==v[n-1][m-1] , we checked column's sum, but row's
sum can also work. 
now v[2][0]+v[2][1]+v[2][2]=3+1+0=4
so v[2][2]=0-4=-4
now final matrix is:- 
-5  2  3
 2 -3  1
 3  1 -4
*/