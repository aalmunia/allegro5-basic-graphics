#include "AppBitmap.h"

AppBitmap::AppBitmap()
{
}

AppBitmap::AppBitmap(unsigned int iWidth, unsigned int iHeight)
{
	this->m_iBitmapWidth = iWidth;
	this->m_iBitmapHeight = iHeight;
	al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
	this->m_pBitmap = al_create_bitmap(this->m_iBitmapWidth, this->m_iBitmapHeight);
}

AppBitmap::AppBitmap(std::string sFilename)
{
	al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
	this->m_pBitmap = al_load_bitmap(sFilename.c_str());
}

void AppBitmap::init()
{
	if (this->m_iBitmapHeight > 0 && this->m_iBitmapWidth > 0) {
		al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
		this->m_pBitmap = al_create_bitmap(this->m_iBitmapWidth, this->m_iBitmapHeight);
	}
}

void AppBitmap::setBitmapWidth(unsigned int iWidth)
{
	this->m_iBitmapWidth = iWidth;
}

unsigned int AppBitmap::getBitmapWidth()
{
	return this->m_iBitmapWidth;
}

void AppBitmap::setBitmapHeight(unsigned int iHeight)
{
	this->m_iBitmapHeight = iHeight;
}

unsigned int AppBitmap::getBitmapHeight()
{
	return this->m_iBitmapHeight;
}

void AppBitmap::setPositionX(float fPosX)
{
	this->m_fPositionX = fPosX;
}

float AppBitmap::getPositionX()
{
	return this->m_fPositionX;
}

void AppBitmap::setPositionY(float fPosY)
{
	this->m_fPositionY = fPosY;
}

float AppBitmap::getPositionY()
{
	return this->m_fPositionY;
}

void AppBitmap::setFilenameLoad(std::string sFilename)
{
	this->m_sFilenameLoad = sFilename;
}

std::string AppBitmap::getFilenameLoad()
{
	return this->m_sFilenameLoad;
}

void AppBitmap::setFilenameSave(std::string sFilename)
{
	this->m_sFilenameSave = sFilename;
}

std::string AppBitmap::getFilenameSave()
{
	return this->m_sFilenameSave;
}

void AppBitmap::drawBitmap(ALLEGRO_DISPLAY * pDisplayToDrawTo)
{
	this->drawBitmap(pDisplayToDrawTo, this->m_fPositionX, this->m_fPositionY);
}

void AppBitmap::drawBitmap(ALLEGRO_DISPLAY * pDisplayToDrawTo, float fPosX, float fPosY)
{
	if (pDisplayToDrawTo != NULL) {
		ALLEGRO_BITMAP* pBackbuffer = al_get_backbuffer(pDisplayToDrawTo);
		al_set_target_bitmap(pBackbuffer);
		al_draw_bitmap(this->m_pBitmap, fPosX, fPosY, 0);
		if (this->m_bFlip) {
			al_flip_display();
		}
	}

}

void AppBitmap::saveBitmap()
{
	if (this->m_pBitmap != NULL && !this->m_sFilenameSave.empty()) {
		al_save_bitmap(this->m_sFilenameSave.c_str(), this->m_pBitmap);
	}
}

void AppBitmap::saveBitmap(std::string sFilename)
{
	if (this->m_pBitmap != NULL) {
		al_save_bitmap(sFilename.c_str(), this->m_pBitmap);
	}
}


AppBitmap::~AppBitmap()
{
	if (this->m_pBitmap != NULL) {
		al_destroy_bitmap(this->m_pBitmap);
	}
}
