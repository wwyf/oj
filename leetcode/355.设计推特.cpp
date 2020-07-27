/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
// @lc code=start
typedef struct Tweet{
    int ts;
    int tweedId;
} tweet_t;
class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, set<int>> userMap; // userId->set(userId)
    unordered_map<int, vector<tweet_t>> tweetMap; // userId->vector<tweet_t>
    int ts; // timestamp
    Twitter() {
        userMap = unordered_map<int, set<int>>{};
        tweetMap = unordered_map<int, vector<tweet_t>>{};
        ts = 0; // FIXME
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back(tweet_t{this->ts, tweetId});
        this->ts += 1; // BUG !
        // FIXME : 控制在每个用户都只存10个推文
        // if (tweetMap[userId].size() > 10){

        // }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // 1. get userIds
        auto userIds = userMap[userId];
        userIds.insert(userId);

        // 2. get all tweet
        vector<tweet_t> allTweets;
        for (auto id : userIds){
            allTweets.insert(allTweets.begin(), tweetMap[id].begin(), tweetMap[id].end());
        }

        // 3. sort
        sort(allTweets.begin(), allTweets.end(),
            [](const tweet_t & l, const tweet_t & r)->bool 
            {
                return l.ts > r.ts;
            });
        
        // 4. get 10 most newest tweet
        vector<int>ans;
        for (int i = 0; i<allTweets.size() && i < 10; i++){
            ans.push_back(allTweets[i].tweedId);
        }
        return ans;

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        userMap[followerId].emplace(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        userMap[followerId].erase(followeeId);
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
// @lc code=end

