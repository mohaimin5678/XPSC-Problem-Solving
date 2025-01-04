#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,n;
    cin>>x>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<int> st;
    multiset<int> ml;
    ml.insert(x);
    st.insert(0);
    st.insert(x);
    for(int i=0;i<n;i++){
        st.insert(v[i]);
        auto it=st.find(v[i]);
        auto pos1=it;
        auto prev=--pos1;
        auto pos2=it;
        auto next=++pos2;
        // cout<<*prev<<" "<<*it<<" "<<*next<<endl;
        auto it2=ml.find(*next-*prev);
        ml.erase(it2);
        ml.insert(v[i]-*prev);
        ml.insert(*next-v[i]);
        cout<<*ml.rbegin()<<" ";
    }
    return 0;
}
/*
for the testcase: 
8 3
3 6 2
we got 0 to 8 length road. 
for 3,
   3
---------
so max distance among 3-0 & 8-3 & max is 8-3 so print 8-3=5
for 6,
   3  6
---------
so max distance among (3-0),(6-3),(8-6) is both (3-0),(6-3) so print 3
for 2,
  23  6
---------
so max distance is still 6-3 so print 3. 
so answer= 5 3 3

so to solve this we'll need a set & multiset. 
set for understanding the order of lights. And multiset for
tracking the max distance among them. 
initially we have to put 0 & x on set, x on multiset. 
now lets go through the given testcase: 
8 3
3 6 2
so initially set=[0 8] & ml=[8]
for 3,
set=[0 3 8] so prev=0 & next=8 & their dif=8-0=8
now lets delete this from ml so ml=[]
And lets insert 3-0=3 & 8-3=5 into ml so ml=[3,5]
now max=5 so print it. 

for 6,
set=[0 3 6 8] so prev=3 & next=8 & their dif=8-3=5
now lets delete this from ml so ml=[3]
And lets insert 6-3=3 & 8-6=2 into ml so ml=[2 3 3]
now max=3 so print it. 

for 2,
set=[0 2 3 6 8] so prev=0 & next=3 & their dif=3-0=3
now lets delete this from ml so ml=[2 3]
And lets insert 2-0=2 & 3-2=1 into ml so ml=[1 2 2 3]
now max=3 so print it. 

finally answer 5 3 3. 
*/