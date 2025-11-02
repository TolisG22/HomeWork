import javax.swing.*;
import java.sql.Connection;
import java.sql.PreparedStatement;

public class InsertForm extends JFrame {
    public InsertForm() {
        JTextField id = new JTextField(10);
        JTextField fname = new JTextField(10);
        JTextField lname = new JTextField(10);
        JButton save = new JButton("Αποθήκευση");

        save.addActionListener(e -> {
            try {
                Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement("INSERT INTO TEACHERS VALUES (?, ?, ?)");
                stmt.setInt(1, Integer.parseInt(id.getText()));
                stmt.setString(2, fname.getText());
                stmt.setString(3, lname.getText());
                stmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Επιτυχής εισαγωγή.");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "Σφάλμα κατά την εισαγωγή.");
            }
        });

        setLayout(new java.awt.GridLayout(4, 2));
        add(new JLabel("ID:")); add(id);
        add(new JLabel("Όνομα:")); add(fname);
        add(new JLabel("Επώνυμο:")); add(lname);
        add(save);
        setSize(300, 200);
        setVisible(true);
    }
}