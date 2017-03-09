package lesson8;

class Syned {
  public static void main(String args[]) {
    Thread t1,t2,t3;
    t1 = new Thread(new Callee("Hello"));
    t2 = new Thread(new Callee("Synchronized"));
    t3 = new Thread(new Callee("World"));
    t1.start();
    t2.start();
    t3.start();
  }
}

class Callee implements Runnable {
  String msg;
  public Callee(String msg) {
    this.msg = msg;
  }

  public void run() {
    call(msg);
  }

  synchronized static void call(String s) {
   	 
    System.out.print("["+s);
    try {
      Thread.sleep(100);
    }catch (Exception e) {}
    System.out.print("]");
  }
}

