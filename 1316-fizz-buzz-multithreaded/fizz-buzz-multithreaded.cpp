class FizzBuzz {
private:
    int n;
    mutex m1,m2,m3,m4;
public:
    FizzBuzz(int n) {
        this->n = n;
        m2.lock();
        m3.lock();
        m4.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i=3;i<=n;i=i+3){
            if(i%5==0) continue;
            m3.lock();
            printFizz();
            if((i+1)<=n){
                if((i+1)%3==0 && (i+1)%5==0) m2.unlock();
                else if((i+1)%3==0) m3.unlock();
                else if((i+1)%5==0) m4.unlock();
                else m1.unlock();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i=5;i<=n;i=i+5){
            if(i%3==0) continue;
            m4.lock();
            printBuzz();
            if((i+1)<=n){
                if((i+1)%3==0 && (i+1)%5==0) m2.unlock();
                else if((i+1)%3==0) m3.unlock();
                else if((i+1)%5==0) m4.unlock();
                else m1.unlock();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i=15;i<=n;i+=15){
            m2.lock();
            printFizzBuzz();
            if((i+1)<=n){
                if((i+1)%3==0 && (i+1)%5==0) m2.unlock();
                else if((i+1)%3==0) m3.unlock();
                else if((i+1)%5==0) m4.unlock();
                else m1.unlock();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            if(i%3==0 || i%5==0) continue;
            m1.lock();
            printNumber(i);
            if((i+1)<=n){
                if((i+1)%3==0 && (i+1)%5==0) m2.unlock();
                else if((i+1)%3==0) m3.unlock();
                else if((i+1)%5==0) m4.unlock();
                else m1.unlock();
            }
        }
    }
};