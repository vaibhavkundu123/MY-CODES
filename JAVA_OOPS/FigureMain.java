import java.io.*;
import shape.Figure;
class FigureMain
{
    public static void main(String[] args) throws IOException
    {
        Figure figure = new Figure();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println();
        while(true)
        {
            System.out.println("Enter the shape name whose volume you want to calculate (cube, rectangle, cylinder) or exit to end the program:");
            String shapeName = br.readLine().toLowerCase();
            switch (shapeName) {
                case "cube":
                System.out.println("Enter the side length of the cube:");
                double side = Double.parseDouble(br.readLine());
                figure.Vol(side);
                break;
                case "rectangle":
                System.out.println("Enter the length of the rectangle:");
                double length = Double.parseDouble(br.readLine());
                System.out.println("Enter the width of the rectangle:");
                double width = Double.parseDouble(br.readLine());
                System.out.println("Enter the height of the rectangle:");
                double height = Double.parseDouble(br.readLine());
                figure.Vol(length, width, height);
                break;
                case "cylinder":
                System.out.println("Enter the radius of the cylinder:");
                double radius = Double.parseDouble(br.readLine());
                System.out.println("Enter the height of the cylinder:");
                double cylheight = Double.parseDouble(br.readLine());
                figure.Vol(radius, cylheight);
                break;
                case "exit":
                System.exit(0);
                default:
                System.out.println("Invalid shape name.");
                break;
            }
        }
    }
}
