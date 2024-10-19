package shape;
public class Figure
{
    public void Vol(double side)
    {
        double vol = side*side*side;
        System.out.println("Volume of cube = " + vol);
        System.out.println();
    }
    public void Vol(double length, double bredth, double height)
    {
        double vol = length*bredth*height;
        System.out.println("Volume of rectangle = " + vol);
        System.out.println();
    }
    public void Vol(double radius, double height)
    {
        double vol = (Math.PI*radius*radius*height)/3;
        System.out.println("Volume of cylinder = " + vol);
        System.out.println();
    }
}
