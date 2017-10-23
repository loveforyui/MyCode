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
};

