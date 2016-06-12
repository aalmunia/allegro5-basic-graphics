/*
* File:   BaseApplication.h
* Author: aalmunia
*
* Created on May 26, 2016, 2:14 PM
*/

#pragma once
#ifndef BASE_APPLICATION_H
#define BASE_APPLICATION_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "AppBitmap.h"

class BaseApplication {
public:
	BaseApplication();
	BaseApplication(const BaseApplication& orig);
	BaseApplication(unsigned int iWidth, unsigned int iHeight, std::string sName);	
	void initApp();
	ALLEGRO_DISPLAY* getDisplay() const;
	void setNewBitmapSize(unsigned int iWidth, unsigned int iHeight);
	std::vector<unsigned int> getNewBitmapSize();
	void initFileBitmaps(std::vector<std::string> vecFilenames);
	void initEmptyBitmaps(unsigned int iHowMany);
	// void autoDrawBitmapCollection();
	void setBitmapPosition(int iBitmap, float fPosX, float fPosY);
	void drawBitmap(int iBitmap);
	void drawAllBitmaps();
	virtual int mainLoop() = 0;
	virtual ~BaseApplication();
protected:
	ALLEGRO_DISPLAY *m_pDisplay = NULL;
	unsigned int m_iWindowWidth = 0;
	unsigned int m_iWindowHeight = 0;
	std::string m_sWindowName;	
	ALLEGRO_COLOR m_oColRed;
	ALLEGRO_COLOR m_oColGreen;
	ALLEGRO_COLOR m_oColBlue;
	ALLEGRO_COLOR m_oColWhite;
	ALLEGRO_EVENT_QUEUE* m_pEventQueue;
	void initColors();
	// Nuevas propiedades
	std::vector<AppBitmap*> m_vecBitmaps;
	unsigned int m_iNewBitmapWidth;
	unsigned int m_iNewBitmapHeight;
};

#endif /* APPLICATION_H */