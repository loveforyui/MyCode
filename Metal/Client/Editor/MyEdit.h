#pragma once

class CMyEdit
{
public:
	CMyEdit();
	~CMyEdit();

public:
	void Initialize();
	void Update();
	void Render(HDC hDC);
	void Release();

private:
    LINEINFO tInfo;
    BOOL isClick = false;

    INT m_iMode;
};

