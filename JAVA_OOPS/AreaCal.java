import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Circle
{
    double radius;
    Circle(double r)
    {
        radius = r;
    }
    double area()
    {
        return Math.PI * radius * radius;
    }
}

class Rectangle
{
    double length, width;
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    double area()
    {
        return length * width;
    }
}

class Square
{
    double side;
    Square(double s)
    {
        side = s;
    }
    double area()
    {
        return side * side;
    }
}

class AreaCal {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println();
        System.out.print("Enter the radius of the circle: ");
        double radius = Double.parseDouble(br.readLine());
        Circle c = new Circle(radius);
        System.out.println("Area of the circle: " + c.area());
        System.out.println();
        System.out.print("Enter the length of the rectangle: ");
        double length = Double.parseDouble(br.readLine());
        System.out.print("Enter the width of the rectangle: ");
        double width = Double.parseDouble(br.readLine());
        Rectangle r = new Rectangle(length, width);
        System.out.println("Area of the rectangle: " + r.area());
        System.out.println();
        System.out.print("Enter the side of the square: ");
        double side = Double.parseDouble(br.readLine());
        Square s = new Square(side);
        System.out.println("Area of the square: " + s.area());

    }
}
