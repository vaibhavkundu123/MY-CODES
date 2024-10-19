class PrimeNumbers
{
	public static void main(String args[])
	{
		int n = Integer.parseInt(args[0]);
		int m = Integer.parseInt(args[1]);
		for(int k = n; k <= m; k++)
		{
			int isPrime = 1;
			int i = 2;
			while (i < k) {
				if (k % i == 0) {
					isPrime = 0;
					break;
				}
				i++;
			}
			if(k == 1) isPrime = 0;
			if (isPrime == 1) {
				System.out.print(k + " ");
			}
		}
	}
}