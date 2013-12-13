#include "Network.h"

alight::Network::Network(){
	count = 0;
	udpConnection.Create();
	udpConnection.BindMcast("224.0.0.0",6000);
	udpConnection.SetNonBlocking(true);
	// udpConnection.Bind(6000);
};

void alight::Network::threadedFunction(){
	while( isThreadRunning() != 0 ){
		if( lock() ){
			count++;
			udpConnection.Receive(udpMessage,10);
			int id = (int)udpMessage[0];
			drawers[id].mouseX = (int)udpMessage[1] + 128*(int)udpMessage[3];
			drawers[id].mouseY = (int)udpMessage[2] + 128*(int)udpMessage[4];
				drawers[id].isDraw = (int)udpMessage[5];
			// if(count > 50000) count = 0;	/* code */
			
			unlock();
			ofSleepMillis(1);
		}
	}
};

alight::Network::Drawer *alight::Network::GetHanDrawer(){
	return drawers;
};

void alight::Network::draw(){
	string str = "I am a slowly increasing thread. \nmy current count is: ";

	if( lock() ){
		// str += ofToString(count) + "\n";
		// for (int i = 0; i < 4; i++)
		// {
		// 	str += "drawers[" + ofToString(i) + "]\n";
		// 	str += "mouseX : " + ofToString(drawers[i].mouseX) + "\n";
		// 	str += "mouseY : " + ofToString(drawers[i].mouseY) + "\n";
		// 	str += "isDraw : " + ofToString(drawers[i].isDraw) + "\n\n";
		// }
		// unlock();
	}else{
		str = "can't lock!\neither an error\nor the thread has stopped";
	}
	ofDrawBitmapString(str, 50, 56);
};