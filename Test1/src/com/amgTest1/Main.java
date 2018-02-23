package com.amgTest1;

import com.amgSort.*;
import com.amgCommon.*;
import java.util.*;

/**
 * This is the main entry point from the command line.
 */
class Main{

	/**
	 * This method prints details of the executable, including parameters
	 */
	public static void menu(){
		System.out.println(new AMGString().padRight(80,"="));
		System.out.println("* Name       : AMGTest1");
        System.out.println("* Author     : Abel Gancsos");
        System.out.println("* Version    : v. 1.0.0");
        System.out.println("* Flags      : ");
		System.out.println("	* -m     : Algorithm to use for sorting");
		System.out.println("	* -t     : Data type");
		System.out.println("	* -values: Comma-separated list of values to sort");
        System.out.println(new AMGString().padRight(80,"="));
	}

	/**
	 * This is the main method to run the utility from the command-line
	 */
	public static void main(String[] args){
		boolean help = false;
		String mode = "bubble";
		String dataType = "int";
		ArrayList values = new ArrayList();  // Generic list to hold any type of values

		// Configure environment using command-line parameters
		if(args.length > 0){
			
			for(int i = 0; i < args.length; i++){
				if(args[i].equals("-h")){
					help = true;
				}
				if(args[i].equals("-t")){
					dataType = args[i + 1].toLowerCase();
				}
				else if(args[i].equals("-m")){
					mode = args[i + 1].toLowerCase();
				}
				else if(args[i].equals("-values")){
					values = new ArrayList(Arrays.asList(args[i + 1].split(",")));
				}
			}			

			if(help){
				menu();
			}

			else{
				// Run algorithm based on mode and data types
				if(mode.equals("bubble")){
					if(dataType.equals("int")){
						ArrayList<Integer> newList = new ArrayList<Integer>(); // List for integer types
						try{
							for(Object value : values){
								newList.add(Integer.parseInt((String)value));
							}
						}
						catch(Exception e){
						}
						AMGBubbleSort session = new AMGBubbleSort("BubbleSort","Testing bubble sort algorithm");
						Integer[] values1 = newList.toArray(new Integer[newList.size()]); // Convert list to array (probably not efficient, but secure)
						session.runInt(values1);	
					}
					else{
						System.out.println("Data type not implemented for this algorithm...");
					}
				}
				else{
					System.out.println("Algorithm not implemented...");
				}
			}
		}
		else{
			menu();
		}
	}
}
