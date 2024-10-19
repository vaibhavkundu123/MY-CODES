class SortString
{
	public static void main(String args[])
	{
		int n = args.length;
		for (int i = 0; i < n - 1; i++)
		{
            for (int j = 0; j < n - i - 1; j++)
			{
                if (args[j].compareToIgnoreCase(args[j + 1]) > 0)
				{
                    String temp = args[j];
                    args[j] = args[j + 1];
                    args[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			System.out.println(args[i]);
		}
	}
}