#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer(GLint _shader_program)
	:CObj(_shader_program)
{
	Initialize();
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{ 
	loadObj<const char*, OBJECT, glm::vec3>("cube.obj", object, glm::vec3(1.0, 0.0, 0.0));

}

void CPlayer::Update()
{
}

void CPlayer::Late_Update()
{
}

void CPlayer::Draw()
{
	
	glEnable(GL_DEPTH_TEST);
	unsigned int modelLocation = glGetUniformLocation(shader_program, "model");
	unsigned int viewLocation = glGetUniformLocation(shader_program, "view");
	unsigned int projLocation = glGetUniformLocation(shader_program, "projection");
	// ============================= 고정 ============================================


	
	// 카메라 좌표 설정
	glm::vec3 cameraPos = {0.f,0.f,1.f};
	glm::vec3 cameraDirection = {0.f,0.f,-1.f};
	glm::vec3 cameraUp = { 0.f,1.f,0.f };




	
	glm::mat4 Scale = glm::mat4(1.f);

	glm::mat4 RotateX = glm::mat4(1.f);
	glm::mat4 RotateY = glm::mat4(1.f);
	glm::mat4 RotateZ = glm::mat4(1.f);

	glm::mat4 Translate = glm::mat4(1.f);

	glm::mat4 RevolutionX = glm::mat4(1.f);
	glm::mat4 RevolutionY = glm::mat4(1.f);
	glm::mat4 RevolutionZ = glm::mat4(1.f);

	glm::mat4 Parent = glm::mat4(1.f);

	glm::mat4 Result = glm::mat4(1.f);

	Scale = glm::scale(Scale, object.model_transform.Scale);

	RotateX = glm::rotate(RotateX, glm::radians(object.model_transform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(object.model_transform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(object.model_transform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, object.model_transform.Translate);

	RevolutionX = glm::rotate(RevolutionX, glm::radians(object.model_transform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(object.model_transform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(object.model_transform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if (object.model_transform.Parent)
		Parent = glm::translate(Parent, object.model_transform.Parent->Translate);

	// 크 자 이 공 부 거꾸로
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateX * RotateY * RotateZ * Scale;

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(Result));


	// ============================= 뷰 변환 ============================================
	glm::mat4 view = glm::mat4(1.f);
	glm::mat4 view_Rotate = glm::mat4(1.f);
	view_Rotate = glm::rotate(view_Rotate, glm::radians(0.f), glm::vec3(0.0, 1.0, 0.0));

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
	// ============================= 뷰 변환 ============================================






	// ============================= 투영 변환 ============================================
	glm::mat4 projection = glm::mat4(1.f);
	projection = glm::perspective(glm::radians(60.f), (float)WINCX / (float)WINCY, 0.1f, 200.f);
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(projection));
	// ============================= 투영 변환 ============================================

	cout << object.model_transform.Translate.x<<','<< object.model_transform.Translate.y<<','<< object.model_transform.Translate.z << endl;
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, object.vertices.size());
}

void CPlayer::Release()
{
}

void CPlayer::Set_ModelTransform()
{
}
