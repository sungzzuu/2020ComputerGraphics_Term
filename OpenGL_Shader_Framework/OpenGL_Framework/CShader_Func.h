#pragma once
namespace PLAYER
{
	enum BODY { UNDER, CENTER, LEFT_ARM, RIGHT_ARM, BODY_END };
	enum DIR {FRONT, BACK, LEFT, RIGHT};
}
struct Tree {
	OBJECT branch;
	OBJECT Grass;
};
struct Running_Machine {
	OBJECT bottom;
	OBJECT left_Side;
	OBJECT right_Side;
	OBJECT top;
	//OBJECT 
};
enum RUNNING { RUNNING_BODY, RUNNING_LEFTLEG, RUNNING_RIGHTLEG, RUNNING_END };

class CShader_Func
{
public:
	CShader_Func();
	~CShader_Func();

public:
	
	// 1. drawScene�Լ����� �׸��� for������
	// 2. make_vertexShader()
	// 3. make_fragmentShader()
	// 4. InitBuffer()
	// 5. InitShader()

	// �ʱ�ȭ
	void Initialize_Shader();
	void make_vertexShader();
	void make_fragmentShader();
	void Init_Objects();
	void Init_Machines();

	// ������Ʈ
	void Update();
	void Update_Buffer(int _vindex, glm::vec3 Shape_pos[], glm::vec3 shape_color[], size_t _size);
	void Update_Buffer(int _vindex, vector<glm::vec3> _vertices, vector<glm::vec3> _color);
	void Update_Shader();
	void Call_Vao();

	// ī�޶� �̵� �Լ�
	void Move_Camera(glm::vec3 _moveSize);
	void Rotate_Camera(GLfloat _dir);
	// �𵨺�ȯ ����
	void Set_ModelTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation);
	void Set_ModelTransform_Parent(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation);
	void Set_ArmModelTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation);
	void Set_ModelTransform_pullbarMan(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation);
	void Set_LegTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation);
	void Set_RailTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation);
	void Set_PlayerTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation);
	void Set_PlayerArmTransform(MODEL_TRANSFORM _modelTransform, unsigned int _modelLocation);



	// 18�� �Լ�
	GLboolean Open_Stage();
	void Walk_Player(glm::vec3 _moveSize, PLAYER::DIR _dir);
	// �κ� �Լ�
	void Rotate_Arms();
	GLboolean Jump();
	// ��� ��ȯ ����
	void Reset_All();
	void Collision_Check();

	// 19�� �Լ�
	void Upate_Machines();
	void Set_nowDir(PLAYER::DIR _eDir) { _nowDir = _eDir; }
private:
	GLchar* vertexsource, * fragmentsource; // �ҽ��ڵ� ���� ����
	GLuint vertexshader, fragmentshader; // ���̴� ��ü
	GLuint s_program;
	//TRIANGLE triShape[TRINUM];
	//CUBE cubeShape[CUBENUM];
	//LINE lineShape[LINENUM];
	GLuint vao[100], vbo[100][2];
	GLenum ePolygonMode = GL_FILL;
	CAMERA_DESC m_Camera_Desc;
	GLfloat m_Camera_Rotate_Angle = 0.f;
	glm::vec3 Camera_Pos{ 0.f, 3.f, 25.f };

	GLboolean bGenerate = false;
	// obj �ҷ�����
	// ���⿡ �ִ´�.
	// �� ��ü�� ��ǥ�� �ִ�.
	OBJECT stage;
	OBJECT stage_front;
	GLfloat m_YMove_Cnt = 0.f;
	
	// �κ� �����

	//Test ��ȸ�� ��Ű�� �� �߽��� ������ �ΰ� �غ���
	OBJECT leftArm, rightArm;
	OBJECT leftLeg, rightLeg;
	OBJECT Body, Head, Nose;

	// arm
	GLboolean bRotate_Dir = true;

	// jump
	GLboolean bJumpUp = true;

	// ���׸ӽ�
	OBJECT running_machine;
	OBJECT running_machine_rail;

	// ����
	Tree tree;
	GLboolean tree_Size = true;

	// ö��
	OBJECT pullbar;
	OBJECT pullbarMan;

	// ���׿��� �޸��� ��
	OBJECT runningMan[RUNNING_END];
	GLboolean running_Size = true;

	// ��ġ������
	OBJECT bench;
	OBJECT weights;
	OBJECT benchMan;
	OBJECT benchArm[2];
	OBJECT benchHand[2];

	GLboolean press_size = true;

	// �߰� �浹ü
	OBJECT mid_cube;

	PLAYER::DIR _nowDir;

	GLuint object_number = 0;
};

