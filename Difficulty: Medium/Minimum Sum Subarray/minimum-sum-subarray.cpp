class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        // kadens se hua hai
        int min_sum = arr[0], current_sum = 0 , n = arr.size();
        
        for(int i = 0;i < n;i++){
            current_sum += arr[i];
            
            if(current_sum < min_sum){
                min_sum = current_sum;
            }
            if (current_sum > 0){
                current_sum = 0;
            }
        }
        return min_sum;
        
        // sliding window ka 
    }
};