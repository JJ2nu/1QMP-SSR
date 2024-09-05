#include "NumberPrintUIScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"
#include "FontScript.h"

NumberPrintUIScript::NumberPrintUIScript(GameObject* pOwner, std::string ObjName)
	:FontScript(pOwner, ObjName)
{
	Start();
}

void NumberPrintUIScript::Start()
{
	// 글자가 안나와서 위치가 찍히나 확인용
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("StartStageUITextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerShipUI", L"\\TestResource\\Ship_Player_0.bmp");

	m_TextComp = m_pOwner->CreateComponent<TextComponent>("NumberPrintUITextComponent");
	m_TextComp->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //폰트 경로를 찾아서 로드
	m_TextComp->m_uColor = RGB(0, 0, 0); // 폰트 색
	m_TextComp->m_tString.push_back(&m_sNumber);  // 이걸 해주어야지 출력된다 꼭 해라
}

void NumberPrintUIScript::FixedUpdate(float fixedDeltaTime)
{
	// 여기를 수정해서 처리 하면 됨.
	m_iNumber += 1; // static으로 값 받아서 누적해서 사용하면 됨
	m_sNumber = std::to_wstring(static_cast<int>(m_iNumber)) + L"%";
}



