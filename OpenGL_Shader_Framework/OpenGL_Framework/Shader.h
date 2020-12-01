#pragma once

class CShader
{
public:
	CShader();
	~CShader();

public:
	void Initialize_Shader();
	void Upadate_Shader(GLuint _vao, GLuint _vbo[2], const OBJECT& _object);

private:
	void make_vertexShader();
	void make_fragmentShader();
	void Update_buffer(GLuint _vao, GLuint _vbo[2], const OBJECT& _object);
	void Upadte_Shader_Program();

public:
	const GLuint& Get_shaderProgram() { return shader_program; }

private:
	GLchar* vertexsource, *fragmentsource;	// �ҽ��ڵ� ���� ����
	GLuint vertexshader, fragmentshader;	// ���̴� ��ü
	GLuint shader_program;


};

