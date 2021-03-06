#pragma once

#include "iWindowFactory.h"

#include <memory>

namespace jle
{
	class WindowFactory_GLFW : public iWindowFactory
	{
	public:
		std::unique_ptr<iWindowAPI> CreateWindow() override;

		virtual std::unique_ptr<iWindowInitializer> CreateWindowInitializer() override;
	};
}