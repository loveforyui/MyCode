#include "stdafx.h"
#include "LineMgr.h"
#include "Line.h"

IMPLEMENT_SINGLETON(CLineMgr)

CLineMgr::CLineMgr()
{
}


CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::SaveData()
{
	// Win32 API 기반의 파일 입출력
	HANDLE hFile = CreateFile(L"../Data/Line.dat", GENERIC_WRITE, 0, 0
		, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/Line.dat", L"Save failed!!", MB_OK);
		return;
	}

	DWORD dwBytes = 0;

	for (auto pLine : m_LineList)
	{
		// WriteFile: API의 파일 출력 함수.
		WriteFile(hFile, &(pLine->GetInfo()), sizeof(LINEINFO), &dwBytes, nullptr);
	}

	CloseHandle(hFile);
}

void CLineMgr::LoadData()
{
	HANDLE hFile = CreateFile(L"../Data/Line.dat", GENERIC_READ, 0, 0
		, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/Line.dat", L"Load failed!!!", MB_OK);
		return;
	}

	LINEINFO tInfo;
	DWORD dwBytes = 0;

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(LINEINFO), &dwBytes, nullptr);

		if (0 == dwBytes)
			break;

		m_LineList.push_back(new CLine(tInfo));
	}

	CloseHandle(hFile);
}

void CLineMgr::Rewind()
{
    list<CLine*>::iterator iter = --(m_LineList.end());

    delete *iter;
    m_LineList.erase(iter);
}

void CLineMgr::Initialize()
{
	/*LINEPOINT tPosArr[4] = { {100.f, 500.f}, {300.f, 500.f}, {500.f, 300.f}, {700.f, 300.f} };

	m_LineList.push_back(new CLine(LINEINFO(tPosArr[0], tPosArr[1])));
	m_LineList.push_back(new CLine(LINEINFO(tPosArr[1], tPosArr[2])));
	m_LineList.push_back(new CLine(LINEINFO(tPosArr[2], tPosArr[3])));*/
}

void CLineMgr::Render(HDC hDC)
{
	for (auto line : m_LineList)
		line->Render(hDC);
}

void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), SafeDelete<CLine*>);
	m_LineList.clear();
}
