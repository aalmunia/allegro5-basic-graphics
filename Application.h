#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

// #include <allegro5/allegro.h>
// #include <allegro5/allegro_image.h>

#include <string>
#include "BaseApplication.h"

class Application :	public BaseApplication {
	public:
		Application(unsigned int iWidth, unsigned int iHeight, std::string sName) : BaseApplication(iWidth, iHeight, sName) {
			al_init();
			al_install_mouse();
			al_install_keyboard();
			al_init_image_addon();
		};
		virtual ~Application();
		void saveBufferAsImage(std::string sFilename);
		int mainLoop();
};

#endif