package trit.alight
import processing.core._
import hypermedia.net._

import processing.net._
class Network(var ps:PApplet){
	var udp = new UDP(ps, 6000, "224.0.0.1")
	udp.listen( true );
	
	var drawers = new Array[Drawer](5)
	drawers(0) = new Drawer
	
	def setup = {}
	
	def update = {
		// if(c != null){
		// 	var s:String = c.readStringUntil('\n')
		// 	if (s != null){
		// 		// println("server received: " + s)
		// 		var splitStrings: Array[String] = PApplet.splitTokens(s)
		// 		var id:Int = splitStrings(0).toInt
		// 		//println("mouseX" + splitStrings(1).toInt)
		// 		// drawers(id).mouseX = splitStrings(1).toInt
		// 		// drawers(id).mouseY = splitStrings(2).toInt
		// 		ps.ellipse(splitStrings(1).toInt,splitStrings(2).toInt,10,10) 
		// 	}
		// }
		
	}
	
	def draw = {
		var id = 0
		if(drawers(id).isDraw == 1){
			ps.line(drawers(id).mouseX,drawers(id).mouseY,drawers(id).pmouseX,drawers(id).pmouseY)
		}
		drawers(id).pmouseX = drawers(id).mouseX
		drawers(id).pmouseY = drawers(id).mouseY
		
	}
	
	def receive(data: Array[Byte]){
		var id = data(0).toInt
		drawers(id).mouseX = data(1).toInt + 128*data(3).toInt
		drawers(id).mouseY = data(2).toInt + 128*data(4).toInt
		
		drawers(id).isDraw = data(5).toInt
		
	
		var x = drawers(id).mouseX
		var y = drawers(id).mouseY
		
		
		
		
	}
}