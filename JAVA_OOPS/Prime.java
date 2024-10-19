class Prime
{
	public static void main(String args[])
	{
		int isPrime = 1;
		int n = Integer.parseInt(args[0]);
		int i = 2;
        while (i < n) {
            if (n % i == 0) {
                isPrime = 0;
				break;
            }
            i++;
        }
		if (isPrime == 1) {
            System.out.println("Your number is Prime");
        } else {
            System.out.println("Your number is Not Prime");
        }
	}
}