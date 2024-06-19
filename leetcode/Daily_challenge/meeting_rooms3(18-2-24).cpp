#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ll maxBooked=-1, currRoom, currEndTime, mostBookedRoom;
        sort(meetings.begin(), meetings.end());
        priority_queue<ll, vector<ll>, greater<ll>> meeetingRooms;
        for(int i=0; i<n; i++){
            meeetingRooms.push(i);
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> meeetingRoomsTime;
        vector<ll> roomMeetingCnt(n, 0);
        for(int i=0; i<meetings.size(); i++){
            if(meeetingRoomsTime.empty()){
                currRoom = meeetingRooms.top();
                roomMeetingCnt[currRoom]+=1;
                meeetingRooms.pop();
                meeetingRoomsTime.push(make_pair(meetings[i][1], currRoom));
            }
            else{
                if(meetings[i][0]>=meeetingRoomsTime.top().first){
                    while(!meeetingRoomsTime.empty() && meetings[i][0]>=meeetingRoomsTime.top().first){
                        currRoom = meeetingRoomsTime.top().second;
                        meeetingRooms.push(currRoom);
                        meeetingRoomsTime.pop();
                    }
                    currRoom = meeetingRooms.top();
                    roomMeetingCnt[currRoom]+=1;
                    meeetingRooms.pop();
                    meeetingRoomsTime.push(make_pair(meetings[i][1], currRoom));
                }
                else{
                    if(!meeetingRooms.empty()){
                        currRoom = meeetingRooms.top();
                        roomMeetingCnt[currRoom]+=1;
                        meeetingRooms.pop();
                        meeetingRoomsTime.push(make_pair(meetings[i][1], currRoom));
                    }
                    else{
                        currRoom = meeetingRoomsTime.top().second;
                        currEndTime = meeetingRoomsTime.top().first;
                        roomMeetingCnt[currRoom]+=1;
                        meeetingRoomsTime.pop();
                        meeetingRoomsTime.push(make_pair(meetings[i][1]-meetings[i][0]+currEndTime, currRoom));
                    }
                }
            }
        }
        for(int i=0; i<roomMeetingCnt.size(); i++){
            if(roomMeetingCnt[i]>maxBooked){
                maxBooked=roomMeetingCnt[i];
                mostBookedRoom = i;
            }
        }
        return mostBookedRoom;
    }
};