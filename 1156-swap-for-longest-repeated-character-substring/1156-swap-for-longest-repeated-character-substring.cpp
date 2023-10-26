class Solution {
public:
 int maxRepOpt1(string text) {
        int ans=0;
        map<char,vector<int>>mp;
        for(int i=0;i<text.size();i++)
        {
            mp[text[i]].push_back(i);
        }
        for(auto &p : mp)
        {
            int pre=0;
            int curr=1;
            int sum=0;
            for(int i=0;i<p.second.size()-1;i++)
            {
                if(p.second[i+1]-p.second[i]==1)  curr++;
                else
                {
                    if(p.second[i+1]-p.second[i]==2)
                        pre = curr;
                    else
                        pre = 0;
                    curr = 1;
                } 
                sum=max(sum,curr+pre);
            }
            if(sum<p.second.size())
                sum++;
            ans=max(ans,sum);
        } 
        return ans;
    }
};