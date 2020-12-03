#include "pch.h"
#include "Obj.h"

CObj::CObj(GLuint* _shader_program)
{
	shader_program = _shader_program;
	glGenVertexArrays(1, &vao); //--- VAO �� �����ϰ� �Ҵ��ϱ�
	glGenBuffers(2, vbo); //--- 2���� VBO�� �����ϰ� �Ҵ��ϱ�
}

CObj::~CObj()
{
}
