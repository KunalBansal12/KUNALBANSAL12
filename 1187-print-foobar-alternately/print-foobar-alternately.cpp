class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int j;
public:
    FooBar(int n) {
        this->n = n;
        j=0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            cv.wait(lock,[&]{return !(j%2);});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            j++;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            cv.wait(lock,[&]{return (j%2);});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            j++;
            cv.notify_one();
        }
    }
};