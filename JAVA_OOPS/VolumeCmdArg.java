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

class VolumeCmdArg {
    public static void main(String args[])
    {
        Volume v = new Volume();
        for(int i = 0; i < args.length; i++)
        {
            if(args[i].equalsIgnoreCase("cube"))
            {
                double side = Double.parseDouble(args[++i]);
                System.out.println("Volume of cube: " + v.volume(side));
            }
            else if(args[i].equalsIgnoreCase("cylinder"))
            {
                double radius = Double.parseDouble(args[++i]);
                double height = Double.parseDouble(args[++i]);
                System.out.println("Volume of cylinder: " + v.volume(radius, height));
            }
            else if(args[i].equalsIgnoreCase("ellipsoid"))
            {
                double a = Double.parseDouble(args[++i]);
                double b = Double.parseDouble(args[++i]);
                double c = Double.parseDouble(args[++i]);
                System.out.println("Volume of ellipsoid: " + v.volume(a, b, c));
            }
        }
    }
}
