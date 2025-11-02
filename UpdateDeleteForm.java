import javax.swing.*;
import java.sql.*;

public class UpdateDeleteForm extends JFrame {
    public UpdateDeleteForm() {
        JTextField id = new JTextField(10);
        id.setEnabled(false);
        JTextField fname = new JTextField(10);
        JTextField lname = new JTextField(10);

        JButton search = new JButton("Αναζήτηση");
        JButton update = new JButton("Ενημέρωση");
        JButton delete = new JButton("Διαγραφή");

        search.addActionListener(e -> {
            String searchLname = JOptionPane.showInputDialog("Εισάγετε επώνυμο");
            try {
                Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement("SELECT * FROM TEACHERS WHERE TEACHER_LNAME=?");
                stmt.setString(1, searchLname);
                ResultSet rs = stmt.executeQuery();
                if (rs.next()) {
                    id.setText(String.valueOf(rs.getInt(1)));
                    fname.setText(rs.getString(2));
                    lname.setText(rs.getString(3));
                } else {
                    JOptionPane.showMessageDialog(this, "Δεν βρέθηκε.");
                }
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "Σφάλμα κατά την αναζήτηση.");
            }
        });

        update.addActionListener(e -> {
            try {
                Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(
                        "UPDATE TEACHERS SET TEACHER_FNAME=?, TEACHER_LNAME=? WHERE TEACHER_ID=?");
                stmt.setString(1, fname.getText());
                stmt.setString(2, lname.getText());
                stmt.setInt(3, Integer.parseInt(id.getText()));
                stmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Επιτυχής ενημέρωση.");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "Σφάλμα κατά την ενημέρωση.");
            }
        });

        delete.addActionListener(e -> {
            int confirm = JOptionPane.showConfirmDialog(this, "Σίγουρα θέλετε να διαγράψετε;");
            if (confirm == JOptionPane.YES_OPTION) {
                try {
                    Connection conn = DBConnection.getConnection();
                    PreparedStatement stmt = conn.prepareStatement("DELETE FROM TEACHERS WHERE TEACHER_ID=?");
                    stmt.setInt(1, Integer.parseInt(id.getText()));
                    stmt.executeUpdate();
                    JOptionPane.showMessageDialog(this, "Επιτυχής διαγραφή.");
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(this, "Σφάλμα κατά τη διαγραφή.");
                }
            }
        });

        setLayout(new java.awt.GridLayout(5, 2));
        add(new JLabel("ID:")); add(id);
        add(new JLabel("Όνομα:")); add(fname);
        add(new JLabel("Επώνυμο:")); add(lname);
        add(search); add(update); add(delete);
        setSize(400, 250);
        setVisible(true);
    }
}