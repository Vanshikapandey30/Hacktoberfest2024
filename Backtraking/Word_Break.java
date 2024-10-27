// A recursive program to print all possible
// partitions of a given string into dictionary
// words
import java.io.*;
import java.util.*;

class GFG {

// Prints all possible word breaks of given string
static void wordBreak(int n, List<String> dict, String s)
{
	String ans="";
	wordBreakUtil(n, s, dict, ans);
}

static void wordBreakUtil(int n, String s, List<String> dict, String ans)
{
	for(int i = 1; i <= n; i++)
	{

	// Extract substring from 0 to i in prefix
	String prefix=s.substring(0, i);

	// If dictionary contains this prefix, then
	// we check for remaining string. Otherwise
	// we ignore this prefix (there is no else for
	// this if) and try next
	if(dict.contains(prefix))
	{
		// If no more elements are there, print it
		if(i == n)
		{

		// Add this element to previous prefix
		ans += prefix;
		System.out.println(ans);
		return;
		}
		wordBreakUtil(n - i, s.substring(i,n), dict, ans+prefix+" ");
	}
	}
}

// main function
public static void main(String args[])
{
	String str1 = "iloveicecreamandmango"; // for first test case
	String str2 ="ilovesamsungmobile";	 // for second test case
	int n1 = str1.length();				 // length of first string
	int n2 = str2.length();				 // length of second string

	// List of strings in dictionary
	List <String> dict= Arrays.asList("mobile","samsung","sam","sung",
									"man","mango", "icecream","and",
									"go","i","love","ice","cream");		 
	System.out.println("First Test:");

	// call to the method
	wordBreak(n1,dict,str1);
	System.out.println("\nSecond Test:");

	// call to the method
	wordBreak(n2,dict,str2);
}
}
