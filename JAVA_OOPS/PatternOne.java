class PatternOne
{
	public static void main(String args[])
	{
		int n = Integer.parseInt(args[0]);
		int twoD[][] = new int[n][];
		for(int i = 0; i < n; i++)
		{
			twoD[i] = new int[i+1];
		}
		for(int i = 0; i < n; i++)
		{
			//int k = 1;
			for(int j = 0; j <= i; j++)
			{
				
				if(j%2==0){
					twoD[i][j] = 1;
				} else if(j%2!=0) {
					twoD[i][j] = 0;
				}
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