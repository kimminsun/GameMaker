#pragma once
#include "Obj.h"
class CLastBoss :
	public CObj
{
public:
	float	MoveTime;
	float	AttTime;
	int		AttCount;

public:
	virtual void Initialize(void);
	virtual int Update(void);
	virtual void Render(void);
	virtual void Release(void);

public:
	CLastBoss();
	virtual ~CLastBoss();
};

