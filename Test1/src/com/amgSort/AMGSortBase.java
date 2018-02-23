package com.amgSort;

import java.util.*;
import java.time.*;
import java.time.temporal.*;

/**
 * This is the base object for all sorting algorithms
 */
class AMGSortBase{
	protected String sortName = "";
	protected String sortDescription = "";
	protected double sortTime = 0.0;

	public AMGSortBase(){
	}

	public AMGSortBase(String name){
		sortName = name;
	}

	public AMGSortBase(String name, String description){
		sortName = name;
		sortDescription = description;
	}

	public void setSortName(String a){
		sortName = a;
	}

	public void setSortDescription(String a){
		sortDescription = a;
	}
}
