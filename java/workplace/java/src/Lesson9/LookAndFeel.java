package Lesson9;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class LookAndFeel extends JFrame
{
	String[] choices = {"eeny", "meeny", "minie", "moe", "toe", "you"};
	Component[] samples = {new JButton("JButton"),
			new JTextField("JTextField"), new JLabel("JLabel"),
			new JCheckBox("JCheckBox"), new JRadioButton("Radio"),
			new JComboBox(choices), new JList(choices),};
	public LookAndFeel()
	{
		super("Look And Feel");
		Container cp = getContentPane();
		cp.setLayout(new FlowLayout());
		for (int i = 0; i < samples.length; i++)
			cp.add(samples[i]);
	}
	private static void usageError()
	{
		System.out.println("Usage:LookAndFeel [cross|system|motif]");
		System.exit(1);
	}
	public static void main(String[] args)
	{
		
		//if (args.length == 0)
		//	usageError();
		args=new String[1];
		//args[0]="cross";
		//args[0]="motif";
		args[0]="system";
		if (args[0].equals("cross"))
		{
			try
			{
				UIManager.setLookAndFeel(UIManager
						.getCrossPlatformLookAndFeelClassName());
			} catch (Exception e)
			{
				e.printStackTrace(System.err);
			}
		} else if (args[0].equals("system"))
		{
			try
			{
				UIManager.setLookAndFeel(UIManager
						.getSystemLookAndFeelClassName());
			} catch (Exception e)
			{
				e.printStackTrace(System.err);
			}
		} else if (args[0].equals("motif"))
		{
			try
			{
				UIManager.setLookAndFeel("com.sun.java."
						+ "swing.plaf.motif.MotifLookAndFeel");
			} catch (Exception e)
			{
				e.printStackTrace(System.err);
			}
		} else
			usageError();
		// Note the look & feel must be set before
		// any components are created.
		JFrame jf=new LookAndFeel();
		jf.setSize(300, 200);
		jf.setVisible(true);
		jf.setDefaultCloseOperation(3);
	}
} ///:~

