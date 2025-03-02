#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<vector<int>> pos(k);
    set<int> st;

    for(int i=0;i<n;i++){
        pos[v[i]-1].push_back(i);   //0-base indexing
        st.insert(i);
    }

    vector<int> ans(k);
    for(int x=0;x<k;x++){
        if(!pos[x].size()) continue;

        ans[x]= 2*(*st.rbegin()-*st.begin()+1);
        for(auto rNc:pos[x]){   //both row & column
            st.erase(rNc);
        }
    }
    for(int x:ans) cout<<x<<" ";
    cout<<ln;
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
its more like an implementation matrix problem. Need to read this
with a testcase: 
suppose: 
5 3
1 2 3 2 1

now according to problem statement: 

      1 2 3 2 1
      -----------
    1|1 _ _ _ _ |   0
    2|_ 2 _ _ _ |   1
    3|_ _ 3 _ _ |   2
    2|_ _ _ 2 _ |   3
    1|_ _ _ _ 1 |   4
     ------------   ^ row
      0 1 2 3 4 5   -col

since we are putting all min(i,j) on the position so diagnoally
this given vector will be stay. 
now we see that 1 is the smallest value so for the whole row where
1 exists, we'll put it into the whole row. then same for column
also. 

      1 2 3 2 1
      -----------
    1|1 1 1 1 1 |   0
    2|1 2 _ _ 1 |   1
    3|1 _ 3 _ 1 |   2
    2|1 _ _ 2 1 |   3
    1|1 1 1 1 1 |   4
     ------------   ^ row
      0 1 2 3 4 5   -col

now we see that 2 is the 2nd smallest value so for the whole row 
where 2 exists, we'll put it into the whole row except where 1
is already exists. then same for column also.


      1 2 3 2 1
      -----------
    1|1 1 1 1 1 |   0
    2|1 2 2 2 1 |   1
    3|1 2 3 2 1 |   2
    2|1 2 2 2 1 |   3
    1|1 1 1 1 1 |   4
     ------------   ^ row
      0 1 2 3 4   -col

now we need to find the smallest rectangle for each color. 
we can see that for 1, it's smallest row=0 & largest row=4
same for it's column. 
since we need the sums of width and height of the smallest rectangle
we can use this formula: (max row-min row +1)+(max col-min col+1)

now 1's max col=4, min col=0, max row=4, min row=0
so using formula the answer is: (4-0+1)+(4-0+1)=10

so how we'll solve this? 
we took:-
vector<vector<int>> pos(k);
set<int> st;

we'll put v[i]-1 (0 base indexing), to get the max-min row & column
and inside set we are taking row-column serial. 

so now we have: 
pos[0]= 0,4 (v[i]=1)
pos[1]= 1,3 (v[i]=2)
pos[2]= 2 (v[i]=3)
st= 0 1 2 3 4 

now we'll check for all colors. 

for color 0/(v[i]=1): 
--> st.rbegin()=4 & st.begin()=0
--> pos[0].size()!=0 & ans[0]=2*(4-0+1)=2*5=10
--> now erase both of them from st so st=1 2 3

for color 1/(v[i]=2):
--> st.rbegin()=3 & st.begin()=1
--> pos[1].size()!=0 & ans[1]=2*(3-1+1)=2*3=6
--> now erase both of them from st so st=2

for color 2/(v[i]=3):
--> st.rbegin()=2 & st.begin()=2
--> pos[2].size()!=0 & ans[2]=2*(2-2+1)=2*1=2
--> now erase both of them from st so st=[]

so answer= 10 6 2
*/
