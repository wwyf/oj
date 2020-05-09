/*
 * @lc app=leetcode.cn id=1352 lang=cpp
 *
 * [1352] 最后 K 个数的乘积
 */

// @lc code=start
class ProductOfNumbers {
    int allProduct;
    // products[n]表示前n个数的乘积，[0]始终为1
    // 在出现0之后，表示在最后一个0之后的数据的乘积
    int products[40001];
    // 表示列表中数组的长度
    int len;
    // 表示最后一个0出现的位置，若为0则没有0。
    int zeroPos = 0;
public:
    ProductOfNumbers() {
        allProduct = 1;
        for (int i = 0; i < 40001; i++){
            products[i] = 1;
        }
        len = 0;
    }
    
    void add(int num) {
        len++;
        if (num == 0){
            zeroPos = len;
            allProduct = 1;
            products[len] = 1;
        } else {
            allProduct *= num;
            products[len] = products[len-1] * num;
        }
    }
    
    int getProduct(int k) {
        if (len-k+1 <= zeroPos){
            return 0;
        } else {
            return allProduct/products[len-k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

