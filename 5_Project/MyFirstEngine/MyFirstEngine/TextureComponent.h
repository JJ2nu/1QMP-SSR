#pragma once
#include "RenderComponent.h"
#include "SceneBase.h"

class Texture;

class TextureComponent : public RenderComponent
{
public:
	void FixedUpdate(float fixedDeltaTime) override;
	void Update(float deltaTime) override;
	void Render() override;

	void SetExcep(UINT excep) { m_uExcep = excep; }
	UINT GetExcep() { return m_uExcep; }

#define MaxTexture 120

public:
	Texture* m_tTexture[MaxTexture];
	UINT m_uRenderIndex;
	UINT m_uExcep;                                                                                        
	UINT m_uAlpha;
	//flag 0: TransparentBlt, 1: BitBlt, 2: AlphaBlend
	int m_iRenderFlag;

	Vector3 m_vOffset;


public:
	TextureComponent(GameObject* pOwner, const std::string& ObjName);
	virtual ~TextureComponent();

};

