class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i = 0,j = 0;
        int current_rooms = 0, max_rooms = 0;
        while(i < start.size()){
            if(start[i] < end[j]){
                current_rooms++;
                i++;
            }
            else{
                current_rooms--;
                j++;
            }
            max_rooms = max(max_rooms, current_rooms);
        }
        
        return max_rooms;
    }
};
