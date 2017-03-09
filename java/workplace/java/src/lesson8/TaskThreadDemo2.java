package lesson8;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

public class TaskThreadDemo2 {
	 public static void main(String[] args) {
		    // Create threads
		   FutureTask<Integer> ft1=new FutureTask<Integer>(new PrintCharc('a', 100));
		   
		   FutureTask<Integer> ft2=new FutureTask<Integer>(new PrintCharc('b', 100));
		   FutureTask<Integer> ft3=new FutureTask<Integer>(new PrintNumc( 100));



		    Thread printA = new Thread (ft1);
		    Thread printB = new Thread (ft2);
		    Thread print100 = new Thread (ft3);
			

		   
		    // Start threads
			printA.start();
			printB.start();
			print100.start();
			try {
				Integer i1=ft1.get();
				System.out.println("[1]endl "+i1);
				System.out.println("test");
				Integer i2=ft2.get();
				System.out.println("[2]endl "+i2);
				Integer i3=ft3.get();
				System.out.println("[3]endl "+i3);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (ExecutionException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
			
		  }
		}

		// The task for printing a specified character in specified times
		class PrintCharc implements Callable<Integer> {
		  private char charToPrint; // The character to print
		  private int times; // The times to repeat

		  /** Construct a task with specified character and number of
		   *  times to print the character
		   */
		  public PrintCharc(char c, int t) {
		    charToPrint = c;
		    times = t;
		  }

		  /** Override the call() method to tell the system
		   *  what the task to perform
		   */


		@Override
		public Integer call() throws Exception {
			// TODO Auto-generated method stub
			for (int i = 0; i < times; i++) {
			      System.out.print(charToPrint);
			      Thread.sleep(5);
			    }
			return new Integer(0);
		}
		}

		// The task class for printing number from 1 to n for a given n
		class PrintNumc implements Callable<Integer>  {
		  private int lastNum;

		  /** Construct a task for printing 1, 2, ... i */
		  public PrintNumc(int n) {
		    lastNum = n;
		  }

		  /** Tell the thread how to run */


		@Override
		public Integer call() throws Exception {
			// TODO Auto-generated method stub
			for (int i = 1; i <= lastNum; i++) {
			      System.out.print(" " + i);
			    }
			return new Integer(0);
		}
}
