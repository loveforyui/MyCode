#include "stdafx.h"
#include "LineMgr.h"
#include "Line.h"
#include "Mline.h"

IMPLEMENT_SINGLETON(CLineMgr)

CLineMgr::CLineMgr()
{
}

CLineMgr::~CLineMgr()
{
	Release();
}

// 플레이어의 x을 받은 뒤 pOutY에다가 플레이어가 타야할 y를 기록한다.
bool CLineMgr:: CollisionLine       (float fX, float * pOutY)
{
	if (m_LineList.empty())
		return false;

	CLine* pLine = nullptr; // 플레이어가 타야할 라인.

	// 플레이어가 위치한 x좌표를 통해 현재 라인을 찾는다.
	for (auto line : m_LineList)
	{
		float fLposX = line->GetInfo().tLPoint.fX;
		float fRposX = line->GetInfo().tRPoint.fX;

		if (fX > fLposX && fX < fRposX)
		{
			pLine = line;
			break;
		}
	}

	if (nullptr == pLine)
		return false;

	// 두점을 통과하는 직선의 방정식을 이용하여 플레이어의 Y를 도출한다!
	// playerY = (y2 - y1) / (x2 - x1) * (playerX - x1) + y1
	float x1 = pLine->GetInfo().tLPoint.fX;
	float y1 = pLine->GetInfo().tLPoint.fY;
	float x2 = pLine->GetInfo().tRPoint.fX;
	float y2 = pLine->GetInfo().tRPoint.fY;

	*pOutY = (y2 - y1) / (x2 - x1) * (fX - x1) + y1;
	return true;
}

void CLineMgr:: LoadData            ()
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

    hFile = CreateFile(L"../Data/MLine.dat", GENERIC_READ, 0, 0
		, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/MLine.dat", L"Load failed!!!", MB_OK);
		return;
	}

    LINEINFO tInfos;
	dwBytes = 0;

    while (true)
	{
		ReadFile(hFile, &tInfos, sizeof(LINEINFO), &dwBytes, nullptr);

		if (0 == dwBytes)
			break;

		m_MlineList.push_back(new MCLine(tInfos));
	}

    CloseHandle(hFile);
}

void CLineMgr:: SaveData            ()
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

    hFile = CreateFile(L"../Data/MLine.dat", GENERIC_WRITE, 0, 0
		, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

    if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"../Data/MLine.dat", L"Save failed!!", MB_OK);
		return;
	}

    dwBytes = 0;

    for (auto pMine : m_MlineList)
	{
		// WriteFile: API의 파일 출력 함수.
		WriteFile(hFile, &(pMine->GetInfo()), sizeof(LINEINFO), &dwBytes, nullptr);
	}

    CloseHandle(hFile);
}

void CLineMgr:: Initialize          ()
{
	LoadData();
}

void CLineMgr:: Render              (HDC hDC)
{
	for (auto line : m_LineList)
		line->Render(hDC);
    for (auto line : m_MlineList)
		line->Render(hDC);
}

void CLineMgr:: Release             ()
{
	for_each(m_LineList.begin(), m_LineList.end(), SafeDelete<CLine*>);
	m_LineList.clear();
}
