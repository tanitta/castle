#include "ofMain.h"
#include "ofxUI.h"
namespace alight{
namespace interface{
	class GUI
	{
	public:
		ofxUICanvas *gui;
		GUI(){
			gui = new ofxUICanvas();    
		};
		~GUI(){};
		void setup(){
			ofSetVerticalSync(true); 
			ofEnableSmoothing(); 
			gui->setDrawBack(false); 

			gui->addLabel("BUTTONS/TOGGLES", OFX_UI_FONT_LARGE);
			gui->addSpacer();
			gui->addLabel("BUTTONS");
			gui->addButton("B1", false, 44, 44);
			gui->addButton("B2", false);
			gui->addSpacer();
			gui->addLabel("TOGGLES");
			gui->addToggle("T1", false, 44, 44);
			gui->addToggle("T2", false);
			gui->addSpacer();

			gui->addFPSSlider("FPS SLIDER");
			gui->addWidgetDown(new ofxUILabel("CUSTOM WIDGET LAYOUT", OFX_UI_FONT_LARGE), OFX_UI_ALIGN_RIGHT);

			gui->addWidget(new ofxUILabel(360, 300, "2D PAD", OFX_UI_FONT_MEDIUM)); 				
			// gui->addWidgetSouthOf(new ofxUI2DPad("PAD", ofPoint(0, 320), ofPoint(0, 190), ofPoint(320*.5,190*.5), 320, 190), "2D PAD");
			// gui->addWidgetWestOf(new ofxUITextInput("TEXT INPUT", "Input Text", 320, 16, 0, 0, OFX_UI_FONT_MEDIUM), "PAD");
			// gui->addWidgetEastOf(new ofxUISlider("0", 0.0, 255.0, 150, 16, 190), "PAD");
			// gui->addWidgetNorthOf(new ofxUIToggle("D_GRID", false, 16, 16), "2D PAD");
			// gui->addWidgetWestOf(new ofxUIToggle("D2", true, 16, 16), "D_GRID");
			// gui->addWidgetLeft(new ofxUIToggle("NEW", true, 16, 16));

			// gui->addWidgetNorthOf(new ofxUISlider("GREEN", 0.0, 255.0, 150, 320, 16), "NEW");
			// gui->addWidgetNorthOf(new ofxUISlider("BLUE", 0.0, 255.0, 150, 320, 16), "GREEN");
			gui->addWidgetEastOf(new ofxUISlider("RED", 0.0, 255.0, 150, 320, 16), "2D PAD");
			gui->autoSizeToFitWidgets(); 
			ofAddListener(gui->newGUIEvent,this,&alight::interface::GUI::guiEvent);	
			// ofBackground(red, green, blue); 
		};
		void draw(){
			
		};

		void keyPressed(int key){};
		void guiEvent(ofxUIEventArgs &e){};

		void exit(){
			gui->saveSettings("settings.xml");     
    			delete gui; 
		};
	};
}
}
