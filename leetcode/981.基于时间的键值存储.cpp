/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
bool comp(const pair<int, string> & a, const pair<int, string> & b) {
    return a.first < b.first;
}
class TimeMap {
public:
    map<string, vector< pair<int, string> > > m;
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        // auto compare = [](pair<int, string> & a, pair<int, string> & b){return a.first < b.first;};
        auto & list = m[key];
        // 找到list中第一个大于timestamp的迭代器
        auto i = upper_bound(list.begin(), list.end(), pair<int, string>(timestamp, value), comp);
        list.insert(i, pair<int, string>(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        // auto compare = [](pair<int, string> & a, pair<int, string> & b){return a.first < b.first;};
        auto i = m.find(key);
        string ans = "";
        if (i == m.end()){
            return ans;
        } else {
            auto & list = m[key];
            // 找到第一个大于timestamp的迭代器，这个的前一个就是我们想要的
            auto i = upper_bound(list.begin(), list.end(), pair<int, string>(timestamp, ""), comp) - list.begin();
            if (i != 0){
                ans = list[i-1].second;
            }
            return ans;
        }

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
int main(){
    TimeMap kv = TimeMap();
    kv.set("foo", "bar", 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1   
    cout << kv.get("foo", 1);  // 输出 "bar"   
    cout << kv.get("foo", 3); // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）   
    kv.set("foo", "bar2", 4);   
    cout << kv.get("foo", 4); // 输出 "bar2"   
    cout << kv.get("foo", 5); // 输出 "bar2"  ;
    cout << endl;
}