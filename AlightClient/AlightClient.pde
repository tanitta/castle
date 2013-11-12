import hypermedia.net.*;


UDP udp;
int id = 1;
void setup() {

  size( 1366, 768 );
  background( 0 );

  udp = new UDP( this, 6000, "224.0.0.0" );

  udp.listen( true );

  println( "init as multicast socket ... "+udp.isMulticast() );
  println( "joins a multicast group  ... "+udp.isJoined() );

  stroke( 255 );
}



void draw() {
    noStroke();
  fill( 0, 0, 0, 7 );
  rect( 0, 0, width, height);
    byte[] data = new byte[6]; 
    
    int mouseX1 = mouseX%128;
    int mouseY1 = mouseY%128;
    
    int mouseX2 = mouseX/128;
    int mouseY2 = mouseY/128;
    
    // add the mouse positions
    data[0] = byte(id);
    data[1] = byte(mouseX1);
    data[2] = byte(mouseY1);
    data[3] = byte(mouseX2);
    data[4] = byte(mouseY2);
    data[5] = byte(mousePressed);
 
    udp.send( data );
    println(mouseX1);
    ellipse(mouseX,mouseY,20,20);
}
int bx = 0;
int by = 0;
void receive( byte[] data ) {
  
  int x  = int( data[1] )+128*int( data[3]) ;
  int y  = int( data[2] )+128*int( data[4]) ;


  
  stroke( 255 );
  line( x, y, bx, by );
  
  bx = x;
  by = y;
  
}

boolean sketchFullScreen(){
  return false;
}
