#pragma once

#include "jleComponent.h"
#include "cTransform.h"

#include "iQuadRendering.h"
#include "iTexture.h"

#include <memory>
#include <string>

class cSprite : public jle::jleComponent
{
public:
	cSprite(jle::jleObject* owner = nullptr, jle::jleScene* scene = nullptr);

	void CreateAndSetTextureFromPath(const std::string& path);
	void SetTexture(std::shared_ptr<jle::iTexture> texture);
	void SetRectangleDimensions(int width, int height);
	void SetTextureBeginCoordinates(int x, int y);

	virtual void Start() override;
	virtual void Update(float dt) override;

	virtual const std::string_view GetComponentName() const override;

private:
	TexturedQuad quad;
	std::shared_ptr<cTransform> transform;

};

