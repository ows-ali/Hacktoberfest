class FooBar {
    private int n;

    public FooBar(int n) {
        this.n = n;
        semFoo=new Semaphore(1);
        semBar=new Semaphore(0);
    }

    
    private Semaphore semFoo;
    private Semaphore semBar;
    
    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            semFoo.acquire();
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            semBar.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            semBar.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            semFoo.release();
        }
    }
}