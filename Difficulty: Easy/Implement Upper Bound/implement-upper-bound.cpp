class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
            int low = 0, high = n - 1;
            int ans = n; // Default answer agar koi element strictly bada na mile (length of array)

            while (low <= high) {
                int mid = low + (high - low) / 2;

                // Upper bound mein strictly bada ( > ) dekhte hain, equal nahi
                if (arr[mid] > target) {
                    ans = mid;        // Is index ko save karo
                    high = mid - 1;   // Aur pehle kisi bade element ke liye left side jao
                } else {
                    low = mid + 1;    // Agar chhota ya barabar hai toh right side jao
                }
            }
            return ans;
    }
};
