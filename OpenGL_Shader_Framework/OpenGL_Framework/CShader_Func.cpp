#include "pch.h"
#include "CShader_Func.h"

CShader_Func::CShader_Func()
{
	
}

CShader_Func::~CShader_Func()
{
}

void CShader_Func::Call_Vao()
{
	glEnable(GL_DEPTH_TEST);
	// ============================= ���� ============================================
	glLineWidth(1.f);
	glPolygonMode(GL_FRONT_AND_BACK, ePolygonMode);
	// ����� VAO �ҷ�����
	glUseProgram(s_program);
	// s_program ���̴� ��� �𵨺�ȯ
	unsigned int modelLocation = glGetUniformLocation(s_program, "model");
	unsigned int viewLocation = glGetUniformLocation(s_program, "view");
	unsigned int projLocation = glGetUniformLocation(s_program, "projection");
	// ============================= ���� ============================================
	
	
	// ============================= �� ��ȯ ============================================
	// ī�޶� ��ǥ ����
	glm::vec3 cameraPos = Camera_Pos;
	glm::vec3 cameraDirection = m_Camera_Desc.cameraDirection;
	glm::vec3 cameraUp = m_Camera_Desc.cameraUp;
	

	

	glm::mat4 view = glm::mat4(1.f);
	glm::mat4 view_Rotate = glm::mat4(1.f);
	view_Rotate = glm::rotate(view_Rotate, glm::radians(m_Camera_Rotate_Angle), glm::vec3(0.0, 1.0, 0.0));

	view = view_Rotate * glm::lookAt(cameraPos, cameraDirection, cameraUp);
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
	// ============================= �� ��ȯ ============================================

	// ============================= ���� ��ȯ ============================================
	glm::mat4 projection = glm::mat4(1.f);
	projection = glm::perspective(glm::radians(45.f), (float)WINCX / (float)WINCY, 1.f, 100.f);
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, &projection[0][0]);
	// ============================= ���� ��ȯ ============================================

	glm::mat4 Tx = glm::mat4(1.0f);
	glm::mat4 Rz = glm::mat4(1.0f);
	glm::mat4 TR = glm::mat4(1.0f);

	Tx = glm::translate(Tx, glm::vec3(0.0, 0.0, 0.0));
	Rz = glm::rotate(Rz, glm::radians(85.f), glm::vec3(1.0, 0.0, 0.0));

	TR = Tx * Rz;

	
	// ��� ����
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(TR));
	
	
	int vIndex = 0;

	
	Set_ModelTransform(stage.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, stage.vertices.size());

	Set_PlayerArmTransform(leftArm.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, leftArm.vertices.size());

	Set_PlayerArmTransform(rightArm.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, rightArm.vertices.size());

	Set_ModelTransform(Body.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, Body.vertices.size());

	Set_PlayerArmTransform(leftLeg.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, leftLeg.vertices.size());

	Set_PlayerArmTransform(rightLeg.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, rightLeg.vertices.size());


	Set_PlayerArmTransform(Head.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, Head.vertices.size());

	Set_PlayerArmTransform(Nose.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, Nose.vertices.size());

	/////////////////////////////////////////////////////

	Set_ArmModelTransform(running_machine.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, running_machine.vertices.size());

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Set_RailTransform(running_machine_rail.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, running_machine_rail.vertices.size());

	glPolygonMode(GL_FRONT_AND_BACK, ePolygonMode);

	Set_ModelTransform(tree.branch.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, tree.branch.vertices.size());

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Set_ModelTransform(tree.Grass.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, tree.Grass.vertices.size());


	glPolygonMode(GL_FRONT_AND_BACK, ePolygonMode);

	Set_ModelTransform(pullbar.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, pullbar.vertices.size());

	Set_ModelTransform_pullbarMan(pullbarMan.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, pullbarMan.vertices.size());

	Set_ModelTransform(runningMan[RUNNING::RUNNING_BODY].model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, runningMan[RUNNING::RUNNING_BODY].vertices.size());
	
	Set_LegTransform(runningMan[RUNNING::RUNNING_LEFTLEG].model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, runningMan[RUNNING::RUNNING_LEFTLEG].vertices.size());

	Set_LegTransform(runningMan[RUNNING::RUNNING_RIGHTLEG].model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, runningMan[RUNNING::RUNNING_RIGHTLEG].vertices.size());


	Set_ModelTransform(bench.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, bench.vertices.size());

	Set_ModelTransform(weights.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, weights.vertices.size());

	Set_ModelTransform(benchMan.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, benchMan.vertices.size());

	Set_ModelTransform(benchArm[0].model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, benchArm[0].vertices.size());

	Set_ModelTransform(benchArm[1].model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, benchArm[1].vertices.size());

	Set_ModelTransform(benchHand[0].model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, benchHand[0].vertices.size());

	Set_ModelTransform(benchHand[1].model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, benchHand[1].vertices.size());

	Set_ModelTransform(mid_cube.model_transform, modelLocation);
	glBindVertexArray(vao[vIndex++]);
	glDrawArrays(GL_TRIANGLES, 0, mid_cube.vertices.size());
}

