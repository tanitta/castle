#include "UI.h"
alight::ui::UI::UI(){};
alight::ui::UI::~UI(){};

void alight::ui::UI::setup(){
	ofEnableSmoothing(); 
	ofBackground(32); 
	
	set1();
	set2();
};

void alight::ui::UI::exit()
{
    gui1->saveSettings("GUI/guiSettings1.xml"); 
    gui2->saveSettings("GUI/guiSettings2.xml"); 
    delete gui1; 
    delete gui2; 
}

void alight::ui::UI::Event(ofxUIEventArgs &e)
{
// 	string name = e.widget->getName(); 
// 	int kind = e.widget->getKind(); 
// 	cout << "got event from: " << name << endl; 	
	
// 	if(name == "RED")
// 	{
// 		ofxUISlider *slider = (ofxUISlider *) e.widget; 
// 		cout << "RED " << slider->getScaledValue() << endl; 
// 		red = slider->getScaledValue(); 
// 	}
// 	else if(name == "GREEN")
// 	{
// 		ofxUISlider *slider = (ofxUISlider *) e.widget; 
// 		cout << "GREEN " << slider->getScaledValue() << endl; 
// 		green = slider->getScaledValue(); 
// 	}
	
// 	else if(name == "BLUE")
// 	{
// 		ofxUISlider *slider = (ofxUISlider *) e.widget; 
// 		cout << "BLUE " << slider->getScaledValue() << endl; 
// 		blue = slider->getScaledValue(); 		
// 	}
// 	else if(name == "DRAW GRID")
// 	{
// 		ofxUIButton *button = (ofxUIButton *) e.widget; 
// 		bdrawGrid = button->getValue(); 
// 	}
// 	else if(name == "D_GRID")
// 	{
// 		ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
// 		bdrawGrid = toggle->getValue(); 
// 	}
//     else if(name == "TEXT INPUT")
//     {
//         ofxUITextInput *textinput = (ofxUITextInput *) e.widget; 
//         if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER)
//         {
//             cout << "ON ENTER: "; 
// //            ofUnregisterKeyEvents((testApp*)this); 
//         }
//         else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_FOCUS)
//         {
//             cout << "ON FOCUS: "; 
//         }
//         else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS)
//         {
//             cout << "ON BLUR: "; 
// //            ofRegisterKeyEvents(this);             
//         }        
//         string output = textinput->getTextString(); 
//         cout << output << endl; 
//     }
}

void alight::ui::UI::keyPressed(int key){
}

void alight::ui::UI::set1(){
	gui1 = new ofxUICanvas();
	
    gui1->setFont("fonts/frabk.ttf"); 
    
    gui1->addLabel("alight", OFX_UI_FONT_LARGE);
    gui1->addSpacer(); 
    gui1->addSlider("FPS",0.0,255.0,100.0); 
    gui1->addToggle("FULLSCREEN", false);
    gui1->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));
    
    gui1->addSpacer(); 
    gui1->addLabel("Network", OFX_UI_FONT_LARGE);

	vector<float> buffer1;
	vector<float> buffer2;
	vector<float> buffer3;
	vector<float> buffer4; 
    for(int i = 0; i < 256; i++)
    {
        buffer1.push_back(0.0);
        buffer2.push_back(0.0);
        buffer3.push_back(0.0);
        buffer4.push_back(0.0);
    }
    
    float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 
    
    gui1->addLabel("drawer1", OFX_UI_FONT_MEDIUM);
	gui1->add2DPad("PAD1Drawer", ofPoint(0,length-xInit), ofPoint(0,120), ofPoint((length-xInit)*.5,120*.5), length-xInit,120);
    
    gui1->addLabel("drawer2", OFX_UI_FONT_MEDIUM);
	gui1->add2DPad("PAD2Drawer", ofPoint(0,length-xInit), ofPoint(0,120), ofPoint((length-xInit)*.5,120*.5), length-xInit,120);
    
    gui1->addLabel("drawer3", OFX_UI_FONT_MEDIUM);
	gui1->add2DPad("PAD3Drawer", ofPoint(0,length-xInit), ofPoint(0,120), ofPoint((length-xInit)*.5,120*.5), length-xInit,120);
   	
    gui1->addLabel("drawer4", OFX_UI_FONT_MEDIUM);
	gui1->add2DPad("PAD4Drawer", ofPoint(0,length-xInit), ofPoint(0,120), ofPoint((length-xInit)*.5,120*.5), length-xInit,120);
    
    
    
    
    gui1->autoSizeToFitWidgets(); 
    ofAddListener(gui1->newGUIEvent, this, &UI::Event); 
    gui1->loadSettings("GUI/guiSettings1.xml");
	
};

void alight::ui::UI::set2(){
	float xInit = 0; 
    float length = 255-xInit; 
	gui2 = new ofxUIScrollableCanvas(255, 0, 127, ofGetHeight());
    gui2->setFont("fonts/frabk.ttf"); 
	
    gui2->addLabel("Theme", OFX_UI_FONT_LARGE);
    
    ofAddListener(gui2->newGUIEvent, this, &UI::Event); 
    gui2->loadSettings("GUI/guiSettings2.xml");
	
	
};