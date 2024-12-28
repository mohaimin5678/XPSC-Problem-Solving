#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[i].first=x;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    int rounds=1;
    int idx=-1;
    for(int i=0;i<n;i++){
        // cout<<v[i].first<<" "<<v[i].second<<endl;
        if(v[i].second<idx) rounds++;
        idx=v[i].second;
    }
    cout<<rounds<<endl;
    return 0;
}
/*
since we can't make multiple loops because of the constraint
we have to make an analysis on how to solve this in one loop!
But since its a rounds problem, we need to find a way by which
we can count the rounds that we'll be needed. 

they let us to go from left to right, so if next value's
index position is lower than current's index position, then 
it means we need to increment the round number. And this is
what we'll keep our track.
 
now lets check a testcase: 
testcase:
5
4 2 1 5 3
now: 
vector:  4 2 1 5 3
index:   1 2 3 4 5
we all know that we have to start from 1, then 2>3>4>5
so lets sort the vector based on their first value. 
vector: 1 2 3 4 5
index:  3 2 5 1 4

we'll keep an idx which will carry the index position of the
last founded increasing number. 
lets initially take idx=-1 & rounds=1
for v[0]={1,3} & 3>-1 so no increment. Now idx=3 & round=1  
for v[1]={2,2} & 2<3 so increment must. Now idx=2 & round=2
for v[2]={3,5} & 5>2 so no increment. Now idx=5 & round=2
for v[3]={4,1} & 1<5 so increment must. Now idx=1 & round=3
for v[4]={5,4} & 4>1 so no increment. Nor idx=4 & round=3

final answer: 3
*/