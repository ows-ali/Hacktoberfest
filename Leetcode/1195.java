class FizzBuzz {
    private int n;
    private Semaphore fbSem, bSem, fSem, nSem;
    public FizzBuzz(int n) {
        this.n = n;
        fbSem=new Semaphore(0);
        bSem=new Semaphore(0);
        fSem=new Semaphore(0);
        nSem=new Semaphore(1);
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        while(fSem.tryAcquire(1,100,TimeUnit.MILLISECONDS)){
            printFizz.run();
            nSem.release();
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        while(bSem.tryAcquire(1,100,TimeUnit.MILLISECONDS)){
            printBuzz.run();
            nSem.release();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while(fbSem.tryAcquire(1,100,TimeUnit.MILLISECONDS)){
            printFizzBuzz.run();
            nSem.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i++){
            nSem.acquire();
            if(i%15==0)
            {
                fbSem.release();
            }
            else if(i%3==0)
            {
                fSem.release();
            }
            else if(i%5==0){
                bSem.release();
            }
            else {
                System.out.println(i);
                printNumber.accept(i);
                nSem.release();
            }
            
        }
    }
}