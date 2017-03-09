package lesson8;

class ThreadTest{
    public static void main( String args [] ) {
        Runnable t1 = new MyThread("T1");
        Thread t2 = new Thread(t1);
        t2.start();
        Thread t3 = new Thread(new MyThread("t3"));
        t3.setPriority( Thread.MAX_PRIORITY );
        t3.start();
        //t1.setPriority( Thread.MIN_PRIORITY );
        //t1.start( );
        //Thread t2 = new MyThread("T2");
        //t2.setPriority( Thread.MAX_PRIORITY );
        //t2.start( );
       	       // Thread t3 = new MyThread("T3");
 	     //t3.setPriority( Thread.MAX_PRIORITY );
        //t3.start( );
    }
		}
class MyThread implements Runnable {
    String message;
    MyThread ( String message ) {
        this.message = message;
    }
    public void run() {
        for ( int i=0; i<10; i++ )
          System.out.println( message);
    }
		}
