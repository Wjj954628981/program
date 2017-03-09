package lesson8;

import java.util.Vector;
class Producer extends Thread {
  static final int MAXQUEUE = 5;
   Vector messages = new Vector();

  public void run() {
    try {
      while (true) {
        putMessage();
        sleep(500);
      }
    }catch (InterruptedException e) {}
  }

  private synchronized void putMessage()
             throws InterruptedException {
    while (messages.size() == MAXQUEUE)
    { System.out.println(messages.size());
         wait();}
    messages.addElement(new java.util.Date().toString());
    notify();
  }

  public synchronized String getMessage()
             throws InterruptedException {
    while (messages.size() == 0 ) wait();
    String message = (String)messages.firstElement();
    messages.removeElement(message);
    notify();
    return message;
  }
}

class Consumer extends Thread {
  Producer producer;
  Consumer(Producer p) {
    producer = p;
  }

  public void run() {
    try {
      while (true) {
        String message = producer.getMessage();
        System.out.println("Got message:"+message+producer.messages.size());
        sleep(500);
      }
    }catch (InterruptedException e) {}
  }

  public static void main(String args[]) {
    Producer producer = new Producer();
    producer.start();
    new Consumer(producer).start();
  }
}