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
	vertexshader = glCreateShader(GL_VERTEX_SHADER); // 버텍스 쉐이더 객체 만들기
	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0); // 쉐이더 코드를 쉐이더 객체에 넣기
	glCompileShader(vertexshader); // 버텍스 쉐이더 컴파일

	// 컴파일이 제대로 되지 않은 경우 에러체크
	GLint result;
	GLchar error[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(vertexshader, 512, NULL, error);
		cerr << "ERROR: vertex shader 컴파일 실패\n" << error << endl;
		return;
	}
}

void CShader::make_fragmentShader()
{
	fragmentsource = filetobuf("fragment.glsl");
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER); // 프래그먼트 쉐이더 객체 만들기
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0); // 쉐이더 코드를 쉐이더 객체에 넣기
	glCompileShader(fragmentshader); // 프래그먼트쉐이더 컴파일

	// 컴파일이 제대로 되지 않은 경우 에러체크
	GLint result;
	GLchar error[512];
	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(fragmentshader, 512, NULL, error);
		cerr << "ERROR: fragment shader 컴파일 실패\n" << error << endl;
		return;
	}

}

void CShader::Update_buffer(GLuint _vao, GLuint _vbo[2], const OBJECT& _object)
{
	glBindVertexArray(_vao);	// vao 바인드
	glBindBuffer(GL_ARRAY_BUFFER, _vbo[0]); // vbo[0] 활성화&바인드
	glBufferData(GL_ARRAY_BUFFER, _object.vertices.size() * sizeof(glm::vec3), &_object.vertices[0], GL_STATIC_DRAW); // 버텍스 죄표값 저장
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	// 좌표값을 attribute 인덱스 0번에 명시 버텍스당 3*float크기
	glEnableVertexAttribArray(0);	// attribute 인덱스 0번 사용가능하도록함

	glBindBuffer(GL_ARRAY_BUFFER, _vbo[1]); // vbo[1] 활성화&바인드
	glBufferData(GL_ARRAY_BUFFER, _object.color.size() * sizeof(glm::vec3), &_object.color[0], GL_STATIC_DRAW); // 버텍스 죄표값 저장
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0); 	// 좌표값을 attribute 인덱스 1번에 명시 버텍스당 3*float크기
	glEnableVertexAttribArray(1);	// attribute 인덱스 1번 사용가능하도록함
}

void CShader::Upadte_Shader_Program()
{
	// Update_buffer 에서 갱신된 정보를 쉐이더 프로그램에 연결한다?
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertexshader);
	glAttachShader(shader_program, fragmentshader);
	glLinkProgram(shader_program);

	GLint result;
	GLchar error[512];

	glGetProgramiv(shader_program, GL_LINK_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(shader_program, 512, NULL, error);
		cerr << "ERROR: shader program 연결 실패\n" << error << endl;
		return;
	}
	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);
	glUseProgram(shader_program);
}
