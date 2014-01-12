#include "UI.h"
alight::ui::UI::UI(){};
alight::ui::UI::~UI(){};

void alight::ui::UI::setup(){
    fontPath = "fonts/Helvetica.ttf";
	ofEnableSmoothing(); 
	ofBackground(32); 
};

void alight::ui::UI::exit()
{
 
}

void alight::ui::UI::Event(ofxUIEventArgs &e)
{
}

void alight::ui::UI::keyPressed(int key){
}
