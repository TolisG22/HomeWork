import javax.swing.*;

public class MenuForm extends JFrame {
    public MenuForm() {
        setTitle("Μενού");
        JButton insertBtn = new JButton("Εισαγωγή Εκπαιδευτή");
        JButton searchBtn = new JButton("Αναζήτηση Εκπαιδευτή");

        insertBtn.addActionListener(e -> new InsertForm());
        searchBtn.addActionListener(e -> new UpdateDeleteForm());

        add(insertBtn);
        add(searchBtn);
        setLayout(new java.awt.GridLayout(2, 1));
        setSize(300, 200);
        setVisible(true);
    }
}