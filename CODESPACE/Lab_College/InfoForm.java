import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

class InfoForm extends JFrame implements ActionListener {
    JPanel p1, p2, p3;
    JLabel l1, l2, l3, l4, l5;
    JTextField t1,t2,t3,t4;
    JButton b1;
    
    InfoForm(){

        //Creating frame
        JFrame j =new JFrame();
        j.setLayout(null);

        p1=new JPanel();
        p2=new JPanel();
        p3=new JPanel();

        //Adding size to panels
        p1.setBounds(10,10,350,90);
        p2.setBounds(10, 100, 360, 100 );
        p3.setBounds(10,200, 360, 100);

        //Adding panels to frame
        j.add(p1);
        j.add(p2);
        j.add(p3);

        //Labels
        l1=new JLabel("INFORMATION");
        l2=new JLabel("NAME: ");
        l3=new JLabel("ROLL NO: ");
        l4=new JLabel("DEPARTMENT: ");
        l5=new JLabel("EMAIL: ");

        //TextFields
        t1=new JTextField();
        t2=new JTextField();
        t3=new JTextField();
        t4=new JTextField();    




        //Buttons
        b1=new JButton("OKAY");



        //P1 will contain INFORMATION label
        p1.setLayout(new GridLayout(1,1,10,10));
        p1.add(l1);

        //P2 will contain all the inputs
        p2.setLayout(new GridLayout(4,2,10,10));
        p2.add(l2);
        p2.add(t1);
        p2.add(l3);
        p2.add(t2);    
        p2.add(l4);
        p2.add(t3);
        p2.add(l5);
        p2.add(t4);


        //P3 will contain "OKAY" button
        p3.setLayout(new FlowLayout());
        p3.add(b1);

        b1.addActionListener(this);


        //Setting frame size and close action
        j.setSize(500,500);
        j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        j.setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource()==b1){

            int check= Integer.parseInt(t2.getText());

            if (check < 0 || check > 79) {
                JOptionPane.showMessageDialog(null, "Invalid Roll No found!", "Error", JOptionPane.ERROR_MESSAGE);
            }else{
                JOptionPane.showMessageDialog(null, "Accepted!", "Success", JOptionPane.INFORMATION_MESSAGE);

            }
        }
    }


}



class Driver_2{
    public static void main(String ar[]){
        new InfoForm();
    }
}