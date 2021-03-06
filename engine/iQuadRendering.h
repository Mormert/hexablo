#pragma once

#include "Texture.h"

#include <memory>

enum class RenderingMethod { Dynamic, Static };

struct Quad
{
	float x = 0.f, y = 0.f;
	float depth = 0.f;
};

struct TexturedQuad : public Quad
{
	TexturedQuad(std::shared_ptr<jle::iTexture> t) : texture{ t } {}

	std::shared_ptr<jle::iTexture> texture;

	// Coordinates on the texture
	int textureX = 0, textureY = 0;

	// Dimensions of quad on the texture
	unsigned int width = 1, height = 1;
};

struct ColoredQuad : public Quad
{
	unsigned char r, g, b, a;
};

class iQuadRendering
{
public:
	virtual ~iQuadRendering(){}

	virtual void SendTexturedQuad(TexturedQuad& texturedQuad, RenderingMethod renderingMethod) = 0;
	virtual void SendColoredQuad(ColoredQuad& coloredQuad, RenderingMethod renderingMethod) = 0;
};