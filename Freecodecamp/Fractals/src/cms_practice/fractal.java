package cms_practice;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Toolkit;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JPanel;

class FrameFractal extends JFrame {

	private int ORDER = 1;
	private int x=2;
	private PanelFractals panFrac;
	private Reader reader = new Reader();
	
	FrameFractal(){
		setTitle("Fractal of order " + ORDER);
		setResizable(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		addMouseListener(reader);
		panFrac = new PanelFractals(ORDER);
		add(panFrac);
		pack();
		
		setVisible(true);
	}
	
	FrameFractal(int order){
		setTitle("Fractal of order " + ORDER);
		setResizable(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		addMouseListener(reader);
		panFrac = new PanelFractals(order);
		add(panFrac);
		pack();
		
		setVisible(true);
	}
	
	public class PanelFractals extends JPanel{
		
		Toolkit tkit = Toolkit.getDefaultToolkit();
		Dimension dimMon = tkit.getScreenSize();
		public final int width = dimMon.width/2, height = width;
		private final int xA = width/4, yA = 3*height/4, xB=3*width/4,yB=3*height/4, xC=width/2,yC=height/4;
		private int order, count=1;
		
		PanelFractals(int order){
			setPreferredSize(new Dimension(width, height));
			setBackground(Color.WHITE);
			this.order = order;
			setResizable(true);
		}
		
		public void paint(Graphics g) {
			super.paint(g);
			((Graphics2D)g).setStroke(new BasicStroke(1.5f));
			g.setColor(Color.BLACK);
			drawFlake(g,xA,yA,xB,yB,count);
			drawFlake(g,xB,yB,xC,yC,count);
			drawFlake(g,xC,yC,xA,xB,count);
			
		}
		
		public void drawFlake(Graphics g, int Xin, int Yin, int Xend, int Yend, int count) {
			int xA,xB,yA,yB,xC,yC;
			
			if(count == order) {
				g.drawLine(Xin, Yin, Xend, Yend);
			}else {
				xA = Xin + (Xend-Xin)/3;
				yA = Yin + (Yend-Yin)/3;
				xB = Xin + (Xend-Xin)*2/3;
				yB = Yin + (Yend-Yin)*2/3;
				xC = (int)((Xin+Xend)/2+(Yin-Yend)*Math.sqrt(3)/6);
				yC = (int)((Yin+Yend)/2+(Xend-Xin)*Math.sqrt(3)/6);
				
				drawFlake(g, Xin, Yin,xA,yA,count+1);
				drawFlake(g,xA,yA,xC,yC,count+1);
				drawFlake(g,xC,yC,xB,yB,count+1);
				drawFlake(g,xB,yB,Xend,Yend,count+1);
			}
		}
	}
	
	
	class Reader extends MouseAdapter{
		
		public void mouseClicked(MouseEvent e) {
			if(e.getButton()==MouseEvent.BUTTON3) {
				FrameFractal f = new FrameFractal(x);
				x++;
			}else if(e.getButton()==MouseEvent.BUTTON1){
				if(ORDER>(x+1)) {
					x--;
					FrameFractal f = new FrameFractal(x);
				}
			}
		}
		
	}
}