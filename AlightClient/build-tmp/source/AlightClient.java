import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.net.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class AlightClient extends PApplet {




Client cl;


public void setup() 
{
  size(450, 255);
  background(204);
  stroke(0);
  // Connect to the server's IP address and port
  cl = new Client(this, "127.0.0.1", 20000); // Replace with your server's IP and port
}

public void draw(){}

// void clientEvent(Client c){
// 	String s = c.readString();
// 	if(s != null){
// 		println("client received: " + s);
// 	}
// }

// void mouseClicked(){
// 	String s = "(" + mouseX + ", " + mouseY + ") was clicked";
// 	println(s);
// 	cl.write(s);
// }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "AlightClient" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
