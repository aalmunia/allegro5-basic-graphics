#pragma once
#ifndef BASE_BITMAP_H
#define BASE_BITMAP_H

#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class AppBitmap
{
public:
	AppBitmap();	
	AppBitmap(unsigned int iWidth, unsigned int iHeight);
	AppBitmap(std::string sFilename);
	void init();
	void setBitmapWidth(unsigned int iWidth);
	unsigned int getBitmapWidth();
	void setBitmapHeight(unsigned int iHeight);
	unsigned int getBitmapHeight();
	void setPositionX(float fPosX);
	float getPositionX();
	void setPositionY(float fPosY);
	float getPositionY();
	void setFilenameLoad(std::string sFilename);
	std::string getFilenameLoad();
	void setFilenameSave(std::string sFilename);
	std::string getFilenameSave();
	void drawBitmap(ALLEGRO_DISPLAY* pDisplayToDrawTo);
	void drawBitmap(ALLEGRO_DISPLAY* pDisplayToDrawTo, float fPosX, float fPosY);
	void saveBitmap();
	void saveBitmap(std::string sFilename);
	virtual ~AppBitmap();
protected:
	unsigned int m_iBitmapWidth;
	unsigned int m_iBitmapHeight;
	float m_fPositionX;
	float m_fPositionY;
	std::string m_sFilenameLoad;
	std::string m_sFilenameSave;
	bool m_bFlip = false;
	ALLEGRO_BITMAP* m_pBitmap;
};

#endif

