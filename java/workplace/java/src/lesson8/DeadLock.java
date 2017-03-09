package lesson8;

class classA {
    public classB b;

    synchronized void methoda() {
        String name = Thread.currentThread().getName();

        b.methodb();
    }

    synchronized void methodb() {
        System.out.println( " inside classA.mothedb() " );
    }
}

class classB {
    public classA a;

    synchronized void methoda() {
        String name = Thread.currentThread().getName();
       
        a.methodb();
    }

    synchronized void methodb() {
        System.out.println( " inside classB.mothedb() " );
    }
}

class DeadLock implements Runnable  {
    classA a = new classA();
    classB b = new classB();

    DeadLock()  {
        a.b = b;
        b.a = a;
        new Thread( this ).start();
        a.methoda();
        }

    public void run()   {
        b.methoda();
        }

    public static void main( String args[] )    {
        new DeadLock();
    }
}
