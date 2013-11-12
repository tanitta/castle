package trit.alight
import processing.core._
import ddf.minim.analysis._
import ddf.minim._

class Sound(var ps:PApplet){
	var minim = new Minim(this)
	var in:AudioInput = minim.getLineIn(Minim.STEREO, 512)
	var fft = new FFT(in.bufferSize(), in.sampleRate())
	fft.window(FourierTransform.HAMMING)
	
	def update ={
		fft.forward(in.mix)
	}
}