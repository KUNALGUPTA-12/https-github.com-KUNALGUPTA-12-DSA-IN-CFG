class Solution {
  private:
    int findFirst(vector<int>& arr,int target){//& means ampersand nahi arr ki copy nahi banata hai usi mai change kart hai
       int low = 0,high = arr.size() - 1,first = -1;
       while(low <= high){
           int mid = low + (high - low) / 2;
           
           if(arr[mid] == target){
               first = mid;
               high = mid - 1;//because leftmai dekho ki auur toh duplites nahi hai
           }else if(arr[mid] < target){
               low = mid + 1;
           }else{
               high = mid - 1;
           }
       }
       return first;
   }
   int findLast(vector<int>& arr,int target){//& means ampersand nahi arr ki copy nahi banata hai usi mai change kart hai
       int low = 0,high = arr.size() - 1,last = -1;
       while(low <= high){
           int mid = low + (high - low) / 2;
           
           if(arr[mid] == target){
               last = mid;
               low = mid + 1;//because right mai dekho ki auur toh duplites nahi hai
           }else if(arr[mid] < target){
               low = mid + 1;
           }else{
               high = mid - 1;
           }
       }
       return last;
   }

  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = findFirst(arr,target);
        
        if(first == -1){
            return 0;
        }
        
        int last = findLast(arr,target);
        
        return(last - first) + 1;
    
    }
};
