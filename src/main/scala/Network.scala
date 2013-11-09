package trit.alight
import processing.core._
import processing.net._
class Network(var ps:PApplet){
	var server = new Server(ps, 20000)
	def setup = {}
	def update = {
		var c:Client = server.available()
		if(c != null){
			var s:String = c.readString()
		}
	}
	def draw = {}
}