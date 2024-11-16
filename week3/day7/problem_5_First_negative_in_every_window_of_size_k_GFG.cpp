class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& v, int k) {
        int n=v.size();
        int l=0,r=0;
        vector<int> ans;
        queue<int> q;   //for FIFO
        while(r<n){
            if(v[r]<0){
                q.push(v[r]);
            }
            if(r-l+1==k){   //window size equal then inside
                if(!q.empty()){     //if not empty means negative value exist
                    ans.push_back(q.front());
                    if(v[l]==q.front()){    //if same then remove because for next window l will be updated
                        q.pop();
                    }
                }
                else ans.push_back(0);  //according to problem statement
                
                l++;
                r++;
            }
            else r++;
        }
        return ans;
    }
};