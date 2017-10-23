#pragma once

class CLine;
class CLineMgr
{
	DECLARE_SINGLETON(CLineMgr)
private:
	CLineMgr();
	~CLineMgr();

public:
	list<CLine*>& GetLineList() { return m_LineList; }

public:
	void SaveData();
    	void LoadData();

public:
    	void Rewind();
	
public:
	void Initialize();
	void Render(HDC hDC);
	void Release();

private:
	list<CLine*>	m_LineList;
};

