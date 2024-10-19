class Fibonacci
{
	public static void main(String args[])
	{
		int num = Integer.parseInt(args[0]);
		if (num == 1) System.out.print("For n = " + num + " : " + "0.");
        else if (num == 2) System.out.print("For n = " + num + " : " + "0, 1.");
        else if (num >= 3)
		{
			int first = 0, second = 1;
			System.out.print("For n = " + num + " : " + first + ", ");
			System.out.print(second + ", ");
			for(int i = 3; i<num; i++) {
				int third = first + second;
				System.out.print(third + ", ");
				first = second;
				second = third;
			}
			System.out.print(first + second + ".");
		}
    }
}