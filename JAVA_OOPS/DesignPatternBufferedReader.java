import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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

class DesignPatternBufferedReader
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println();
        System.out.print("Enter the number of rows for the triangle: ");
        int rowst = Integer.parseInt(br.readLine());
        DesignPattern.triangle(rowst);
        System.out.print("Enter the number of rows for the rectangle: ");
        int rowsr = Integer.parseInt(br.readLine());
        System.out.print("Enter the number of columns for the rectangle: ");
        int cols = Integer.parseInt(br.readLine());
        DesignPattern.rectangle(rowsr, cols);
        System.out.print("Enter the number of rows for the square: ");
        int rowss = Integer.parseInt(br.readLine());
        DesignPattern.square(rowss);
    }
}
