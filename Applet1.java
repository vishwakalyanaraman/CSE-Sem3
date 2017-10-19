import java.applet.*;  
import java.awt.*;  
public class Applet1 extends Applet{  
  
	public void paint(Graphics g){

	g.drawString("Welcome to Applet Programming",150,150);
	showStatus("This is a status window");  
	}  
  	public void init(){

  	setBackground(Color.red);

  	}
}  
/* 
<applet code="Applet1.class" width="300" height="300"> 
</applet> 
*/  