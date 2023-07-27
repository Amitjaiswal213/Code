import javax.swing.*;
import java.awt.*;


class Face extends JFrame{

	Face(){
		setSize(500,500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}
	
	public void paint(Graphics g){
		g.setColor(Color.yellow);
		g.fillOval(40,40,220,220);
		g.setColor(Color.blue);
		g.fillOval(80,80, 40,40);
		g.setColor(Color.blue);
		g.fillOval(180, 80, 40, 40);
		g.setColor(Color.blue);
		//g.drawLine(150, 120, 150, 200);
		g.fillRect(150, 110, 5, 80);
		g.setColor(Color.blue);
		g.drawArc(100, 120, 100, 100, 235, 75);
	}


	public static void main(String ar[]){
		new Face();
	}
}