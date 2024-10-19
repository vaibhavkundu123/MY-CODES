class Circle
{
    double radius;
    Circle(double r)
    {
        radius = r;
    }
    double perimeter()
    {
        return 2 * Math.PI * radius;
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
    double perimeter()
    {
        return 2 * (length + width);
    }
}

class Square
{
    double side;
    Square(double s)
    {
        side = s;
    }
    double perimeter()
    {
        return 4 * side;
    }
}

class PerimeterCal
{
    public static void main(String[] args)
    {
        for(int i = 0; i < args.length; i++)
        {
            if(args[i].equalsIgnoreCase("circle"))
            {
                double radius = Double.parseDouble(args[++i]);
                Circle c = new Circle(radius);
                System.out.println("Perimeter of Circle: " + c.perimeter());
            }
            else if(args[i].equalsIgnoreCase("rectangle"))
            {
                double length = Double.parseDouble(args[++i]);
                double width = Double.parseDouble(args[++i]);
                Rectangle r = new Rectangle(length, width);
                System.out.println("Perimeter of Rectangle: " + r.perimeter());
            }
            else if(args[i].equalsIgnoreCase("square"))
            {
                double side = Double.parseDouble(args[++i]);
                Square s = new Square(side);
                System.out.println("Perimeter of Square: " + s.perimeter());
            }
        }
    }
}
