class Palindrome
{
	public static void main(String args[])
	{
		int isPalindrome = 1;
		for(int starting_index = 0, ending_index = args[0].length() - 1; starting_index < ending_index; starting_index++, ending_index--)
		{
			if(args[0].charAt(starting_index) != args[0].charAt(ending_index))
			{
				isPalindrome = 0;
				break;
			}
		}
		if(isPalindrome == 1)
		{
			System.out.println("Your string " + args[0] + " is a Palindrome.");
		} else {
			System.out.println("Your string " + args[0] + " is not a Palindrome.");
		}
	}
}