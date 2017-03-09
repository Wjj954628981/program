package lesson7;
import java.io.*;

public class Copy {
  /** Main method
     @param args[0] for sourcefile 
     @param args[1] for target file
   */
  public static void main(String[] args) throws IOException { 
    // Check command-line parameter usage
    if (args.length != 2) { 
      System.out.println(
        "Usage: java Copy sourceFile targetfile");
      System.exit(0);
    }

    // Check if source file exists
    File sourceFile = new File(args[0]);
    if (!sourceFile.exists()) {
       System.out.println("Source file " + args[0] + " not exist");
       System.exit(0);
    }

    // Check if target file exists
    File targetFile = new File(args[1]);
    if (targetFile.exists()) {
      System.out.println("Target file " + args[1] + " already exists");
      //System.exit(0);
      targetFile.delete();
    }

    // Create an input stream
    BufferedInputStream input = 
      new BufferedInputStream(new FileInputStream(sourceFile));

    // Create an output stream
    BufferedOutputStream output = 
      new BufferedOutputStream(new FileOutputStream(targetFile));

    // Continuously read a byte from input and write it to output
    int r; int numberOfBytesCopied = 0;
    long begintime=System.currentTimeMillis();
    while ((r = input.read()) != -1) {
      output.write((byte)r);
      numberOfBytesCopied++;
    }

    // Close streams
    input.close();
    output.close();
    long endtime=System.currentTimeMillis();
    // Display the file size
    System.out.println(numberOfBytesCopied + " bytes copied, used "+((endtime-begintime)/1000)+"second.");
    targetFile = new File(args[1]);
    if (targetFile.exists()) {
      System.out.println("Target file " + args[1] + " already exists");
      //System.exit(0);
      targetFile.delete();
    }
    FileInputStream finput = 
    	      (new FileInputStream(sourceFile));

    	    // Create an output stream
    FileOutputStream foutput = 
    	      (new FileOutputStream(targetFile));

    	    // Continuously read a byte from input and write it to output
    	   
    	     begintime=System.currentTimeMillis();
    	     numberOfBytesCopied=0;
    	    while ((r = finput.read()) != -1) {
    	    	foutput.write((byte)r);
    	      numberOfBytesCopied++;
    	    }

    	    // Close streams
    	    finput.close();
    	    foutput.close();
    	     endtime=System.currentTimeMillis();
    	    // Display the file size
    	    System.out.println(numberOfBytesCopied + " bytes copied, used "+((endtime-begintime)/1000)+"second.");
    	  
  }
}
