#include <cstdlib>
#include <string>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Application.h"

int main(int argc, char** argv) {

	std::string sTitle = "Allegro 5 Bitmap Application";
	Application* oApp = new Application(600, 600, sTitle);
	std::vector<std::string> vecFilenames;	
	vecFilenames.push_back("vivien1.jpg");
	vecFilenames.push_back("vivien2.jpg");
	vecFilenames.push_back("vivien3.jpg");
	vecFilenames.push_back("vivien4.jpg");
	oApp->initApp();	
	oApp->initFileBitmaps(vecFilenames);
	oApp->setBitmapPosition(0, 0.0f, 0.0f);
	oApp->setBitmapPosition(1, 300.0f, 0.0f);
	oApp->setBitmapPosition(2, 0.0f, 300.0f);
	oApp->setBitmapPosition(3, 300.0f, 300.0f);	
	oApp->drawAllBitmaps();
	oApp->mainLoop();
	delete oApp;
	return 0;

}