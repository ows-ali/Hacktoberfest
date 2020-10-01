class DiningPhilosophers {

    Semaphore[] sem;
    public DiningPhilosophers() {
        sem=new Semaphore[5];
        for(int i=0;i<5;i++){
            sem[i]=new Semaphore(1);
        }
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
          int i=philosopher;
          if(i==4){
                sem[(i+1)%5].acquire();
                sem[i].acquire();
                
                pickRightFork.run();
                pickLeftFork.run();
                eat.run();
                putRightFork.run();
                putLeftFork.run();
                
                sem[(i+1)%5].release();
                sem[i].release();
            }
            
            else 
            {
                sem[i].acquire();
                sem[(i+1)%5].acquire();
                
                pickLeftFork.run();
                pickRightFork.run();
                eat.run();
                putLeftFork.run();
                putRightFork.run();
                
                sem[i].release();
                sem[(i+1)%5].release();
            }
        
    }
}