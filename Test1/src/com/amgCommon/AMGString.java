package com.amgCommon;

/**
 * This class helps manipulate strings
 */
public class AMGString{
	private String value = "";

	/**
	 * This is the default constructor
	 */
	public AMGString(){
	}
	
	/**
	 * This is the common constructor
	 * @param str Value to set for the class
	 */
	public AMGString(String str){
		value = str;
	}

	/**
	 * This method pads a string
	 * @param len Length of the pad
	 * @param pad String to use for padding
	 * @return Left-padded string
	 */
	public String padLeft(int len, String pad){
		if(value.length() > len){
			return value.substring(0,len);
		}
		else{
			String mFinal = "";
			for(int i = value.length(); i < len; i++){
				mFinal += pad;
			}
			return (mFinal + value);
		}
	}

    /**
     * This method pads a string
     * @param len Length of the pad
     * @param pad String to use for padding
     * @return Right-padded string
     */
    public String padRight(int len, String pad){
        if(value.length() > len){
            return value.substring(0,len);
        }
        else{
            String mFinal = "";
            for(int i = value.length(); i < len; i++){
                mFinal += pad;
            }
            return (mFinal + value);
        }
    }
}
