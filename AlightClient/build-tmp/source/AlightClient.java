import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import hypermedia.net.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class AlightClient extends PApplet {




UDP udp;
int id = 2;
public void setup() {

  size( 1366, 768 );
  background( 0 );

  udp = new UDP( this, 6000, "224.0.0.0" );

  udp.listen( true );

  println( "init as multicast socket ... "+udp.isMulticast() );
  println( "joins a multicast group  ... "+udp.isJoined() );

  stroke( 255 );
}



public void draw() {
    noStroke();
  fill( 0, 0, 0, 7 );
  rect( 0, 0, width, height);
    byte[] data = new byte[6]; 
    
    int mouseX1 = mouseX%128;
    int mouseY1 = mouseY%128;
    
    int mouseX2 = mouseX/128;
    int mouseY2 = mouseY/128;
    
    // add the mouse positions
    data[0] = PApplet.parseByte(id);
    data[1] = PApplet.parseByte(mouseX1);
    data[2] = PApplet.parseByte(mouseY1);
    data[3] = PApplet.parseByte(mouseX2);
    data[4] = PApplet.parseByte(mouseY2);
    data[5] = PApplet.parseByte(mousePressed);
 
    udp.send( data );
    println(mouseX1);
    ellipse(mouseX,mouseY,20,20);
}
int bx = 0;
int by = 0;
public void receive( byte[] data ) {
  
  int x  = PApplet.parseInt( data[1] )+128*PApplet.parseInt( data[3]) ;
  int y  = PApplet.parseInt( data[2] )+128*PApplet.parseInt( data[4]) ;


  
  stroke( 255 );
  line( x, y, bx, by );
  
  bx = x;
  by = y;
  
}

public boolean sketchFullScreen(){
  return false;
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "AlightClient" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
