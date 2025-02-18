import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class CalculatorApplet extends Applet implements ActionListener {

    // Declare components
    private TextField num1Field, num2Field, resultField;
    private Button addButton, subtractButton, multiplyButton, divideButton;

    @Override
    public void init() {
        // Set layout and initialize components
        setLayout(new GridLayout(5, 2));

        Label num1Label = new Label("Number 1:");
        Label num2Label = new Label("Number 2:");
        Label resultLabel = new Label("Result:");

        num1Field = new TextField();
        num2Field = new TextField();
        resultField = new TextField();
        resultField.setEditable(false); // Result field should be read-only

        addButton = new Button("+");
        subtractButton = new Button("-");
        multiplyButton = new Button("*");
        divideButton = new Button("/");

        // Add components to the applet
        add(num1Label);
        add(num1Field);
        add(num2Label);
        add(num2Field);
        add(resultLabel);
        add(resultField);

        add(addButton);
        add(subtractButton);
        add(multiplyButton);
        add(divideButton);

        // Register event listeners
        addButton.addActionListener(this);
        subtractButton.addActionListener(this);
        multiplyButton.addActionListener(this);
        divideButton.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            double num1 = Double.parseDouble(num1Field.getText());
            double num2 = Double.parseDouble(num2Field.getText());
            double result = 0;

            if (e.getSource() == addButton) {
                result = num1 + num2;
            } else if (e.getSource() == subtractButton) {
                result = num1 - num2;
            } else if (e.getSource() == multiplyButton) {
                result = num1 * num2;
            } else if (e.getSource() == divideButton) {
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    resultField.setText("Cannot divide by zero");
                    return;
                }
            }

            resultField.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            resultField.setText("Invalid input");
        }
    }
}
