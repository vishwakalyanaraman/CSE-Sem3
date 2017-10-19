import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
/* <APPLET CODE=Applet3.class WIDTH=400 HEIGHT=200 > </APPLET> */
public class Applet3 extends Applet implements Runnable{
  String msg="This is scrollable text . . . . . ";
  Thread t=null;
  public void init(){
    setBackground(Color.cyan);
    setForeground(Color.red);
    t=new Thread(this);
    t.start();
  }
  public void run(){
    char ch;
    while(true){
      try{
        repaint();
        Thread.sleep(700);
        ch=msg.charAt(0);
        msg=msg.substring(1,msg.length());
        msg+=ch;
      }
      catch(InterruptedException e){}
    }
  }
      public void paint(Graphics g){
         g.setColor(Color.red);
         g.drawString(msg,20,100);
      }
}