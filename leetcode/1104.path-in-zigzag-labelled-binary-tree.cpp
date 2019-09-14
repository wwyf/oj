/*
 * @lc app=leetcode id=1104 lang=cpp
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 *
 * https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/
 *
 * algorithms
 * Medium (70.38%)
 * Likes:    108
 * Dislikes: 87
 * Total Accepted:    7.8K
 * Total Submissions: 11.1K
 * Testcase Example:  '14'
 *
 * In an infinite binary tree where every node has two children, the nodes are
 * labelled in row order.
 * 
 * In the odd numbered rows (ie., the first, third, fifth,...), the labelling
 * is left to right, while in the even numbered rows (second, fourth,
 * sixth,...), the labelling is right to left.
 * 
 * 
 * 
 * Given the label of a node in this tree, return the labels in the path from
 * the root of the tree to the node with that label.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: label = 14
 * Output: [1,3,4,14]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: label = 26
 * Output: [1,2,6,10,26]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= label <= 10^6
 * 
 * 
 */
/*
仔细想想，如果没有翻转顺序其实很容易算
即便是翻转了顺序，其实也可以用类似的方法来算（反正我能够根据层数知道我自己有没有被翻转）
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int x = log2(label)+1;
        vector <int> result;
        result.push_back(label);
        x--;
        while(x)
        {
            int n = result.size();
            if(x%2==1)
            {
                int temp =3*pow(2,x)-1;
                temp -= result[n-1];
                result.push_back(temp/2);
            }
            else
            {
                int temp = 3*pow(2,x-1)-result[n-1]/2-1;
                result.push_back(temp);
            }
            x--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

/*
https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/381754/Easy-to-understand-C%2B%2B-solutions
*/

