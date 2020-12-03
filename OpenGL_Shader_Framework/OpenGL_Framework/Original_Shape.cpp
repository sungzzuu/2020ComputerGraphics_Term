#include "pch.h"
#include "Original_Shape.h"

COriginal_Shape::COriginal_Shape(GLint _shader_program)
	:CObj(_shader_program)
{
}

COriginal_Shape::~COriginal_Shape()
{
}

void COriginal_Shape::Initialize()
{
}

void COriginal_Shape::Update()
{
}

void COriginal_Shape::Late_Update()
{
}

void COriginal_Shape::Draw()
{
	glEnable(GL_DEPTH_TEST);
	// ============================= 고정 ============================================
	glLineWidth(1.f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	unsigned int modelLocation = glGetUniformLocation(shader_program, "model");
	unsigned int viewLocation = glGetUniformLocation(shader_program, "view");
	unsigned int projLocation = glGetUniformLocation(shader_program, "projection");
	// ============================= 고정 ============================================


	// ============================= 뷰 변환 ============================================
	// 카메라 좌표 설정
	glm::vec3 cameraPos = {0.f,0.f,20.f};
	glm::vec3 cameraDirection = {0.f,0.f,0.f};
	glm::vec3 cameraUp = { 0.f,1.f,0.f };




	glm::mat4 view = glm::mat4(1.f);
	glm::mat4 view_Rotate = glm::mat4(1.f);
	view_Rotate = glm::rotate(view_Rotate, glm::radians(0.f), glm::vec3(0.0, 1.0, 0.0));

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
	// ============================= 뷰 변환 ============================================

	// ============================= 투영 변환 ============================================
	glm::mat4 projection = glm::mat4(1.f);
	projection = glm::perspective(glm::radians(45.f), (float)WINCX / (float)WINCY, 1.f, 100.f);
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, &projection[0][0]);
	// ============================= 투영 변환 ============================================

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

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, object.vertices.size());
}

void COriginal_Shape::Release()
{
}

void COriginal_Shape::Set_ModelTransform()
{
	
}
