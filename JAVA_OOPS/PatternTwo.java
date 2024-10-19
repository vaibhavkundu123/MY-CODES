class PatternTwo
{
	public static void main(String args[])
	{
		int n = Integer.parseInt(args[0]);
		char twoD[][] = new char[n][];
		for(int i = 0; i < n; i++)
		{
			twoD[i] = new char[i+1];
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				twoD[i][j] = '*';
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				System.out.print(twoD[i][j]);
			}
			System.out.println();
		}
	}
}	