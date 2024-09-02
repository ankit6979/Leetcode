#include<bits/stdc++.h>
usimg namespace std;

class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> user_tweets;
    unordered_map<int, unordered_set<int>> following;
    int timestamp;
    Twitter() : timestamp(0){
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].emplace_back(make_pair(timestamp++, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> latest_tweets;
        int count = 0;
        priority_queue<pair<int, int>> max_heap;

        for(const auto& tweet : user_tweets[userId]) {
            max_heap.push(tweet);
        }
        for(int followeeId : following[userId]) {
            for(const auto& tweet : user_tweets[followeeId]) {
                max_heap.push(tweet);
            }
        }

        while(!max_heap.empty() && count < 10) {
            latest_tweets.emplace_back(max_heap.top().second);
            max_heap.pop();
            count++;
        }

        return latest_tweets;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */