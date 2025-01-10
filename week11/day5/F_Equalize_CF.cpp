#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    set<int> st;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        st.insert(x);
    }
    vector<int> v;
    for(int x:st) v.push_back(x);
    int l=0,r=0;
    // ll sum=0;
    int ans=INT_MIN;
    while(r<v.size()){
        // sum+=v[r];
        if(abs(v[r]-v[l])>n-1){
            while((v[r]-v[l])>n-1){
                l++;
            }
        }
        else ans=max(ans,r-l+1);
        r++;
    }
    cout<<ans<<endl;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) mohaimin();
    return 0;
}
/*
since we are adding permutation that means there is no duplicate
number that we'll gonna add. So it'd be better if we keep those
number whos are already duplicate initially & works with the 
distinct numbers. 
now if the length of the array is 4 that means I can only add
1 2 3 4 in any order I like. 
But since my target is to make them equal, I have to check if
the range I want to make equal is enough for my permutation array
to change it. How?

suppose I have: 
5
1 4 3 7 12
now using set we'll get: 1 3 4 7 12
also we can use 1<->5 to make the element of the array equal. 
so if we do:  1 3 4 7 12
              4 2 1 3 5
            --------------
              5 5 5 10 17
now we can see that we can only able to make 3 of them equal. 
why only 3? because 7 & 12 was much bigger for 1 to match with. 
so to check the range of values that can be equal, we have to 
check if the maximum-minimum of that particular range is <n-1. 
for given example: 
12-1=11 > 5-1=4
7-1=6 > 4
4-1=3 <4 
so from 1 to 4 which got the range of 3 can be equal. 
because values are distinct & we can put permutation values any
way we like to make them equal. Which we did on the top. 
So for this case answer is 3. 
We solve this using sliding window.  
*/
