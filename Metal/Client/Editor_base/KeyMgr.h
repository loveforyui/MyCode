#pragma once

// �̱��� ����: �������� �ʿ��� ��ü�� �ϳ��� �Ҵ��Ͽ� �������� ����ϰԲ� ���ִ� ������ ����
// ����ȭ�� �ı��ϴ� ������ ���������� ���� ���������� �ʼ��̴�.
#define MAX_VIRTUAL_KEY 0xFF

class CKeyMgr
{
	DECLARE_SINGLETON(CKeyMgr)
private: // �̱��� ��ü�� �����ڿ� �Ҹ��ڴ� private�� ������ �д�.
	CKeyMgr();	
	~CKeyMgr();

public:
	bool GetKeyPressing(int iKey);
	bool GetKeyDown(int iKey);
	bool GetKeyUp(int iKey);	

public:
	// Update�Լ��� GetKeyPressing, GetKeyDown, GetKeyUp ���� ȣ���� �Ŀ� ȣ�����ִ� �Լ�.
	void Update();	

private:
	bool m_bKey[MAX_VIRTUAL_KEY];
};

#define KEY_DOWN(Key) CKeyMgr::GetInstance()->GetKeyDown(Key)
#define KEY_UP(Key) CKeyMgr::GetInstance()->GetKeyUp(Key)
#define KEY_PRESSING(Key) CKeyMgr::GetInstance()->GetKeyPressing(Key)