import java.applet.Applet;
import java.awt.*;

public class ShapeApplet extends Applet {

    @Override
    public void paint(Graphics g) {
        // Drawing a Circle
        g.setColor(Color.RED);
        g.drawOval(20, 20, 100, 100); // (x, y, width, height) - draws a circle if width = height

        // Drawing an Ellipse
        g.setColor(Color.BLUE);
        g.drawOval(150, 20, 150, 100); // Ellipse (x, y, width, height) with different width and height

        // Drawing a Square
        g.setColor(Color.GREEN);
        g.drawRect(20, 150, 100, 100); // Square (x, y, width, height) - same width and height

        // Drawing a Rectangle
        g.setColor(Color.MAGENTA);
        g.drawRect(150, 150, 150, 100); // Rectangle (x, y, width, height)

        // Drawing a Line
        g.setColor(Color.ORANGE);
        g.drawLine(20, 300, 170, 300); // Line from (x1, y1) to (x2, y2)

        // Drawing a Triangle
        g.setColor(Color.CYAN);
        int[] xPoints = {300, 350, 250}; // x-coordinates of the triangle
        int[] yPoints = {150, 250, 250}; // y-coordinates of the triangle
        g.drawPolygon(xPoints, yPoints, 3); // Triangle with 3 points
    }
}
