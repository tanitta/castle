package trit.alight
import processing.core._
import ddf.minim.analysis._
import ddf.minim._

class BaseScene(var ps:PApplet){
	var minim = new Minim(this)
	var in:AudioInput = minim.getLineIn(Minim.STEREO, 512)
	var fft = new FFT(in.bufferSize(), in.sampleRate())
	fft.window(FourierTransform.HAMMING)

	def setup = {
		ps.stroke(0, 255, 0)
		ps.strokeWeight(2)
		ps.fill(0,255,0,50);
	}
	
	def update = {
		fft.forward(in.mix)
	}
	
	def draw = {
		ps.fill(0,0,0,64);
		ps.noStroke()
		ps.rect(0,0,ps.displayWidth,ps.displayHeight)
		ps.stroke(0, 255, 0)
		for( i <- 0 to in.bufferSize()-1) {
			ps.fill(in.left.get(i).toFloat*100,255,in.right.get(i).toFloat*100,50);
			ps.ellipse(i.toFloat/in.bufferSize().toFloat*ps.displayWidth,in.left.get(i)*ps.displayHeight+ps.displayHeight/2,in.left.get(i)*200,in.left.get(i)*200)
			ps.ellipse(i.toFloat/in.bufferSize().toFloat*ps.displayWidth,in.right.get(i)*ps.displayHeight+ps.displayHeight/2,in.right.get(i)*200,in.right.get(i)*200)

		}
	}
}