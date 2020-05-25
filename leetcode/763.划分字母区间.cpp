/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
using namespace std;

// @lc code=start
struct Segment{
    int len;
    int index;
    set<char> charSet;
};
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int strLen = S.size();
        if (strLen <= 1){
            return vector<int>{strLen};
        }
        // 获得last数组,last[c]为c最后出现的index
        map<char, int> last;
        for (int i = 0; i < strLen; i++){
            last[S[i]] = i;
        }
        vector<int> ans;
        int curRight = 0;
        int curLeft = 0;
        for (int i = 0; i < strLen; i++){
            // 加入新字符，扩展右边界
            curLeft = last[S[i]] > curLeft? last[S[i]] : curLeft;
            // 如果i == curLeft
            if (i == curLeft){
                ans.push_back(curLeft - curRight+1);
                curRight = curLeft+1;
            }
        }
        return ans;
    }
    vector<int> partitionLabels2(string S) {
        int strLen = S.size();
        if (strLen <= 1){
            return vector<int>{strLen};
        }
        int segmentCount = 1;
        Segment segs[501];
        segs[0].len = 1;
        segs[0].index = 1;
        segs[0].charSet.insert(S[0]);
        for (int i = 1; i < strLen; i++){
            // 判断新来的字母是否要增加一段（看看是否出现在前面的哈希表中）
            int occurSegIndex = -1; // 是否出现及出现在哪一段？
            for (int j = 0; j < segmentCount; j++){
                if (segs[j].charSet.find(S[i]) != segs[j].charSet.end()){
                    occurSegIndex = j;
                    break;
                }
            }
            // cout << occurSegIndex << endl;
            if (occurSegIndex >= 0){
                // 如果出现，那就合并
                // 合并的左右段序号分别是 occurSegIndex 开始，到后面的所有字母
                segs[occurSegIndex].len += i+1 - segs[occurSegIndex].index;
                for (int k = segs[occurSegIndex].index; k <= i; k++){
                    segs[occurSegIndex].charSet.insert(S[k]);
                }
                segs[occurSegIndex].index = i+1;
                // 少了这么多段
                segmentCount = occurSegIndex+1;

            } else {
                // 否则新加一段
                segs[segmentCount].len = 1;
                segs[segmentCount].index = i+1;
                segs[segmentCount].charSet.insert(S[i]);
                segmentCount++;
            }
        }

        vector<int> ans;
        for (int i = 0; i < segmentCount; i++){
            ans.push_back(segs[i].len);
        }

        return ans;
    }
};
// @lc code=end


int main(){
    auto ans = Solution{}.partitionLabels("ababcbacadefegdehijhklij");
    for (auto i : ans){
        cout << " " << i << endl;
    }
}