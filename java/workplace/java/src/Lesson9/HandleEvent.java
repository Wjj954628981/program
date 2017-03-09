package Lesson9;
import javax.swing.*;

import java.awt.Color;
import java.awt.event.*;

public class HandleEvent extends JFrame {
	 JButton jbtOK;
	 JButton jbtCancel;
  public HandleEvent() {
    // Create two buttons 
      jbtOK = new JButton("OK");
     jbtCancel = new JButton("Cancel");

    // Create a panel to hold buttons
    JPanel panel = new JPanel();
    panel.add(jbtOK);
    panel.add(jbtCancel);

    add(panel); // Add panel to the frame

    // Register listeners
    OKListenerClass listener1 = new OKListenerClass();
    CancelListenerClass listener2 = new CancelListenerClass();
    jbtOK.addActionListener(listener1);
    jbtOK.addActionListener(listener2);  	
   
    jbtCancel.addActionListener(new ActionListener(){

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			jbtOK.setBackground(Color.YELLOW);
		}
    	
    });
  }
  
  public static void main(String[] args) {
    JFrame frame = new HandleEvent();
    frame.setTitle("Handle Event");
    frame.setSize(200, 150);
    frame.setLocation(200, 100);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);
  }
}

class OKListenerClass implements ActionListener {


public void actionPerformed(ActionEvent e) {
	JButton jb;
	jb=(JButton)e.getSource();
	  if(jb.getText().equals("OK"))
		  {
    System.out.println("OK button clicked");
    jb.setBackground(Color.RED);
    }
	  if(jb.getText().equals("Cancel"))
		    System.out.println("Cancel button clicked");
    System.out.println(e);
  }
}

class CancelListenerClass implements ActionListener {
  public void actionPerformed(ActionEvent e) {
    System.out.println("Cancel button clicked");
    System.out.println(e);
  }
}
