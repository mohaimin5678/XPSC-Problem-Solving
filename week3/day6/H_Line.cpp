#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int start=1,end=n;
    vector<ll> v(n+1);
    priority_queue<ll, vector<ll>, greater<ll>> pq; //minheap
    ll total=0; //counting ans with minimum changes
    int changes=0; //counting changes
    for(int i=1;i<=n;i++){
        int left=abs(i-start);
        int right=abs(end-i);
        if(s[i-1]=='L'){
            if(right>left){ //change needed
                total+=right;
                pq.push(right-left);
                changes++;
            }
            else total+=left;
        }
        else if(s[i-1]=='R'){
            if(left>right){ //change needed
                total+=left;
                pq.push(left-right);
                changes++;
            }
            else total+=right;
        }
    }
    //setting the total from last "changing" occurance 
    //to final index 
    for(int i=changes;i<=n;i++){
        v[i]=total;
    }
    
    //target= removing the lowest amount from total to
    //keep the ans as high as possible.
    //& thats why we are staring from the 2nd last changing
    //means if 5 changes happened, we'll start from 4 to 1.
    for(int i=changes-1;i>=1;i--){
        total-=pq.top();
        pq.pop();
        v[i]=total;
    }
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
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
    return 0;
}