void CShader_Func::Move_Camera(glm::vec3 _moveSize)
{
	Camera_Pos += _moveSize * 0.1f;
	m_Camera_Desc.cameraDirection += _moveSize * 0.1f;
}

void CShader_Func::Rotate_Camera(GLfloat _dir)
{
	m_Camera_Rotate_Angle += _dir;
}


void CShader_Func::Initialize_Shader()
{

	make_vertexShader();
	make_fragmentShader();



	Init_Objects();

}

void CShader_Func::make_vertexShader()
{
	vertexsource = filetobuf("vertex.glsl");
	//--- ���ؽ� ���̴� ��ü �����
	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
	//--- ���ؽ� ���̴� �������ϱ�
	glCompileShader(vertexshader);
	//--- �������� ����� ���� ���� ���: ���� üũ
	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(vertexshader, 512, NULL, errorLog);
		cerr << "ERROR: vertex shader ������ ����\n" << errorLog << endl;
		return;
	}
}

void CShader_Func::make_fragmentShader()
{
	fragmentsource = filetobuf("fragment.glsl");
	//--- �����׸�Ʈ ���̴� ��ü �����
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);
	//--- �����׸�Ʈ ���̴� ������
	glCompileShader(fragmentshader);
	//--- �������� ����� ���� ���� ���: ������ ���� üũ
	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(fragmentshader, 512, NULL, errorLog);
		cerr << "ERROR: fragment shader ������ ����\n" << errorLog << endl;
		return;
	}
}

void CShader_Func::Init_Objects()
{
	// �� ���� ���� ���� ����
	// 6���� �� �ٸ���

	// stage �ʱ�ȭ
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			stage.color[i * 6 + j] = glm::vec3(0.2f + 0.2f * (float)i, 0.2f + 0.2f * (float)i, 0.2f + 0.2f * (float)i);

		}
	}
	stage.model_transform.Scale = glm::vec3(8.f, 5.f, 8.f);


	// ������ �ʱ�ȭ
	leftArm.model_transform.Scale = glm::vec3(0.05f, 0.2f, 0.05f);
	leftArm.model_transform.Translate = glm::vec3(-0.22f, 0.f, 0.f);
	leftArm.model_transform.pivot = glm::vec3(0.f, 0.2f, 0.f);

	leftArm.model_transform.Rotate.x = 180.f;
	// ������
	rightArm.model_transform.Scale = glm::vec3(0.05f, 0.2f, 0.05f);
	rightArm.model_transform.Translate = glm::vec3(0.22f, 0.f, 0.f);
	rightArm.model_transform.pivot = glm::vec3(0.f, 0.2f, 0.f);
	rightArm.model_transform.Rotate.x = 180.f;
	// ����
	Body.model_transform.Scale = glm::vec3(0.4f, 0.3f, 0.2f);
	Body.model_transform.Translate = glm::vec3(0.0f, -4.2f, 5.0f);
	Body.model_transform.origin_Translate = glm::vec3(0.0f, -4.2f, 0.0f);
	// �Ӹ�
	Head.model_transform.Scale = glm::vec3(0.2f, 0.2f, 0.2f);
	Head.model_transform.Translate = glm::vec3(0.f, 0.25f, 0.0f);
	// �޴ٸ�
	leftLeg.model_transform.Scale = glm::vec3(0.05f, 0.3f, 0.05f);
	leftLeg.model_transform.Translate = glm::vec3(-0.1f, 0.f, 0.f);
	leftLeg.model_transform.pivot = glm::vec3(0.f, 0.5f, 0.f);
	leftLeg.model_transform.Rotate.x = 180.f;

	// �����ٸ�
	rightLeg.model_transform.Scale = glm::vec3(0.05f, 0.3f, 0.05f);
	rightLeg.model_transform.Translate = glm::vec3(0.1f, 0.f, 0.f);
	rightLeg.model_transform.pivot = glm::vec3(0.f, 0.5f, 0.f);

	rightLeg.model_transform.Rotate.x = 180.f;
	// ��
	Nose.model_transform.Scale = glm::vec3(0.05f, 0.05f, 0.05f);
	Nose.model_transform.Translate = glm::vec3(0.f, 0.25f, 0.1f);
	// ����� �θ� �������� ����
	leftArm.model_transform.Parent = &Body.model_transform;
	rightArm.model_transform.Parent = &Body.model_transform;
	Head.model_transform.Parent = &Body.model_transform;
	leftLeg.model_transform.Parent = &Body.model_transform;
	rightLeg.model_transform.Parent = &Body.model_transform;
	Nose.model_transform.Parent = &Body.model_transform;




	// ��ⱸ �ʱ�ȭ
	// ���׸ӽ�
	Init_Machines();

	for (int i = 0; i < object_number; ++i) {
		glGenVertexArrays(i, &vao[i]); //--- VAO �� �����ϰ� �Ҵ��ϱ�
		glGenBuffers(2, vbo[i]); //--- 2���� VBO�� �����ϰ� �Ҵ��ϱ�

	}
}

