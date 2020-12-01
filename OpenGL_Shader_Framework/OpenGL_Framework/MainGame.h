#pragma once
#ifndef __MAINGAME_H__
#define __MAINGAME_H__
#include "Obj.h"
#include "Shader.h"

class CMainGame
{
public:
	CMainGame() {}
	~CMainGame() {}

public:
	void Initialize_MainGame();
	void Update_MainGame();
	void Draw_MainGame();
	void Release_MainGame();
	void Add_Object(OBJID::OBJ _objID);

private:
	list<CObj*> list_objects[OBJID::END];
	CShader Shader;
	GLboolean m_add_Turn = LEFT_TURN;
};

#endif // !__MAINGAME_H__
