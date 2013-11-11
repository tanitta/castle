
import processing.net.*;

Client cl;
int id = 0;

void setup() 
{
  size(450, 255);
  background(204);
  stroke(0);
  frameRate(10);
  // Connect to the server's IP address and port
  cl = new Client(this, "127.0.0.1", 20000); // Replace with your server's IP and port
}

void draw(){}

void clientEvent(Client c){
	String s = c.readString();
	if(s != null){
		println("client received: " + s);
	}
}

void mouseDragged(){
	String s = id + " " + mouseX + " " + mouseY + "\n";
	println(s);
	cl.write(s);
}
