import javax.swing.*;

public class MainForm extends JFrame {
    public MainForm() {
        setTitle("Teacher Management");
        JButton openBtn = new JButton("Διαχείριση Εκπαιδευτών");
        openBtn.addActionListener(e -> new MenuForm());

        add(openBtn);
        setSize(300, 100);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}