package trit.alight
import processing.core._
import hypermedia.net._

import processing.net._
class Network(var ps:PApplet){
	var udp = new UDP(ps, 6000, "224.0.0.0")
	udp.listen( true );
	
	var drawers = new Array[Drawer](5)
	drawers(0) = new Drawer
	drawers(1) = new Drawer
	drawers(2) = new Drawer
	drawers(3) = new Drawer
	drawers(4) = new Drawer
	
	
	def setup = {}
	
	def update = {
		
	}
	
	
	def receive(data: Array[Byte]){
		var id = data(0).toInt
		drawers(id).mouseX = data(1).toInt + 128*data(3).toInt
		drawers(id).mouseY = data(2).toInt + 128*data(4).toInt
		
		drawers(id).isDraw = data(5).toInt		
	}
}