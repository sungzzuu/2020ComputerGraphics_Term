#include "pch.h"
#include "Shader.h"
#include "Obj.h"

CShader::CShader()
{
}

CShader::~CShader()
{
}

void CShader::Initialize_Shader()
{
	make_vertexShader();
	make_fragmentShader();
}

void CShader::Upadate_Shader(GLuint _vao, GLuint _vbo[2], const OBJECT& _object)
{
	Update_buffer(_vao, _vbo, _object);
	Upadte_Shader_Program();
}

void CShader::make_vertexShader()
{
	vertexsource = filetobuf("vertex.glsl");
	vertexshader = glCreateShader(GL_VERTEX_SHADER); // ���ؽ� ���̴� ��ü �����
	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0); // ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
	glCompileShader(vertexshader); // ���ؽ� ���̴� ������

	// �������� ����� ���� ���� ��� ����üũ
	GLint result;
	GLchar error[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(vertexshader, 512, NULL, error);
		cerr << "ERROR: vertex shader ������ ����\n" << error << endl;
		return;
	}
}

void CShader::make_fragmentShader()
{
	fragmentsource = filetobuf("fragment.glsl");
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER); // �����׸�Ʈ ���̴� ��ü �����
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0); // ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
	glCompileShader(fragmentshader); // �����׸�Ʈ���̴� ������

	// �������� ����� ���� ���� ��� ����üũ
	GLint result;
	GLchar error[512];
	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(fragmentshader, 512, NULL, error);
		cerr << "ERROR: fragment shader ������ ����\n" << error << endl;
		return;
	}

}

void CShader::Update_buffer(GLuint _vao, GLuint _vbo[2], const OBJECT& _object)
{
	glBindVertexArray(_vao);	// vao ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, _vbo[0]); // vbo[0] Ȱ��ȭ&���ε�
	glBufferData(GL_ARRAY_BUFFER, _object.vertices.size() * sizeof(glm::vec3), &_object.vertices[0], GL_STATIC_DRAW); // ���ؽ� ��ǥ�� ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	// ��ǥ���� attribute �ε��� 0���� ��� ���ؽ��� 3*floatũ��
	glEnableVertexAttribArray(0);	// attribute �ε��� 0�� ��밡���ϵ�����

	glBindBuffer(GL_ARRAY_BUFFER, _vbo[1]); // vbo[1] Ȱ��ȭ&���ε�
	glBufferData(GL_ARRAY_BUFFER, _object.color.size() * sizeof(glm::vec3), &_object.color[0], GL_STATIC_DRAW); // ���ؽ� ��ǥ�� ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0); 	// ��ǥ���� attribute �ε��� 1���� ��� ���ؽ��� 3*floatũ��
	glEnableVertexAttribArray(1);	// attribute �ε��� 1�� ��밡���ϵ�����
}

void CShader::Upadte_Shader_Program()
{
	// Update_buffer ���� ���ŵ� ������ ���̴� ���α׷��� �����Ѵ�?
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertexshader);
	glAttachShader(shader_program, fragmentshader);
	glLinkProgram(shader_program);

	GLint result;
	GLchar error[512];

	glGetProgramiv(shader_program, GL_LINK_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(shader_program, 512, NULL, error);
		cerr << "ERROR: shader program ���� ����\n" << error << endl;
		return;
	}
	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);
	glUseProgram(shader_program);
}
