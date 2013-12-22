#include "UI.h"
alight::ui::UI::UI(){};
alight::ui::UI::~UI(){};

void alight::ui::UI::setup(){
    fontPath = "fonts/Helvetica.ttf";
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
	
    gui1->setFont(fontPath); 
    
    gui1->addLabel("alight", OFX_UI_FONT_LARGE);
    gui1->addSpacer(); 
    gui1->addSlider("FPS",0.0,255.0,100.0); 
    gui1->addToggle("FULLSCREEN", false);
    gui1->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));
    
    gui1->addSpacer(); 

    
    gui1->autoSizeToFitWidgets(); 
    ofAddListener(gui1->newGUIEvent, this, &UI::Event); 
    gui1->loadSettings("GUI/guiSettings1.xml");
	
};

void alight::ui::UI::set2(){
	float xInit = 0; 
    float length = 255-xInit; 
	gui2 = new ofxUIScrollableCanvas(255, 0, 127, ofGetHeight());
    gui2->setFont(fontPath); 
	
    gui2->addLabel("Theme", OFX_UI_FONT_LARGE);
    
    ofAddListener(gui2->newGUIEvent, this, &UI::Event); 
    gui2->loadSettings("GUI/guiSettings2.xml");
	
	
};