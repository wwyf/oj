/*
 * @lc app=leetcode.cn id=1195 lang=cpp
 *
 * [1195] 交替打印字符串
 */



// @lc code=start
class FizzBuzz {
private:
	int n;
	mutex a, b, c, d;

public:
	FizzBuzz(int n) {
		this->n = n;
		b.lock();
		c.lock();
		d.lock();
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		for (int i = 1; i <= n; ++i)
		{
			a.lock();
			if (i % 3 == 0&&i % 15!=0)printFizz();
			b.unlock();
		}
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		for (int i = 1; i <=n; ++i)
		{
			b.lock();
			if (i % 5 == 0&&i%15!=0)printBuzz();
			c.unlock();
		}
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		for (int i = 1; i <= n; ++i)
		{
			c.lock();
			if (i % 15==0)printFizzBuzz();
			d.unlock();
		}
    }
	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		for (int i = 1; i <= n; ++i)
		{
			d.lock();
			if (i % 3 != 0 && i % 5 != 0)printNumber(i);
			a.unlock();
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
