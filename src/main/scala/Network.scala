package trit.alight
import processing.core._
import trit.alight._

import processing.net._
class Network(var ps:PApplet){
	var server = new Server(ps, 20000)
	
	var drawers = Array[Drawer]()
	
	def setup = {}
	
	def update = {
		var c:Client = server.available()
		if(c != null){
			var s:String = c.readStringUntil('\n')
			if (s != null){
				// println("server received: " + s)
				var splitStrings: Array[String] = PApplet.splitTokens(s)
				var id:Int = splitStrings(0).toInt
				//println("mouseX" + splitStrings(1).toInt)
				// drawers(id).mouseX = splitStrings(1).toInt
				// drawers(id).mouseY = splitStrings(2).toInt
				ps.ellipse(splitStrings(1).toInt,splitStrings(2).toInt,10,10) 
			}
		}
		
	}
	
	def draw = {
		
	}
}