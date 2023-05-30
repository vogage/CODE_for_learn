//
//  355_Design Twitter.cpp
//  leetcode
//
//  Created by qiandehou on 2021/4/5.
//

#include <stdio.h>
#include<vector>
#include<unordered_set>
#include <unordered_map>

using namespace std;

//class Twitter {
//public:
//    /** Initialize your data structure here. */
//    Twitter() {
//        
//    }
//    
//    /** Compose a new tweet. */
//    void postTweet(int userId, int tweetId) {
//        fowid[userId].insert(userId);
//        fowid2[userId].insert(userId);
//        
//        twid[tweetId]=userId;
//        newsfd.push_back(tweetId);
//    }
//    
//    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
//    vector<int> getNewsFeed(int userId) {
//        vector<int> out;
//        int count=0;
//        
//        int indx=newsfd.size()-1;
//        while(indx>=0&&count<10){
//            int tw=newsfd[indx];
//            if(fowid2[userId].find(twid[tw])!=fowid2[userId].end()){
//                out.push_back(tw);
//                count++;
//            }
//            indx--;
//            
//        }
//        return out;
//    }
//    
//    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
//    void follow(int followerId, int followeeId) {
//        fowid[followeeId].insert(followerId);
//        fowid2[followerId].insert(followeeId);
//    }
//    
//    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
//    void unfollow(int followerId, int followeeId) {
//        unordered_set<int>::iterator it=fowid[followeeId].find(followerId);
//        if(it!=fowid[followeeId].end())fowid[followeeId].erase(it);
//        unordered_set<int>::iterator it2=fowid2[followerId].find(followeeId);
//        if(it2!=fowid2[followerId].end())fowid2[followerId].erase(it2);
//    }
//private:
//    vector<int> newsfd;
//    unordered_map<int, int> twid;
//    unordered_map<int, unordered_set<int>> fowid2;
//    unordered_map<int, unordered_set<int>> fowid;
//   // unordered_map<int, unordered_set<int>> unfollow_id;
//};

class Twitter
{
    struct Tweet
    {
        int time;
        int id;
        Tweet(int time, int id) : time(time), id(id) {}
    };

    std::unordered_map<int, std::vector<Tweet>> tweets; // [u] = array of tweets by u
    std::unordered_map<int, std::unordered_set<int>> following; // [u] = array of users followed by u

    int time;

public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].emplace_back(time++, tweetId);
    }

    std::vector<int> getNewsFeed(int userId)
    {
        std::vector<std::pair<Tweet*, Tweet*>> h; // pair of pointers (begin, current)

        for (auto& u: following[userId])
        {
            auto& t = tweets[u];
            if (t.size() > 0)
                h.emplace_back(t.data(), t.data() + t.size() - 1);
            //vector_name.data()
            //The function returns a pointer to the first element in the array which is used internally by the vector.
        }
        auto& t = tweets[userId]; // self
        if (t.size() > 0)
            h.emplace_back(t.data(), t.data() + t.size() - 1);

        auto f = [](const std::pair<Tweet*, Tweet*>& x, const std::pair<Tweet*, Tweet*>& y) {
            return x.second->time < y.second->time;
        };
        std::make_heap(h.begin(), h.end(), f);

        const int n = 10;
        std::vector<int> o;
        o.reserve(n);
        //reserve which helps user specify the minimum size of the vector.It indicates that the vector is created such that it can store at least the number of the specified elements without having to reallocate memory.
        for (int i = 0; (i < n) && !h.empty(); ++i)
        {
            std::pop_heap(h.begin(), h.end(), f);
            //using pop_heap() to reorder elements
            //This function is used to delete the maximum element of the heap. The size of heap is decreased by 1. The heap elements are reorganised accordingly after this operation
            auto& hb = h.back();
            o.push_back(hb.second->id);

            if (hb.first == hb.second--)
                h.pop_back();
            else
                std::push_heap(h.begin(), h.end(), f);
            //using push_heap() to reorder elements
            //This function is used to insert elements into heap. The size of the heap is increased by 1. New element is placed appropriately in the heap.
        }
        return o;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};

int main(){
//    Twitter twitter;
//    twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
//    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
//    twitter.follow(1, 2);    // User 1 follows user 2.
//    twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
//    vector<int> res=twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
//    twitter.unfollow(1, 2);  // User 1 unfollows user 2.
//    vector<int> res2=twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
    
    
    
    
//
//    Twitter twitter2;
//    //["Twitter","postTweet","getNewsFeed","follow","getNewsFeed","unfollow","getNewsFeed"]
//   // [[],[1,1],[1],[2,1],[2],[2,1],[2]]
//    twitter2.postTweet(1, 1);
//    twitter2.getNewsFeed(1);
//    twitter2.follow(2, 1);
//    vector<int> res=twitter2.getNewsFeed(2);
//    twitter2.unfollow(2, 1);
//    vector<int> res2=twitter2.getNewsFeed(2);
    
    
    
    
    
    
    
    
//  //  ["Twitter","postTweet","postTweet","unfollow","getNewsFeed"]
//  //  [[],[1,4],[2,5],[1,2],[1]]
//    Twitter twitter3;
//    twitter3.postTweet(1, 4);
//    twitter3.postTweet(2, 5);
//    twitter3.unfollow(1, 2);
//    vector<int> res=twitter3.getNewsFeed(1);
//
    
    Twitter twitter4;
//    ["Twitter","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed","follow","getNewsFeed","unfollow","getNewsFeed"]
//    [[],[1,5],[2,3],[1,101],[2,13],[2,10],[1,2],[1,94],[2,505],[1,333],[2,22],[1,11],[1,205],[2,203],[1,201],[2,213],[1,200],[2,202],[1,204],[2,208],[2,233],[1,222],[2,211],[1],[1,2],[1],[1,2],[1]]
    
    twitter4.postTweet(1, 5);
    twitter4.postTweet(2, 3);
    twitter4.postTweet(1, 101);
    twitter4.postTweet(2, 13);
    twitter4.postTweet(2, 10);
    twitter4.postTweet(1, 2);
    twitter4.postTweet(1, 94);
    twitter4.postTweet(2, 505);
    twitter4.postTweet(1, 333);
    twitter4.postTweet(2, 22);
    twitter4.postTweet(1, 11);
    twitter4.postTweet(1, 205);
    twitter4.postTweet(2, 203);
    twitter4.postTweet(1, 201);
    
    twitter4.getNewsFeed(1);
    
    twitter4.follow(2, 1);
    
    twitter4.getNewsFeed(2);
    
    
    
    
    return 0;
}
