
import processing.net.*;

Client cl;


void setup() 
{
  size(450, 255);
  background(204);
  stroke(0);
  // Connect to the server's IP address and port
  cl = new Client(this, "127.0.0.1", 20000); // Replace with your server's IP and port
}

void draw(){}

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
