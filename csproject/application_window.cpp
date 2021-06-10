#include "application_window.h"
#include "graphics_engine.h"
application_window::application_window()
{
}


application_window::~application_window()
{
}

void application_window::onCreate()
{
	Window::onCreate();
	graphics_engine::get()->init();

}

void application_window::onUpdate()
{
	Window::onUpdate();

}

void application_window::onDestroy()
{
	Window::onDestroy();
	graphics_engine::get()->release();

}