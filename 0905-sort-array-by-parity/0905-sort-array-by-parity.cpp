class Solution {
public:
    
bool isEven(int num) {
    return num % 2 == 0;
}
  vector<int> sortArrayByParity(vector<int>& nums) {
          sort(nums.begin(), nums.end(),[&](int a, int b) {
            if (isEven(a) && !isEven(b)) {
                return true;
            }
            else if (!isEven(a) && isEven(b)) {
                return false;
            }
            return a < b;
        });
         return nums;
    }
};