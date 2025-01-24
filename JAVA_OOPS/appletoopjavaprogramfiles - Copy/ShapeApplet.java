import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

public class ShapeApplet extends Applet {

    @Override
    public void init() {
        setSize(400, 400);  // Setting size of the applet
        setBackground(Color.WHITE);  // Background color
    }

    @Override
    public void paint(Graphics g) {
        // Draw a Circle
        g.setColor(Color.RED);
        g.drawOval(50, 50, 100, 100); // (x, y, width, height) for circle

        // Draw an Ellipse
        g.setColor(Color.BLUE);
        g.drawOval(200, 50, 150, 100); // (x, y, width, height) for ellipse

        // Draw a Square
        g.setColor(Color.GREEN);
        g.drawRect(50, 200, 100, 100); // (x, y, width, height) for square

        // Draw a Rectangle
        g.setColor(Color.MAGENTA);
        g.drawRect(200, 200, 150, 100); // (x, y, width, height) for rectangle

        // Draw a Triangle
        g.setColor(Color.ORANGE);
        int[] xPoints = {150, 200, 100};
        int[] yPoints = {350, 400, 400};
        g.drawPolygon(xPoints, yPoints, 3); // Draw triangle using points
    }
}