void CShader_Func::Init_Machines()
{

	// ���׸ӽ�
	running_machine.model_transform.Scale = glm::vec3(0.1f, 0.1f, 0.1f);
	running_machine.model_transform.Rotate = glm::vec3(0.f, 90.f, 0.f);

	running_machine.model_transform.Translate = glm::vec3(-6.f, -2.5f, 0.f);

	running_machine_rail.model_transform.Scale = glm::vec3(0.2f, 0.1f, 0.8f);
	running_machine_rail.model_transform.Translate = glm::vec3 (-5.5f, -5.5f, 5.f);
	running_machine_rail.model_transform.Rotate = glm::vec3(90.f, 0.f, 0.f);
	running_machine_rail.model_transform.Revolution = glm::vec3(0.f, 0.f, 0.f);


	// ����
	tree.branch.model_transform.Scale = glm::vec3(0.5f, 3.f, 0.5f);
	tree.branch.model_transform.Translate = glm::vec3(6.f, -4.f, 6.f);
	tree.Grass.model_transform.Scale = glm::vec3(0.1f, 0.1f, 0.1f);
	tree.Grass.model_transform.Translate = glm::vec3(6.f, -1.f, 6.f);

	// ö��
	pullbar.model_transform.Scale = glm::vec3(0.1f, 0.1f, 0.1f);
	pullbar.model_transform.Translate = glm::vec3(4.f, -3.f, 0.f);

	pullbarMan.model_transform.Scale = glm::vec3(0.1f, 0.1f, 0.1f);
	pullbarMan.model_transform.Translate = glm::vec3(4.f, -0.f, 3.f);
	pullbarMan.model_transform.Rotate = glm::vec3(0.f, 90.f, 0.f);
	pullbarMan.model_transform.pivot = glm::vec3(-1.f, -1.4f, -3.f);


	// ���׸�
	runningMan[RUNNING_BODY].model_transform.Scale = glm::vec3(0.1f, 0.6f, 0.4f);
	runningMan[RUNNING_BODY].model_transform.Translate = glm::vec3(-5.5f, -3.f, 6.f);

	runningMan[RUNNING_LEFTLEG].model_transform.Scale = glm::vec3(0.1f, 0.6f, 0.1f);
	runningMan[RUNNING_RIGHTLEG].model_transform.Scale = glm::vec3(0.1f, 0.6f, 0.1f);
	runningMan[RUNNING_LEFTLEG].model_transform.Translate = glm::vec3(-5.5f, -3.5f, 5.8f);
	runningMan[RUNNING_RIGHTLEG].model_transform.Translate = glm::vec3(-5.5f, -3.5f, 6.2f);

	runningMan[RUNNING_LEFTLEG].model_transform.pivot = glm::vec3(0.f, -0.5f, 0.f);
	runningMan[RUNNING_RIGHTLEG].model_transform.pivot = glm::vec3(0.f, -0.5f, 0.f);

	// ��ġ������

	bench.model_transform.Translate = glm::vec3(-6.f, -5.f, -4.f);
	bench.model_transform.Scale = glm::vec3(0.15f, 0.15f, 0.15f);

	weights.model_transform.Translate = glm::vec3(-6.f, -2.9f, -4.5f);
	weights.model_transform.Scale = glm::vec3(0.18f, 0.1f, 0.15f);

	benchMan.model_transform.Translate = glm::vec3(-6.f, -4.4f, -4.8f);
	benchMan.model_transform.Scale = glm::vec3(0.2f, 0.2f, 0.4f);

	benchArm[0].model_transform.Translate = glm::vec3(-6.5f, -3.9f, -4.5f);
	benchArm[0].model_transform.Rotate = glm::vec3(0.f, 0.f, 20.f);
	benchArm[0].model_transform.Scale = glm::vec3(0.1f, 0.4f, 0.1f);

	benchArm[1].model_transform.Translate = glm::vec3(-5.5f, -3.9f, -4.5f);
	benchArm[1].model_transform.Rotate = glm::vec3(0.f, 0.f, -20.f);

	benchArm[1].model_transform.Scale = glm::vec3(0.1f, 0.4f, 0.1f);

	benchHand[0].model_transform.Translate = glm::vec3(-6.5f, -3.4f, -4.5f);
	benchHand[0].model_transform.Scale = glm::vec3(0.1f, 0.4f, 0.1f);
	benchHand[0].model_transform.Rotate = glm::vec3(0.f, 0.f, -20.f);

	benchHand[1].model_transform.Translate = glm::vec3(-5.5f, -3.4f, -4.5f);
	benchHand[1].model_transform.Scale = glm::vec3(0.1f, 0.4f, 0.1f);
	benchHand[1].model_transform.Rotate = glm::vec3(0.f, 0.f, 20.f);

	// �߰� ť��
	mid_cube.model_transform.Translate.y = -4.f;
}

