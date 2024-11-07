#include<bits/stdc++.h>
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
        map<int,int> cnt;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            cnt[x]++;
        }
        priority_queue<int> pq;
        for(auto [x,y]:cnt){
            pq.push(y);
        }
        while(!pq.empty()){
            //if pq doesn't have atleast 2 element then we can't
            //make any pair thats why our loop will end.
            if(pq.size()<2) break;

            int x=pq.top();     //1st highest occurance taken
            pq.pop();           //then removed it
            int y=pq.top();     //2nd highest occurance taken
            pq.pop();           //then removed it
            
            //making pair so decrement the 2 highest value
            x--;
            y--;

            //After decrement if their value is still exist then
            //push them again into the pq.
            if(x>0) pq.push(x);
            if(y>0) pq.push(y);
        }

        int ans=0;
        while(!pq.empty()){
            //remaining occurance will be added to ans
            //because remaining occurance represents that the
            //elements still exists & they didn't make the pair
            ans+=pq.top();  
            pq.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
remove elements from the array but also can't choose both 
elements that are duplicate. Ai != Aj is the rule & then
remove both Ai & Aj. 

logic:- 
value with highest occurence will be paired with value with 2nd
highest occurance

given testcase explanation: 
6
1 6 1 1 4 4
here we got:
3 times 1
2 times 4
1 time 6
pairing {1,4} & we will still have
2 times 1
1 times 4
1 time 6
pairing {1,4} again & we will still have
1 time 1
1 time 6
since there is no occurance of 4 anymore, we won't re-enter 
4 into our priority queue. 
after pairing {1,6}, there will be no 1 & 6 
so the array size will become empty
minimuming the array size is the target
*/