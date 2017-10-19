#pragma once

class CObj;
class CMathMgr
{
public:
	CMathMgr();
	~CMathMgr();

public:
	static float CalcDistance(CObj* dst, CObj* src);
	static float CalcRadian(CObj* dst, CObj* src);
	static float CalcDegree(CObj* dst, CObj* src);
};

