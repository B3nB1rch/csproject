#pragma once
#include "Window.h"



class application_window : public Window
{
public:
	application_window();
	~application_window();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
};