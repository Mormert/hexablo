#pragma once
#include "iRenderingFactory.h"

namespace jle
{
	class RenderingFactory_OpenGL : public iRenderingFactory
	{
	public:
		virtual std::unique_ptr<iRenderingAPI> CreateRenderingAPI() override;

		virtual std::unique_ptr<iQuadRendering> CreateQuadRendering() override;

		virtual std::unique_ptr<iFramebuffer> CreateFramebuffer(unsigned int width, unsigned int height) override;

		virtual std::unique_ptr<iFullscreenRendering> CreateFullscreenRendering() override;

	};
}