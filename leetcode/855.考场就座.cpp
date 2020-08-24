/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class ExamRoom {
public:
    set<int> s;
    int length;
    ExamRoom(int N) {
        s = set<int>{};
        length = N;
    }
    
    int seat() {
        int p = find_next_seat();
        if (p == -1){
            return -1;
        }
        s.insert(p);
        return p;
    }
    
    void leave(int p) {
        s.erase(p);
    }
    int find_next_seat(){
        if(s.empty()){
            return 0;
        }
        int prev = -1;
        int m_space = -1;
        int m_start_index = -1;
        int end_n;
        int start_n = *s.begin();
        for (auto n : s){
            end_n = n;
            if (prev == -1){
                prev = n;
                continue;
            }
            if (prev+1 == n){
                prev = n;
                continue;
            }
            int this_m_space = (n-1 -prev -1)/2;
            if (this_m_space > m_space){
                m_space = this_m_space;
                m_start_index = prev + m_space + 1 ;
            }
            prev = n;
        }
        int start_space = start_n-1;
        int end_space = length-1 - (end_n) - 1;
        if (start_space >= m_space && start_space >= end_space){
            return 0;
        }
        if (m_space >= end_space && m_space > start_space){
            return m_start_index;
        }
        if (end_space > start_space && end_space > m_space){
            return length-1;
        }
        return -1; 
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

int main(){
    // auto t = ExamRoom(10);
    // cout << t.seat() << endl;
    // cout << t.seat() << endl;
    // cout << t.seat() << endl;
    // cout << t.seat() << endl;
    // t.leave(4);
    // cout << t.seat() << endl;
    
    auto t = ExamRoom(4);
    cout << t.seat() << endl;
    cout << t.seat() << endl;
    cout << t.seat() << endl;
    cout << t.seat() << endl;
    t.leave(1);
    t.leave(3);
    cout << t.seat() << endl;

}
