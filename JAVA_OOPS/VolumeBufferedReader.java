import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Volume
{
    double volume(double side)
    {
        return side * side * side;
    }
    
    double volume(double radius, double height)
    {
        return Math.PI * radius * radius * height;
    }
    
    double volume(double a, double b, double c)
    {
        return (4.0/3.0) * Math.PI * a * b * c;
    }
}

class VolumeBufferedReader
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Volume v = new Volume();
        System.out.print("Enter the side of a cube: ");
        double side = Double.parseDouble(br.readLine());
        System.out.println("Volume of cube: " + v.volume(side));
        System.out.print("\nEnter the radius of a cylinder: ");
        double radius = Double.parseDouble(br.readLine());
        System.out.print("Enter the height of the cylinder: ");
        double height = Double.parseDouble(br.readLine());
        System.out.println("Volume of cylinder: " + v.volume(radius, height));
        System.out.println("\nEnter the three sides of a cuboid: ");
        System.out.print("Side 1: ");
        double a = Double.parseDouble(br.readLine());
        System.out.print("Side 2: ");
        double b = Double.parseDouble(br.readLine());
        System.out.print("Side 3: ");
        double c = Double.parseDouble(br.readLine());
        System.out.println("Volume of ellipsoid: " + v.volume(a, b, c));
    }    
}
