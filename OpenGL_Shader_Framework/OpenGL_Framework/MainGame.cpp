#include "pch.h"
#include "MainGame.h"
#include "Original_Shape.h"
#include "CPlayer.h"

void CMainGame::Initialize_MainGame()
{
	Shader.Initialize_Shader();
}

void CMainGame::Update_MainGame()
{
	for (int i = 0; i < OBJID::END; ++i) {
		for (auto& object : list_objects[i]) {
			object->Update();
			Shader.Upadate_Shader(object->Get_vao(), object->Get_vbo(), object->Get_Object());
			object->Draw();

		}
	}
}

void CMainGame::Draw_MainGame()
{

}

void CMainGame::Release_MainGame()
{
	for (int i = 0; i < OBJID::END; ++i)
	{
		for_each(list_objects[i].begin(), list_objects[i].end(), Safe_Delete<CObj*>);
		list_objects[i].clear();
	}
}

void CMainGame::Add_Object(OBJID::OBJ _objID)
{
	CObj* pObj = nullptr;
	if (_objID == OBJID::PLAYER) {
		 pObj = new CPlayer(*Shader.Get_shaderProgram());
	}
	else {
<<<<<<< HEAD
		pObj = new COriginal_Shape(*Shader.Get_shaderProgram());
		// 삼각형
		glm::vec3 color = { 1.f, 0.f,0.f };
		pObj->Get_Object().vertices.emplace_back(glm::vec3(0.f, 1.f, 0.f));
		pObj->Get_Object().vertices.emplace_back(glm::vec3(-1.f, -1.f, 0.f));
		pObj->Get_Object().vertices.emplace_back(glm::vec3(1.f, -1.f, 0.f));
=======
		//pObj = new COriginal_Shape(Shader.Get_shaderProgram());
		//// 삼각형
		//glm::vec3 color = { 1.f, 0.f,0.f };
		//pObj->Get_Object().vertices.emplace_back(glm::vec3(0.f, 1.f, 0.f));
		//pObj->Get_Object().vertices.emplace_back(glm::vec3(-1.f, -1.f, 0.f));
		//pObj->Get_Object().vertices.emplace_back(glm::vec3(1.f, -1.f, 0.f));
>>>>>>> 95710e820d8c7be0f35a2537d14fa7534e7b942e

		//pObj->Get_Object().color.emplace_back(color);
		//pObj->Get_Object().color.emplace_back(color);
		//pObj->Get_Object().color.emplace_back(color);

		//if (LEFT_TURN == m_add_Turn) {
		//	// x,y 각각의 이동량
		//	// 처음 위치 
		//	// => 두 값 세트로 
		//	//pObj->Set_Translate(glm::vec3(-1.f, 1.f, 0.f));

		//}
		//else {

		//}
	}
	list_objects[_objID].emplace_back(pObj);
}
