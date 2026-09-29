class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low = 0;
                int high = arr.size() - 1;

                int min_val = INT_MAX; // Sabse chota element track karne ke liye
                int ans_index = 0;     // Sabse chote element ka index store karne ke liye

                while (low <= high) {
                    int mid = low + (high - low) / 2;

                    // Shortcut: Agar poora sub-array sorted mil gaya (koi break nahi hai)
                    if (arr[low] <= arr[high]) {
                        if (arr[low] < min_val) {
                            min_val = arr[low];
                            ans_index = low;
                        }
                        break; // Jab poora part sorted hai, toh aage dhoondne ki zaroorat nahi
                    }

                    // Case 1: Agar sirf Left Part sorted hai
                    if (arr[low] <= arr[mid]) {
                        // Left sorted hai, toh iska sabse chota element arr[low] hoga
                        if (arr[low] < min_val) {
                            min_val = arr[low];
                            ans_index = low;
                        }
                        // Kyunki left ka minimum check ho chuka hai, ab bache hue right part me dhoondo
                        low = mid + 1;
                    } 
                    // Case 2: Agar sirf Right Part sorted hai
                    else {
                        // Right sorted hai, toh iska sabse chota element khud arr[mid] hoga
                        if (arr[mid] < min_val) {
                            min_val = arr[mid];
                            ans_index = mid;
                        }
                        // Kyunki right ka minimum check ho chuka hai, ab bache hue left part me dhoondo
                        high = mid - 1;
                    }
                }

                return ans_index; // Minimum element ka index hi rotation count (k) hai
    }
};
