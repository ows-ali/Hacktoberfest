class H2O {

    Semaphore oxygen;
    Semaphore hydrogen;
    AtomicInteger hydCount;
    public H2O() {
        oxygen=new Semaphore(1);
        hydrogen=new Semaphore(2);
        hydCount=new AtomicInteger(0);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        hydrogen.acquire();
        hydCount.set(hydCount.get()+1);
        releaseHydrogen.run();
        if(hydCount.get()==2){
            oxygen.release();
            hydCount.set(0);
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        
        oxygen.acquire();
        System.out.println("O");
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        hydrogen.release(2);
    }
}