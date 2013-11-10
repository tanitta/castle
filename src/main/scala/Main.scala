package trit.alight
import trit.alight._
import processing.core._
import fullscreen._



object Main extends processing.core.PApplet{
	var scene = new BaseScene(this)
	var network = new Network(this)
	override def setup = {
		// size(displayWidth,displayHeight)
		size(500,500)
		noCursor()
		
		scene.setup
	}
	
	def update = {
		network.update
		scene.update
		
	}
	
	override def draw = {
		update
		
		if(keyCode==PConstants.ESC){
			exit()
		}
		
		scene.draw
		
	}
	
	def main(args: Array[String]){
	  runSketch()
	}
	
	override def sketchFullScreen():Boolean = {
  		return false
	}
}