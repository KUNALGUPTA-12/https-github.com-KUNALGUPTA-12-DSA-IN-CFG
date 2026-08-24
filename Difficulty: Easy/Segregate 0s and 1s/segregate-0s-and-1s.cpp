class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int left = 0;
        int right = arr.size() - 1;
        while(left < right){
            // aagr left par zero hai toh left ko ++
            if(arr[left]==0){
                left++;
            }
            // right mai 1 hai to right --
            else if(arr[right]==1){
                right --;
            }
            // ager left par 1 aya toh aur right par zero toh swap karo
            else{
                std :: swap(arr[left],arr[right]);
                left++;
                right--;
            }
        }
        
    }
};