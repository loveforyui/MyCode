#pragma once

#define WINCX 800
#define WINCY 400

// Math
#define PI 3.1415f
#define GRAVITY 9.8f

#define RadianToDegree(X) (X * 180.f / PI)
#define DegreeToRadian(X) (X * PI / 180.f)

//Singletone
#define DECLARE_SINGLETON(ClassName)		\
public:										\
	static ClassName* GetInstance()			\
	{										\
		if (nullptr == m_pInstance)			\
			m_pInstance = new ClassName;	\
		return m_pInstance;					\
	}										\
	void DestroyInstance()					\
	{										\
		if (m_pInstance)					\
		{									\
			delete m_pInstance;				\
			m_pInstance = nullptr;			\
		}									\
	}										\
private:									\
	static ClassName* m_pInstance;

#define IMPLEMENT_SINGLETON(ClassName)		\
ClassName* ClassName::m_pInstance = nullptr;