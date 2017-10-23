#pragma once
class CLine
{
public:
	CLine();
	CLine(LINEINFO& rInfo);
	~CLine();

public:
	const LINEINFO& GetInfo() const { return m_tInfo; }

public:
	void SetRPoint(LINEPOINT& RPoint) { m_tInfo.tRPoint = RPoint; }

public:
	void Render(HDC hDC);

private:
	LINEINFO m_tInfo;
};

