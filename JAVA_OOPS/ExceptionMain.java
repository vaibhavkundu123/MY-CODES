import java.io.*;

class NoMatchFoundException extends Exception {
    private String city_name;
    NoMatchFoundException(String cn)
    {
        city_name = cn;
    }
    public String toString()
    {
        return city_name + " NOT FOUND!!";
    }
}

class ExceptionMain {
    static void Search(String cities[], String city, int n) throws NoMatchFoundException
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (cities[i].equalsIgnoreCase(city))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            System.out.println("City found!!");
        else
            throw new NoMatchFoundException(city);
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the number of cities:");
        int n = Integer.parseInt(br.readLine());
        String cities[] = new String[n];
        System.out.println("Enter the cities:");
        for (int i = 0; i < n; i++)
            cities[i] = br.readLine();
        System.out.println("Enter the city to be searched:");
        String city = br.readLine();
        try {
            Search(cities, city, n);
        } catch (NoMatchFoundException e) {
            System.out.println("Exception Caught: " + e);
        }
    }
}
