#pragma once

#include "JLE_ENGINE_CONFIG.h"

#include <string>

#include <functional>

namespace jle
{
	struct WindowSettings
	{
		std::string WindowTitle{ "jle game engine" };

		unsigned int windowWidth = 500, windowHeight = 500;
		unsigned int windowWidthMin = 100, windowHeightMin = 100;

		std::string iconPath{ JLE_ENGINE_PATH + "/EditorResources/jle_default_icon.png" };

		bool windowIsRezisable = true;
		bool windowDisplayCursor = true;
	};

	class iWindowAPI
	{
	public:
		virtual ~iWindowAPI() {};

		virtual void SetWindowSettings(WindowSettings& windowSettings) = 0;

		// Adds a function to be called when window is resized. Returns an id that can be used when removing the callback
		virtual unsigned int AddWindowResizeCallback(std::function<void(unsigned int, unsigned int)> callback) = 0;

		// Removes a resize callback with the id retrieved from the add callback method
		virtual void RemoveWindowResizeCallback(unsigned int callback_id) = 0;


		virtual void DisplayCursor(bool enable) = 0;
		virtual bool IsCursorDisplayed() = 0;

		virtual unsigned int GetWindowHeight() = 0;
		virtual unsigned int GetWindowWidth() = 0;

	};
}