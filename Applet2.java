import java.awt.*;
import java.applet.*;

/*<applet code = "Applet2" width = 200 height = 200 > <param name = Value value = 5> </applet> */

public class Applet2 extends Applet{
	int value;

	public void start(){
		String param = getParameter("Value");
		try{
			value = Integer.parseInt(param);
		}
		catch (NumberFormatException e){
			value = 0;
		}

	}

	public void paint(Graphics g){
		for (int i = 1; i <= 10; i++)
			g.drawString(value+"*"+i+" = "+ value*i, 10, 30+(i*50));;
	}
}