void CShader_Func::Update()
{
	if (!bGenerate) {
		
		bGenerate = true;
	}

	int vIndex = 0;


	Update_Buffer(vIndex++, stage.vertices, stage.color);
	Update_Buffer(vIndex++, leftArm.vertices, leftArm.color);
	Update_Buffer(vIndex++, rightArm.vertices, rightArm.color);
	Update_Buffer(vIndex++, Body.vertices, Body.color);
	Update_Buffer(vIndex++, leftLeg.vertices, leftLeg.color);
	Update_Buffer(vIndex++, rightLeg.vertices, rightLeg.color);
	Update_Buffer(vIndex++, Head.vertices, Head.color);
	Update_Buffer(vIndex++, Nose.vertices, Nose.color);




	//19��
	Update_Buffer(vIndex++, running_machine.vertices, running_machine.color);
	Update_Buffer(vIndex++, running_machine_rail.vertices, running_machine_rail.color);
	Update_Buffer(vIndex++, tree.branch.vertices, tree.branch.color);
	Update_Buffer(vIndex++, tree.Grass.vertices, tree.Grass.color);
	Update_Buffer(vIndex++, pullbar.vertices, pullbar.color);
	Update_Buffer(vIndex++, pullbarMan.vertices, pullbarMan.color);
	for (int i = 0; i < RUNNING_END; ++i) {
		Update_Buffer(vIndex++, runningMan[i].vertices, runningMan[i].color);
	}
	Update_Buffer(vIndex++, bench.vertices, bench.color);
	Update_Buffer(vIndex++, weights.vertices, weights.color);
	Update_Buffer(vIndex++, benchMan.vertices, benchMan.color);
	Update_Buffer(vIndex++, benchArm[0].vertices, benchArm[0].color);
	Update_Buffer(vIndex++, benchArm[1].vertices, benchArm[1].color);
	Update_Buffer(vIndex++, benchHand[0].vertices, benchHand[0].color);
	Update_Buffer(vIndex++, benchHand[1].vertices, benchHand[1].color);


	Update_Buffer(vIndex++, mid_cube.vertices, mid_cube.color);
	

	Update_Shader();

	
	
}

void CShader_Func::Update_Buffer(int _vindex, glm::vec3 Shape_pos[], glm::vec3 shape_color[], size_t _size)
{
	
	//--- VAO ��ü ���� �� ���ε�
	glBindVertexArray(vao[_vindex]); //--- VAO�� ���ε��ϱ�

	//--- vertex data ������ ���� VBO ���� �� ���ε�
	//--- 1��° VBO�� Ȱ��ȭ�Ͽ� ���ε��ϰ�, ���ؽ� �Ӽ� (��ǥ��)�� ����
	glBindBuffer(GL_ARRAY_BUFFER, vbo[_vindex][0]);
	// ���� triShape ���� ���ؽ� ������ ���� ���ۿ� �����Ѵ�.

	// triShape �迭�� ������: 9 * float
	glBufferData(GL_ARRAY_BUFFER, _size, Shape_pos, GL_STATIC_DRAW);

	//--- ���� �Ӽ�
	// ��ǥ���� attribute �ε��� 0���� ����Ѵ�: ���ؽ� �� 3* float
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// attribute �ε��� 0���� ��밡���ϰ� ��
	glEnableVertexAttribArray(0);
	//--- 2��° VBO�� Ȱ��ȭ �Ͽ� ���ε� �ϰ�, ���ؽ� �Ӽ� (����)�� ����
	glBindBuffer(GL_ARRAY_BUFFER, vbo[_vindex][1]);
	// ���� colors���� ���ؽ� ������ �����Ѵ�.
	// colors �迭�� ������: 9 *float 
	glBufferData(GL_ARRAY_BUFFER, _size, shape_color, GL_STATIC_DRAW);
	// ������ attribute �ε��� 1���� ����Ѵ�: ���ؽ� �� 3*float
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// attribute �ε��� 1���� ��� �����ϰ� ��.
	glEnableVertexAttribArray(1);
}

