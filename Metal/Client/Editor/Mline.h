#pragma once
class MCLine
{
public:
    MCLine();
    MCLine(LINEINFO& rInfo);
    ~MCLine();

public:
    const LINEINFO& GetInfo() const { return m_tInfo; }

public:
    void SetRPoint(LINEPOINT& RPoint) { m_tInfo.tRPoint = RPoint; }

public:
	void Render(HDC hDC);

private:
	LINEINFO m_tInfo;
};

