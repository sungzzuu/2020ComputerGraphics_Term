#pragma once
#ifndef __OBJ_H__
#define __OBJ_H__


class CObj
{
public:
	CObj(GLint _shader_program);
	~CObj();
public:
	virtual void Initialize()=0;
	virtual void Update()=0;
	virtual void Late_Update() = 0;
	virtual void Draw()=0;
	virtual void Release()=0;

public:
	GLuint& Get_vao() { return vao; }
	GLuint* Get_vbo() { return vbo; }
	OBJECT& Get_Object() { return object; }
public:
	void Set_Translate(glm::vec3 _moveSize) { object.model_transform.Translate += _moveSize; }
public:
	void Set_ShaderProgram(GLuint _shader_program) { shader_program = _shader_program; }

protected:
	virtual void Set_ModelTransform() = 0;
	GLuint vao, vbo[2];
	GLuint shader_program;
	OBJECT object;
};


#endif // !__OBJ_H__

