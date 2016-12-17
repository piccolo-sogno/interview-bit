// Hotel Booking Possible - interviewBit
// Developed by: piccolo-sogno
//
// Problem: A hotel manager has to process N advance bookings of rooms for the next season. 
//          His hotel has K rooms. Bookings contain an arrival date and a departure date. 
//          He wants to find out whether there are enough rooms in the hotel to satisfy the demand.
//          Write a program that solves this problem in time O(N log N).
//
// Input : First list for arrival time of booking.
//         Second list for departure time of booking.
//         Third is K which denotes count of rooms.
//
// Input : 
//        Arrivals :   [1 3 5]
//        Departures : [2 6 8]
//        K : 1
// Return : False / 0 
// At day = 5, there are 2 guests in the hotel. But I have only one room. 

// Solution approach: Put all arrival times into multiset with time and 'S'. where 'S' denotes start time.
//                    Put all departure times into same multiset with time and 'E', where 'E' denotes end time.
//                    Since multiset orders values in ascending time order, increment value when 'S' times seen.
//                    Decrement value when 'E' times seen.
//                    If count is more than given K value in any time, return false.

bool Solution::hotel(vector<int> &a, vector<int> &d, int k) {

  if( (k == 0) || (a.size()==0) || (d.size() == 0)
     return false;
	
  int currBook = 0;
  multiset<pair<int,char>> mset;
	
  for(int i=0; i<a.size(); i++) {
      mset.emplace(a[i], 'S');
      mset.emplace(d[i], 'E');
  }
	
  for (auto it=mset.begin(); it != mset.end(); it++){
      if (it->second == 'S')
	  currBook++;
      else
	  currBook--;

      if(currBook > k)
	  return false;
  }
	
  return true;
}
