class DesignPattern
{
    static void triangle(int rows)
    {
        System.out.println();
        System.out.println("Triangle");
        for (int i = 0; i < rows; i++)
        {
            for (int j = rows - i; j > 1; j--)
            {
                System.out.print("  ");
            }
            for (int j = 0; j <= i + i; j++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }
    static void rectangle(int rows, int cols)
    {
        System.out.println();
        System.out.println("Rectangle");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }
    static void square(int rows)
    {
        System.out.println();
        System.out.println("Square");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }
}

class DesignPatternCmdArg
{
    public static void main(String[] args)
    {
        for(int i = 0; i < args.length; i++)
        {
            if(args[i].equalsIgnoreCase("triangle"))
            {
                int rows = Integer.parseInt(args[++i]);
                DesignPattern.triangle(rows);
            }
            else if(args[i].equalsIgnoreCase("rectangle"))
            {
                int rows = Integer.parseInt(args[++i]);
                int cols = Integer.parseInt(args[++i]);
                DesignPattern.rectangle(rows, cols);
            }
            else if(args[i].equalsIgnoreCase("square"))
            {
                int rows = Integer.parseInt(args[++i]);
                DesignPattern.square(rows);
            }
        }
    }
}