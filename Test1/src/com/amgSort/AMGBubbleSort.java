package com.amgSort;

import java.util.*;
import java.time.*;
import java.time.temporal.*;

/**
 * This class manages buble sort related operations
 */
public class AMGBubbleSort extends AMGSortBase{

    public AMGBubbleSort(){
		super();
    }

    public AMGBubbleSort(String name){
		super(name);
    }

    public AMGBubbleSort(String name, String description){
		super(name,description);
    }

	/**
	 * This is the private method that sorts a list of integers using bubble sort
	 */
    private void bubbleSortInt(Integer[] a){
		for(int i = 0; i < a.length; i++){
			for(int j = 0; j < a.length; j++){
				if(a[i] > a[j]){
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
    }

	/**
	 * This is the entry point to the class for an integer list
	 */
    public void runInt(Integer[] a){
        LocalTime startTime = LocalTime.now();
        LocalTime endTime = null;

        bubbleSortInt(a);
		for(int i = a.length - 1; i >= 0; i--){
			if(i < a.length - 1){
				System.out.print(",");
			}
			System.out.print(a[i]);
		}
		System.out.println();

        endTime = LocalTime.now();
        sortTime = startTime.until(endTime,ChronoUnit.MILLIS);
        System.out.println("This utility completed in: " + Double.toString(sortTime) + " miliseconds");
    }
}
