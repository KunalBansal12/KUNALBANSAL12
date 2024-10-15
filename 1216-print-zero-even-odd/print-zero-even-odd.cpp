class ZeroEvenOdd {
private:
    int n;
    int state;
    int curr;
    condition_variable cv;
    mutex m1;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        state=0;
        curr=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[&]{return state==0;});
            printNumber(0);
            state=(curr%2 ? 1:2);
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+= 2) {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[&]{return state==2;});
            printNumber(i);
            curr++;
            state=0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+= 2) {
            unique_lock<mutex> lock(m1);
            cv.wait(lock,[&]{return state==1;});
            printNumber(i);
            curr++;
            state=0;
            cv.notify_all();
        }
    }
};

/*
class ZeroEvenOdd {
private:
    int n;
    mutex m1,m2,m3;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        m2.lock();
        m3.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            m1.lock();
            printNumber(0);
            if (i%2 == 0)
                m2.unlock();
            else
                m3.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+= 2) {
            m2.lock();
            printNumber(i);
            m1.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+= 2) {
            m3.lock();
            printNumber(i);
            m1.unlock();
        }
    }
};
*/