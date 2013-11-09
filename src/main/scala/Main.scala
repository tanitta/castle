package trit.alight
import trit.alight._
import processing.core._
import fullscreen._



object Main extends processing.core.PApplet{
	var scene = new BaseScene(this)
	override def setup = {
		size(displayWidth,displayHeight)
		noCursor()
		
		scene.setup
	}
	
	def update = {
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
  		return true
	}
}