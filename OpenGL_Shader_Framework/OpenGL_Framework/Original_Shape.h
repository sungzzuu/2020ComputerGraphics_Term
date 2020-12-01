#pragma once
#include "Obj.h"
class COriginal_Shape : public CObj
{
public:
	COriginal_Shape(GLint _shader_program);
	~COriginal_Shape();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Draw() override;
	virtual void Release() override;
	virtual void Set_ModelTransform() override;
};

