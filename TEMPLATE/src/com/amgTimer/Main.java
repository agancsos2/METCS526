package com.amgTimer;

import java.util.*;
import java.time.*;
import java.time.temporal.*;

/**
 * THis is the main entry point from the command line.
 */
class Main{
	public static void main(String[] args){
		LocalTime startTime = LocalTime.now();
		LocalTime endTime = null;
		double timespan = 0.0;

		endTime = LocalTime.now();
		timespan = startTime.until(endTime,ChronoUnit.MILLIS);
		
		System.out.println("This utility completed in: " + timespan + " miliseconds");
	}
}
