package trit.alight
import trit.alight._
import processing.core._
import fullscreen._
import scala.collection.mutable.LinkedList


object Main extends processing.core.PApplet{
	var sound = new Sound(this)
	var network = new Network(this)
	
	
	// var scenes = LinkedList.empty[BaseScene]
	
	// var sceneFire = new Fire(this)
	
	
	var scene = new BaseScene(this)
	scene.setSound(sound)
	scene.setNetwork(network)
	
	override def setup = {
		size(displayWidth,displayHeight)
		// size(255,255)
		noCursor()
		
		
		scene.setup
		
	}
	
	def update = {
		network.update
		sound.update
		
		scene.update
		
		println("ok")
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
	def receive(data:Array[Byte]){
		network.receive(data)
	}
}