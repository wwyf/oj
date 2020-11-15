#include <vector>
#include <string>
using namespace std;

class OrderedStream {
public:
    vector<string> ss;
    int cur;
    OrderedStream(int n) {
        ss = vector<string>(n,"");
        cur = 0;
    }
    
    vector<string> insert(int id, string value) {
        int tid = id-1;
        ss[tid] = value;;
        if (tid != cur){
            return vector<string>();
        } else {
            // get cur string list
            vector<string> ans;
            while(cur < ss.size() && ss[cur].size() > 0){
                ans.push_back(ss[cur]);
                cur++;
            }
            return ans;
        }
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */

int main(){
    OrderedStream* os= new OrderedStream(5);
    os->insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
    os->insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
    os->insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
    os->insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
    os->insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
}