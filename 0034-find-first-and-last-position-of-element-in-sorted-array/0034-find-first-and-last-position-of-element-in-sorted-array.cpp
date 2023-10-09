class Solution {
public:
    int findFirstOccurence(int n,vector<int>& arr, int key){
        int low =0;
        int high = n-1;
        int first=-1;
     while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==key){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]<key)  low = mid+1;
        else high = mid-1;
   }
return first;

}

  int findLastOccurence(int n,vector<int>& arr, int key){
        int low =0;
        int high = n-1;
        int last=-1;
        while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==key){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<key)  low = mid+1;
        else  high = mid-1;
        }
        return last;
  }


    vector<int> searchRange(vector<int>& nums, int key) {
        int n=nums.size();
        int firstOccurence = findFirstOccurence(n, nums, key);
        if(firstOccurence==-1) return {-1,-1};
        int lastOccurence = findLastOccurence(n, nums, key);
        return {firstOccurence,lastOccurence};

   }
};
