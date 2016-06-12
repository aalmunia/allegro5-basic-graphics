#include "Application.h"

Application::~Application()
{
}

void Application::saveBufferAsImage(std::string sFilename)
{
	ALLEGRO_BITMAP* oBackBuffer = al_get_backbuffer(this->m_pDisplay);
	al_save_bitmap(sFilename.c_str(), oBackBuffer);
}

int Application::mainLoop() {

	this->m_pEventQueue = al_create_event_queue();
	al_register_event_source(this->m_pEventQueue, al_get_keyboard_event_source());
	al_register_event_source(this->m_pEventQueue, al_get_display_event_source(this->m_pDisplay));

	while (true) {
		ALLEGRO_EVENT oEvent;
		al_wait_for_event(this->m_pEventQueue, &oEvent);

		switch (oEvent.type) {
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				return 0;
			break;

			case ALLEGRO_EVENT_KEY_DOWN:
				return 0;
			break;
		}

		al_flip_display();
	}
}
