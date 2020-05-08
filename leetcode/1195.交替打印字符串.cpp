/*
 * @lc app=leetcode.cn id=1195 lang=cpp
 *
 * [1195] 交替打印字符串
 */



// @lc code=start
class FizzBuzz {
private:
    int n;
atomic<int> i;
public:
    FizzBuzz(int n) {
        this->n = n;
        i.store(1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i.load(memory_order_acquire)<=n){
            if(i%3==0 && i%5!=0){
                printFizz();
                ++i;
            }else this_thread::yield();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
       while(i.load(memory_order_acquire)<=n){
            if(i%3!=0 && i%5==0){
                printBuzz();
                ++i;
            }else
             this_thread::yield();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
       while(i.load(memory_order_acquire)<=n){
            if(i%3==0 && i%5==0){
                printFizzBuzz();
                ++i;
            } else
            this_thread::yield();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
       while(i.load(memory_order_acquire)<=n){
            if(i%3!=0 && i%5!=0){
                printNumber(i);
                ++i;
            }
            else
            this_thread::yield();
        }
    }
};

// @lc code=end

int main(int argc, char** argv){
    FizzBuzz fizzBuzz(15);

    std::function<void()> printFizz = [](){printf(" fizz ");};
    std::function<void()> printBuzz = [](){printf(" buzz ");};
    std::function<void()> printFizzBuzz = [](){printf(" fizzbuzz ");};
    std::function<void(int)> printNum = [](int x){printf(" %d ", x);};

    std::thread th[4];
    th[0] = std::thread(&FizzBuzz::fizz, &fizzBuzz, printFizz);
    th[1] = std::thread(&FizzBuzz::buzz, &fizzBuzz, printBuzz);
    th[2] = std::thread(&FizzBuzz::fizzbuzz, &fizzBuzz, printFizzBuzz);
    th[3] = std::thread(&FizzBuzz::number, &fizzBuzz, printNum);

    for(auto &ts : th) {
        if(ts.joinable()) ts.join();
    }

    return 0;
}