void CShader_Func::Update_Buffer(int _vindex, vector<glm::vec3> _vertices, vector<glm::vec3> _color)
{
	//--- VAO ��ü ���� �� ���ε�
	glBindVertexArray(vao[_vindex]); //--- VAO�� ���ε��ϱ�

	//--- vertex data ������ ���� VBO ���� �� ���ε�
	//--- 1��° VBO�� Ȱ��ȭ�Ͽ� ���ε��ϰ�, ���ؽ� �Ӽ� (��ǥ��)�� ����
	glBindBuffer(GL_ARRAY_BUFFER, vbo[_vindex][0]);
	// ���� triShape ���� ���ؽ� ������ ���� ���ۿ� �����Ѵ�.

	// triShape �迭�� ������: 9 * float
	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(glm::vec3), &_vertices[0], GL_STATIC_DRAW);

	//--- ���� �Ӽ�
	// ��ǥ���� attribute �ε��� 0���� ����Ѵ�: ���ؽ� �� 3* float
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// attribute �ε��� 0���� ��밡���ϰ� ��
	glEnableVertexAttribArray(0);
	//--- 2��° VBO�� Ȱ��ȭ �Ͽ� ���ε� �ϰ�, ���ؽ� �Ӽ� (����)�� ����
	glBindBuffer(GL_ARRAY_BUFFER, vbo[_vindex][1]);
	// ���� colors���� ���ؽ� ������ �����Ѵ�.
	// colors �迭�� ������: 9 *float 
	glBufferData(GL_ARRAY_BUFFER, _color.size() * sizeof(glm::vec3), &_color[0], GL_STATIC_DRAW);
	// ������ attribute �ε��� 1���� ����Ѵ�: ���ؽ� �� 3*float
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// attribute �ε��� 1���� ��� �����ϰ� ��.
	glEnableVertexAttribArray(1);
}

void CShader_Func::Update_Shader()
{
	//make_vertexShader(i);
		//make_fragmentShader(i);
	s_program = glCreateProgram();
	glAttachShader(s_program, vertexshader);
	glAttachShader(s_program, fragmentshader);
	glLinkProgram(s_program);

	GLint result;
	GLchar errorLog[512];

	glGetProgramiv(s_program, GL_LINK_STATUS, &result); // ---���̴��� �� ����Ǿ����� üũ�ϱ�
	if (!result) {
		glGetProgramInfoLog(s_program, 512, NULL, errorLog);
		cerr << "ERROR: shader program ���� ����\n" << errorLog << endl;
		return;
	}
	//--- ���̴� �����ϱ�
	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);
	//--- Shader Program ����ϱ�
	glUseProgram(s_program);
}


