package lesson8;

public class TaskThreadDemo1 {
	  public static void main(String[] args) {
	    // Create threads
		Thread printA = new PrintCharT('a', 100);
		Thread printB = new PrintCharT('b', 100);
		Thread print100 = new PrintNumT(100);

	   
	    // Start threads
		printA.start();
		printB.start();
		print100.start();
	  }
	}

	// The task for printing a specified character in specified times
	class PrintCharT extends Thread {
	  private char charToPrint; // The character to print
	  private int times; // The times to repeat

	  /** Construct a task with specified character and number of
	   *  times to print the character
	   */
	  public PrintCharT(char c, int t) {
	    charToPrint = c;
	    times = t;
	  }

	  /** Override the run() method to tell the system
	   *  what the task to perform
	   */
	  public void run() {
	    for (int i = 0; i < times; i++) {
	      System.out.print(charToPrint);
	    }
	  }
	}

	// The task class for printing number from 1 to n for a given n
	class PrintNumT extends Thread  {
	  private int lastNum;

	  /** Construct a task for printing 1, 2, ... i */
	  public PrintNumT(int n) {
	    lastNum = n;
	  }

	  /** Tell the thread how to run */
	  public void run() {
	    for (int i = 1; i <= lastNum; i++) {
	      System.out.print(" " + i);
	    }
	  }
	}