package trit.alight
import processing.core._
import ddf.minim.analysis._
import ddf.minim._

class BaseScene(var ps:PApplet){
	var sd:trit.alight.Sound = null
	var nt:trit.alight.Network = null
	
	def setSound(input:trit.alight.Sound){
		sd = input
	}
	
	def setNetwork(input:trit.alight.Network){
		nt = input
	}
	
	
	def setup = {
		ps.stroke(0, 255, 0)
		ps.strokeWeight(2)
		ps.fill(0,255,0,50);
	}
	
	def update = {

	}
	
	def draw = {
		ps.fill(0,0,0,32);
		ps.noStroke()
		ps.rect(0,0,ps.displayWidth,ps.displayHeight)
		ps.stroke(0, 255, 0)
		for( i <- 0 to sd.in.bufferSize()-1) {
			ps.fill(sd.in.left.get(i).toFloat*512,255,sd.in.right.get(i).toFloat*512,50);
			ps.ellipse(i.toFloat/sd.in.bufferSize().toFloat*ps.displayWidth,sd.in.left.get(i)*ps.displayHeight+ps.displayHeight/2,sd.in.left.get(i)*400,sd.in.left.get(i)*400)
			ps.ellipse(i.toFloat/sd.in.bufferSize().toFloat*ps.displayWidth,sd.in.right.get(i)*ps.displayHeight+ps.displayHeight/2,sd.in.right.get(i)*400,sd.in.right.get(i)*400)

		}
		
		var id = 1
		if(nt.drawers(id).isDraw == 1){
			ps.fill(sd.in.left.get(0).toFloat*512,255,sd.in.right.get(0).toFloat*512,128);
			ps.ellipse(nt.drawers(id).mouseX,nt.drawers(id).mouseY,sd.in.left.get(0)*400,sd.in.left.get(0)*400)
		}
	}
}