void CShader_Func::Set_ModelTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation)
{
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

	Scale = glm::scale(Scale, _modelTransform.Scale);

	RotateX = glm::rotate(RotateX, glm::radians(_modelTransform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(_modelTransform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(_modelTransform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, _modelTransform.Translate);

	RevolutionX = glm::rotate(RevolutionX, glm::radians(_modelTransform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(_modelTransform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(_modelTransform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if(_modelTransform.Parent)
		Parent = glm::translate(Parent, _modelTransform.Parent->Translate);

	// ũ �� �� �� �� �Ųٷ�
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateX * RotateY * RotateZ * Scale;


	glUniformMatrix4fv(_modelLocation, 1, GL_FALSE, glm::value_ptr(Result));
}

void CShader_Func::Set_ModelTransform_Parent(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation)
{
	// �θ��� �̵�, ���� ����� �θ�� �д�.
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

	Scale = glm::scale(Scale, _modelTransform.Scale);

	RotateX = glm::rotate(RotateX, glm::radians(_modelTransform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(_modelTransform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(_modelTransform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, _modelTransform.Translate);

	RevolutionX = glm::rotate(RevolutionX, glm::radians(_modelTransform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(_modelTransform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(_modelTransform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if (_modelTransform.Parent) {
		Parent = glm::translate(Parent, _modelTransform.Parent->Translate);
		//Parent = glm::rotate(Parent, glm::radians(_modelTransform.Parent->Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	}

	// ũ �� �� �� �� �Ųٷ�
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateX * RotateY * RotateZ * Scale;


	glUniformMatrix4fv(_modelLocation, 1, GL_FALSE, glm::value_ptr(Result));
}

void CShader_Func::Set_ArmModelTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation)
{
	glm::mat4 Scale = glm::mat4(1.f);

	glm::mat4 RotateX = glm::mat4(1.f);
	glm::mat4 RotateY = glm::mat4(1.f);
	glm::mat4 RotateZ = glm::mat4(1.f);

	glm::mat4 Translate = glm::mat4(1.f);
	glm::mat4 PivotTranslate = glm::mat4(1.f);
	glm::mat4 RevolutionX = glm::mat4(1.f);
	glm::mat4 RevolutionY = glm::mat4(1.f);
	glm::mat4 RevolutionZ = glm::mat4(1.f);

	glm::mat4 Parent = glm::mat4(1.f);

	glm::mat4 Result = glm::mat4(1.f);

	Scale = glm::scale(Scale, _modelTransform.Scale);

	RotateX = glm::rotate(RotateX, glm::radians(_modelTransform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(_modelTransform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(_modelTransform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, _modelTransform.Translate);
	PivotTranslate = glm::translate(Translate, _modelTransform.pivot);
	RevolutionX = glm::rotate(RevolutionX, glm::radians(_modelTransform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(_modelTransform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(_modelTransform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if (_modelTransform.Parent) {
		Parent = glm::translate(Parent, _modelTransform.Parent->Translate);
	}

	// ũ �� �� �� �� �Ųٷ�
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateX * RotateY * RotateZ * PivotTranslate * Scale;


	glUniformMatrix4fv(_modelLocation, 1, GL_FALSE, glm::value_ptr(Result));
}

void CShader_Func::Set_ModelTransform_pullbarMan(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation)
{
	glm::mat4 Scale = glm::mat4(1.f);

	glm::mat4 RotateX = glm::mat4(1.f);
	glm::mat4 RotateY = glm::mat4(1.f);
	glm::mat4 RotateZ = glm::mat4(1.f);

	glm::mat4 Translate = glm::mat4(1.f);
	glm::mat4 PivotTranslate = glm::mat4(1.f);
	glm::mat4 RevolutionX = glm::mat4(1.f);
	glm::mat4 RevolutionY = glm::mat4(1.f);
	glm::mat4 RevolutionZ = glm::mat4(1.f);

	glm::mat4 Parent = glm::mat4(1.f);

	glm::mat4 Result = glm::mat4(1.f);

	Scale = glm::scale(Scale, _modelTransform.Scale);

	RotateX = glm::rotate(RotateX, glm::radians(_modelTransform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(_modelTransform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(_modelTransform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, _modelTransform.Translate);
	PivotTranslate = glm::translate(Translate, _modelTransform.pivot);
	RevolutionX = glm::rotate(RevolutionX, glm::radians(_modelTransform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(_modelTransform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(_modelTransform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if (_modelTransform.Parent) {
		Parent = glm::translate(Parent, _modelTransform.Parent->Translate);
		Parent = glm::rotate(Parent, glm::radians(_modelTransform.Parent->Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	}

	// ũ �� �� �� �� �Ųٷ�
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateZ * RotateY * RotateX * PivotTranslate * Scale;


	glUniformMatrix4fv(_modelLocation, 1, GL_FALSE, glm::value_ptr(Result));
}

void CShader_Func::Set_LegTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation)
{
	glm::mat4 Scale = glm::mat4(1.f);

	glm::mat4 RotateX = glm::mat4(1.f);
	glm::mat4 RotateY = glm::mat4(1.f);
	glm::mat4 RotateZ = glm::mat4(1.f);

	glm::mat4 Translate = glm::mat4(1.f);
	glm::mat4 PivotTranslate = glm::mat4(1.f);

	glm::mat4 RevolutionX = glm::mat4(1.f);
	glm::mat4 RevolutionY = glm::mat4(1.f);
	glm::mat4 RevolutionZ = glm::mat4(1.f);

	glm::mat4 Parent = glm::mat4(1.f);

	glm::mat4 Result = glm::mat4(1.f);

	Scale = glm::scale(Scale, _modelTransform.Scale);
	PivotTranslate = glm::translate(Translate, _modelTransform.pivot);

	RotateX = glm::rotate(RotateX, glm::radians(_modelTransform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(_modelTransform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(_modelTransform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, _modelTransform.Translate);

	RevolutionX = glm::rotate(RevolutionX, glm::radians(_modelTransform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(_modelTransform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(_modelTransform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if (_modelTransform.Parent)
		Parent = glm::translate(Parent, _modelTransform.Parent->Translate);

	// ũ �� �� �� �� �Ųٷ�
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateX * RotateY * RotateZ * PivotTranslate * Scale;


	glUniformMatrix4fv(_modelLocation, 1, GL_FALSE, glm::value_ptr(Result));
}

void CShader_Func::Set_RailTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation)
{
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

	Scale = glm::scale(Scale, _modelTransform.Scale);

	RotateX = glm::rotate(RotateX, glm::radians(_modelTransform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(_modelTransform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(_modelTransform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, _modelTransform.Translate);

	RevolutionX = glm::rotate(RevolutionX, glm::radians(_modelTransform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(_modelTransform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(_modelTransform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if (_modelTransform.Parent)
		Parent = glm::translate(Parent, _modelTransform.Parent->Translate);

	// ũ �� �� �� �� �Ųٷ�
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateZ * RotateY * RotateX * Scale;


	glUniformMatrix4fv(_modelLocation, 1, GL_FALSE, glm::value_ptr(Result));
}

void CShader_Func::Set_PlayerTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation)
{
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

	Scale = glm::scale(Scale, _modelTransform.Scale);

	RotateX = glm::rotate(RotateX, glm::radians(_modelTransform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(_modelTransform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(_modelTransform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, _modelTransform.Translate);

	RevolutionX = glm::rotate(RevolutionX, glm::radians(_modelTransform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(_modelTransform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(_modelTransform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if (_modelTransform.Parent)
		Parent = glm::translate(Parent, _modelTransform.Parent->Translate);

	// ũ �� �� �� �� �Ųٷ�
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateX * RotateY * RotateZ * Scale;


	glUniformMatrix4fv(_modelLocation, 1, GL_FALSE, glm::value_ptr(Result));
}

void CShader_Func::Set_PlayerArmTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation)
{
	glm::mat4 Scale = glm::mat4(1.f);

	glm::mat4 RotateX = glm::mat4(1.f);
	glm::mat4 RotateY = glm::mat4(1.f);
	glm::mat4 RotateZ = glm::mat4(1.f);

	glm::mat4 Translate = glm::mat4(1.f);
	glm::mat4 PivotTranslate = glm::mat4(1.f);
	glm::mat4 RevolutionX = glm::mat4(1.f);
	glm::mat4 RevolutionY = glm::mat4(1.f);
	glm::mat4 RevolutionZ = glm::mat4(1.f);

	glm::mat4 Parent = glm::mat4(1.f);

	glm::mat4 Result = glm::mat4(1.f);

	Scale = glm::scale(Scale, _modelTransform.Scale);

	RotateX = glm::rotate(RotateX, glm::radians(_modelTransform.Rotate.x), glm::vec3(1.0, 0.0, 0.0));
	RotateY = glm::rotate(RotateY, glm::radians(_modelTransform.Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	RotateZ = glm::rotate(RotateZ, glm::radians(_modelTransform.Rotate.z), glm::vec3(0.0, 0.0, 1.0));

	Translate = glm::translate(Translate, _modelTransform.Translate);
	PivotTranslate = glm::translate(Translate, _modelTransform.pivot);
	RevolutionX = glm::rotate(RevolutionX, glm::radians(_modelTransform.Revolution.x), glm::vec3(1.0, 0.0, 0.0));
	RevolutionY = glm::rotate(RevolutionY, glm::radians(_modelTransform.Revolution.y), glm::vec3(0.0, 1.0, 0.0));
	RevolutionZ = glm::rotate(RevolutionZ, glm::radians(_modelTransform.Revolution.z), glm::vec3(0.0, 0.0, 1.0));
	if (_modelTransform.Parent) {
		Parent = glm::translate(Parent, _modelTransform.Parent->Translate);
		Parent = glm::rotate(Parent, glm::radians(_modelTransform.Parent->Rotate.y), glm::vec3(0.0, 1.0, 0.0));
	}

	// ũ �� �� �� �� �Ųٷ�
	Result = Parent * RevolutionX * RevolutionY * RevolutionZ * Translate * RotateX * RotateY * RotateZ * PivotTranslate * Scale;


	glUniformMatrix4fv(_modelLocation, 1, GL_FALSE, glm::value_ptr(Result));
}



GLboolean CShader_Func::Open_Stage()
{
	for (int i = 12; i < 18; ++i) {
		if (m_YMove_Cnt >= 2.f)
			return false;
		stage.vertices[i].y += 0.01f;
	}
	m_YMove_Cnt += 0.01f;
	return true;
}

void CShader_Func::Walk_Player(glm::vec3 _moveSize, PLAYER::DIR _dir)
{
	Body.model_transform.Translate += _moveSize * 0.1f;
	
	switch (_dir)
	{
	case PLAYER::FRONT:
		Body.model_transform.Rotate.y = 0.f;
		break;
	case PLAYER::BACK:
		Body.model_transform.Rotate.y = 180.f;
		break;
	case PLAYER::LEFT:
		Body.model_transform.Rotate.y = -90.f;
		break;
	case PLAYER::RIGHT:
		Body.model_transform.Rotate.y = 90.f;
		break;
	default:
		break;
	}
}

void CShader_Func::Rotate_Arms()
{
	if (bRotate_Dir) {
		leftArm.model_transform.Rotate.x += 2.f;
		rightArm.model_transform.Rotate.x -= 2.f;
		// �ٸ��� ���� �ݴ�� ������
		rightLeg.model_transform.Rotate.x += 2.f;
		leftLeg.model_transform.Rotate.x -= 2.f;
	}
	else {
		leftArm.model_transform.Rotate.x -= 2.f;
		rightArm.model_transform.Rotate.x += 2.f;

		// �ٸ��� ���� �ݴ�� ������
		rightLeg.model_transform.Rotate.x -= 2.f;
		leftLeg.model_transform.Rotate.x += 2.f;
	}
	if (leftArm.model_transform.Rotate.x >= 180.f + 45.f && bRotate_Dir) {
		leftArm.model_transform.Rotate.x = 180.f + 45.f;
		rightArm.model_transform.Rotate.x = 180.f - 45.f;
		// �ٸ��� ���� �ݴ�� ������
		rightLeg.model_transform.Rotate.x = 180.f + 45.f;
		leftLeg.model_transform.Rotate.x = 180.f - 45.f;

		bRotate_Dir = false;
	}
	if (leftArm.model_transform.Rotate.x <= 180.f - 45.f && !bRotate_Dir) {
		leftArm.model_transform.Rotate.x = 180.f - 45.f;
		rightArm.model_transform.Rotate.x = 180.f + 45.f;

		// �ٸ��� ���� �ݴ�� ������
		rightLeg.model_transform.Rotate.x = 180.f - 45.f;
		leftLeg.model_transform.Rotate.x = 180.f + 45.f;

		bRotate_Dir = true;
	}
}

GLboolean CShader_Func::Jump()
{
	if (bJumpUp) {
		Body.model_transform.Translate.y += 0.1f;
		if (Body.model_transform.Translate.y >= Body.model_transform.origin_Translate.y + 1.f) {
			bJumpUp = false;
		}
	}
	else {
		// �ٿ��ε� �̶� �ٴں��� �۾����� ���߰� false ��ȯ
		Body.model_transform.Translate.y -= 0.1f;
		if (Body.model_transform.Translate.y <= Body.model_transform.origin_Translate.y) {
			Body.model_transform.Translate.y = Body.model_transform.origin_Translate.y;
			bJumpUp = true;
			return false;
		}
	}
	return true;
}

void CShader_Func::Reset_All()
{
	Init_Objects();
	Body.model_transform.Rotate.y = 0.f;
	for (int i = 12; i < 18; ++i) {

		stage.vertices[i].y -= 2.f;
	}
	m_YMove_Cnt = 0.f;
}

void CShader_Func::Collision_Check()
{
	//  ���� �κ��� �߰� ������ ���� z�� x ��ǥ ����
	if (Body.model_transform.Translate.x >= -1.f && Body.model_transform.Translate.x <= 1.f
		&& Body.model_transform.Translate.z >= -1.f && Body.model_transform.Translate.z <= 1.f) {
		if (_nowDir == PLAYER::LEFT || _nowDir == PLAYER::RIGHT) {
			if (Body.model_transform.Translate.x <= 0.f) {
				Body.model_transform.Translate.x = -1.1f;
			}
			else {
				Body.model_transform.Translate.x = 1.1f;

			}
		}
		else {
			if (Body.model_transform.Translate.z <= 0.f) {
				Body.model_transform.Translate.z = -1.1f;
			}
			else {
				Body.model_transform.Translate.z = 1.1f;

			}
		}
	}
}

void CShader_Func::Upate_Machines()
{
	Collision_Check();
	// ���� �ӽ� ���� ������
	running_machine_rail.model_transform.Rotate.z -= 1.f;

	// ����
	if (tree.Grass.model_transform.Scale.x >= 0.25f && tree_Size) {
		tree_Size = false;
	}
	else if (tree.Grass.model_transform.Scale.x <= 0.05f && !tree_Size) {
		tree_Size = true;

	}

	if(tree_Size)
		tree.Grass.model_transform.Scale += 0.002f;
	else
		tree.Grass.model_transform.Scale -= 0.002f;

	pullbarMan.model_transform.Rotate.z += 1.f;

	if (runningMan[RUNNING_LEFTLEG].model_transform.Rotate.z >= 20.f && running_Size) {
		running_Size = false;
	}
	else if (runningMan[RUNNING_LEFTLEG].model_transform.Rotate.z <= -20.f && !running_Size) {
		running_Size = true;
	}
	if (running_Size) {
		runningMan[RUNNING_LEFTLEG].model_transform.Rotate.z += 0.5f;
		runningMan[RUNNING_RIGHTLEG].model_transform.Rotate.z -= 0.5f;
	}
	else {
		runningMan[RUNNING_LEFTLEG].model_transform.Rotate.z -= 0.5f;
		runningMan[RUNNING_RIGHTLEG].model_transform.Rotate.z += 0.5f;
	}
	if (benchArm[0].model_transform.Rotate.z >= 50.f && press_size)
		press_size = false;
	else if (benchArm[0].model_transform.Rotate.z <= 10.f && !press_size)
		press_size = true;

	if (press_size) {
		weights.model_transform.Translate.y -= 0.01f;
		benchArm[0].model_transform.Rotate.z += 1.f;
		benchArm[1].model_transform.Rotate.z -= 1.f;
		benchHand[0].model_transform.Rotate.z -= 1.f;
		benchHand[1].model_transform.Rotate.z += 1.f;
	}
	else {
		weights.model_transform.Translate.y += 0.01f;
		benchArm[0].model_transform.Rotate.z -= 1.f;
		benchArm[1].model_transform.Rotate.z += 1.f;
		benchHand[0].model_transform.Rotate.z += 1.f;
		benchHand[1].model_transform.Rotate.z -= 1.f;
	}

}

