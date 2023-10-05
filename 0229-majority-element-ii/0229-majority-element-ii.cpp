class Solution {
public:
    vector<int> majorityElement(vector<int> &arr){

    vector<int> ans;
    int cnt=1;
    for(int i=0;i<arr.size();i++){
        cnt=1;
        if(arr[i]!=1e9+1 && (ans.empty() || ans.back()!=arr[i]) ){

            for(int j=i+1;j<arr.size();j++){
                if(arr[j]==arr[i]){
                    arr[j]=1e9+1;
                      cnt++;
                }
                  
            }
            if(cnt>arr.size()/3)
                ans.push_back(arr[i]);
        }
    }
    return ans;
    }
};