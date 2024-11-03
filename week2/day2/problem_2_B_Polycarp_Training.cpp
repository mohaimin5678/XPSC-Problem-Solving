#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    multiset<int> ml;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ml.insert(x);
    }
    int ans=0,problems=1;
    while(!ml.empty()){
        auto LB=ml.lower_bound(problems);
        if(LB!=ml.end()){
            ans++;
            ml.erase(LB);
        }
        else break;
        problems++;
    }
    cout<<ans<<'\n';
    return 0;
}
/*
testcase:
4
3 1 4 1
output:
3

here this array represents number of contests & each index 
represents the number of problems in each contest. 
what he has to do is that, he has to solve problems per day!
means on 1st day 1 problem, on 2nd day 2, on 3rd 3, on 4th 4... 
so for 1st day he'll solve 1 problem & it doesn't matter if
there is more problem in that contest. same for the 2nd day
he'll solve 2 problem & it doesn't matter if there is more problem
to solve in that contest BUT that contest atleast have 2 problem
otherwise he won't be able to solve it (means more will be ok,
but can't be less).
now lets explain using the testcase: 
contests-> 3 1 4 1
=>for day 1 he will select any of the two contests consist of 1
remaining contests-> 3 1 4
=>for day 2 he'll select closest value of 2 which is 3 & he'll
solve 2 problem from 3. 
remaining contests-> 1 4
=>for day 3 he'll select closest value of 3 which is 4 & he'll
solve 3 problem from 4.
remaining contests-> 1
=>but for day 4 there is no contest left that has >=4 problems
so he can only train 3 days
so the output is 3.

*/