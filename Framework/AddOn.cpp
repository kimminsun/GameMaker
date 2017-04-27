#include "stdafx.h"
#include "FollowMonster.h"
#include "TextureMgr.h"
#include "DeviceMgr.h"
#include "TimeMgr.h"
#include "ObjMgr.h"
#include "AddOn.h"


CAddOn::CAddOn()
{
}


CAddOn::~CAddOn()
{
}
void CAddOn::Initialize(void)
{
	Pos = D3DXVECTOR3(2000, 300, 0);
	Angle = 0;
	Radius = 35;
	strTextureKey = L"AddOn";

	Dir = D3DXVECTOR3(0, 0, 0);

}
int CAddOn::Update(void)
{
	float DeltaTime = CTimeMgr::GetInst()->GetTime();

	CObj* Player = CObjMgr::GetInst()->GetPlayer();

	D3DXVECTOR3 OriginDir = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 tmpTarget = Player->Pos;
	tmpTarget.x -= 90;
	tmpTarget.y += 50;
	OriginDir = tmpTarget - Pos;

	D3DXVec3Normalize(&Dir, &OriginDir);

	Pos += Dir * DeltaTime * 100;


	ComputeMatrix();
	return 0;
}

void CAddOn::Render(void)
{
	//이미지를 가져온다.
	TEXINFO*	pTexInfo = CTextureMgr::GetInst()->GetTextureInfo(strTextureKey);

	D3DXVECTOR3 vCenter = D3DXVECTOR3(pTexInfo->TexInfo.Width / 2.f
		, pTexInfo->TexInfo.Height / 2.f, 0.f);

	CDeviceMgr::GetInst()->GetSprite()->SetTransform(&matWorld);

	CDeviceMgr::GetInst()->GetSprite()->Draw(pTexInfo->pTexture
		, NULL, &vCenter, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
}
void CAddOn::Release(void)
{

}