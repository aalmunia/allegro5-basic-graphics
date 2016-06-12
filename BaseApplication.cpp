/*
* File:   BaseApplication.cpp
* Author: aalmunia
*
* Created on May 26, 2016, 2:14 PM
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "BaseApplication.h"

/**
* Default empty constructor
*/
BaseApplication::BaseApplication() {
}

/**
* Default copy-constructor
* @param orig The BaseApplication object to be copied
*/
BaseApplication::BaseApplication(const BaseApplication& orig) {
}

/**
* Constructor for BaseApplication class.
* @param iWidth Width of the window
* @param iHeight Height of the window
* @param sName Title of the window
*/
BaseApplication::BaseApplication(unsigned int iWidth, unsigned int iHeight, std::string sName) {
	this->m_iWindowWidth = iWidth;
	this->m_iWindowHeight = iHeight;
	this->m_sWindowName = sName;
}

/**
* Method that initializes the Allegro library, along with the rest of the objects
* needed to use the class.
*/
void BaseApplication::initApp() {

	this->m_pDisplay = al_create_display(this->m_iWindowWidth, this->m_iWindowHeight);

	if (this->m_pDisplay != NULL) {
		al_set_window_title(this->m_pDisplay, this->m_sWindowName.c_str());		
		this->initColors();
		al_clear_to_color(this->m_oColWhite);
		std::cout << "Initialized OK" << std::endl;
	}
}

ALLEGRO_DISPLAY * BaseApplication::getDisplay() const {
	return this->m_pDisplay;
}

void BaseApplication::setNewBitmapSize(unsigned int iWidth, unsigned int iHeight) {
	this->m_iNewBitmapWidth = iWidth;
	this->m_iNewBitmapHeight = iHeight;
}

std::vector<unsigned int> BaseApplication::getNewBitmapSize() {
	std::vector<unsigned int> vecReturn;
	vecReturn.push_back(this->m_iNewBitmapWidth);
	vecReturn.push_back(this->m_iNewBitmapHeight);
	return vecReturn;
}

void BaseApplication::initFileBitmaps(std::vector<std::string> vecFilenames) {
	for (unsigned int i = 0; i < vecFilenames.size(); i++) {
		AppBitmap* oBitmap = new AppBitmap(vecFilenames[i]);
		this->m_vecBitmaps.push_back(oBitmap);
	}
}

void BaseApplication::initEmptyBitmaps(unsigned int iHowMany) {
	for (unsigned int i = 0; i < iHowMany; i++) {
		AppBitmap* oBitmap = new AppBitmap(this->m_iNewBitmapWidth, this->m_iNewBitmapHeight);
		this->m_vecBitmaps.push_back(oBitmap);
	}
}

void BaseApplication::setBitmapPosition(int iBitmap, float fPosX, float fPosY) {
	this->m_vecBitmaps[iBitmap]->setPositionX(fPosX);
	this->m_vecBitmaps[iBitmap]->setPositionY(fPosY);
}

void BaseApplication::drawBitmap(int iBitmap) {
	float fPosX = this->m_vecBitmaps[iBitmap]->getPositionX();
	float fPosY = this->m_vecBitmaps[iBitmap]->getPositionY();
	this->m_vecBitmaps[iBitmap]->drawBitmap(this->m_pDisplay, fPosX, fPosY);	
}

void BaseApplication::drawAllBitmaps() {
	for (unsigned int i = 0; i < this->m_vecBitmaps.size(); i++) {
		this->drawBitmap(i);
	}
	al_flip_display();
}

/**
* This method initializes the color objects we will be using in the application
*/
void BaseApplication::initColors() {
	this->m_oColRed = al_map_rgb(255, 0, 0);
	this->m_oColGreen = al_map_rgb(0, 255, 0);
	this->m_oColBlue = al_map_rgb(0, 0, 255);
	this->m_oColWhite = al_map_rgb(255, 255, 255);
}

/**
* BaseApplication destructor (~ctor)
*/
BaseApplication::~BaseApplication() {
	if (this->m_pDisplay != NULL) {
		al_destroy_display(this->m_pDisplay);
	}
	if (this->m_pEventQueue != NULL) {
		al_destroy_event_queue(this->m_pEventQueue);
	}	
}