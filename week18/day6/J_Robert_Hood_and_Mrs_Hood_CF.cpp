#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,d,k;
    cin>>n>>d>>k;
    // vector<int> v(n+1,0);
    vector<pair<int,int>> jobs(k);
    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;
        jobs[i].first=l,jobs[i].second=r;
    }
    sort(jobs.begin(),jobs.end());
    int mx=0,mn=1e9,bro=-1,mom=-1;
    int l=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<n-d+2;i++){
        while(l<k && jobs[l].first<=(i+d-1)){
            //range er last value theke < jobs er first values
            //gular end point push korbo pq te
            pq.push(jobs[l].second);
            l++;
        }

        //range er first value theke < end values gula remove
        while(!pq.empty() && pq.top()<i){   
            pq.pop();
        }

        int sz=pq.size();
        if(sz>mx){
            mx=sz;
            bro=i;
        }
        if(sz<mn){
            mn=sz;
            mom=i;
        }
    }
    cout<<bro<<" "<<mom<<ln;
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
we need to find 2 visiting D days range. 1 has to have maximum
risky jobs & other has to have minimum risky jobs. 
now lets proceed with a testcase: 
n d k
9 2 4
7 9
4 8
1 3
2 3

now lets sort the k jobs so: 
1 3
2 3
4 8
7 9

also mx=0 & min=1e9     also bro=-1 & mom=-1
and l=0
we'll run a loop from 1 to n-d+2=9-2+2=9  where initial pq=[]
when i=1, first=1 & last=1+d-1=1+2-1=2
    while 1:
        l=0<k(4) jobs[0].first=1 < last so push jobs[0].sec on pq
        pq=[3] & l++;
        l=1<k(4) jobs[1].first=2 == last so push jobs[1].sec on pq
        pq=[3 3] & l++;
        l=2<k(4) jobs[2].first=4 > last so break;
    while 2:
        pq size>0 but pq.top()==3 > i(1) so break;
    now mx<pq.size() so mx=2 & bro=1 
    AND mn>pq.size() so mn=2 & mom=1

now i=2, first=2 & last=2+d-1=2+2-1=3
    while 1: 
        l=2<k(4) jobs[2].first=4 > last so break;
    while 2:
        pq size>0 but pq.top()==3 > i(2) so break;
    no changes on mx & mn so bro & mom remain same. 
*/