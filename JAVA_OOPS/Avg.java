class Avg
{
	public static void main(String args[])
	{
		int sum = 0;
		float avg = 0;
		for(int i = 0; i < 10; i++)
		{
			int a = Integer.parseInt(args[i]);
			sum += a;
		}
		avg = (float)sum / 10;
		System.out.println(avg);
	}
}