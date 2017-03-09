package lesson8;

class noSyned {
  public static void main(String args[]) {
    Thread t1,t2,t3;
    t1 = new Thread(new NoCallee("Hello"));
    t2 = new Thread(new NoCallee("Synchronized"));
    t3 = new Thread(new NoCallee("World"));
    t1.start();
    t2.start();
    t3.start();
  }
}

class NoCallee implements Runnable {
  String msg;
  public NoCallee(String msg) {
    this.msg = msg;
  }

  public void run() {
    call(msg);
  }

  static void call(String s) {
    System.out.print("["+s);
    try {
      Thread.sleep(100);
    }catch (Exception e) {}
    System.out.print("]");
  }
}

