class Solution {
public:
    vector<int> majorityElement(vector<int> &arr){

    vector<int> ans;
    int cnt=1;
    for(int i=0;i<arr.size();i++){
        cnt=1;
        if(ans.empty() || ((ans[0] || ans[0]==0) && ans[0]!=arr[i] )){

            for(int j=i+1;j<arr.size();j++){
                if(arr[j]==arr[i])
                    cnt++;
            }
            if(cnt>arr.size()/3)
                ans.push_back(arr[i]);
        }
        if(ans.size()==2)
            break;
    }
    return ans;
    }
};