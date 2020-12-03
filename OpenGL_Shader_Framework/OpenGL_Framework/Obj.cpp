#include "pch.h"
#include "Obj.h"

CObj::CObj(GLuint* _shader_program)
{
	shader_program = _shader_program;
	glGenVertexArrays(1, &vao); //--- VAO 를 지정하고 할당하기
	glGenBuffers(2, vbo); //--- 2개의 VBO를 지정하고 할당하기
}

CObj::~CObj()
{
}
