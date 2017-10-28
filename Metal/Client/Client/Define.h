#pragma once

#define WINCX 1200
#define WINCY 800

// Math
#define PI 3.14159265f
#define GRAVITY 9.8f

#define RadianToDegree(X) (X * 180.f / PI)
#define DegreeToRadian(X) (X * PI / 180.f)

#define IMG_PATH "../resource/Image/"

//Obj direction
#define OBJ_D_LEFT 0x01
#define OBJ_D_RIGH 0x02
#define OBJ_D_BOTT 0x04
#define OBJ_D_TOPP 0x08

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