class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int low = 0, high = arr.size() - 1;
            int ans = -1; // Default agar koi element na mile

            while (low <= high) {
                int mid = low + (high - low) / 2;

                // Agar mid element x se bada ya barabar hai
                if (arr[mid] >= x) {
                    ans = mid;        // Is index ko save karo
                    high = mid - 1;   // First occurrence aur chote number ke liye left side jao
                } else {
                    low = mid + 1;    // Agar x se chhota hai toh right side jao
                }
            }
            return ans;
    }
};