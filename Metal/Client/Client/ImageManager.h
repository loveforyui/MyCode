#pragma once

class CImageMgr
{
private:
    CImageMgr();
    ~CImageMgr();

public:
    void Initialize();
    void Update();
    void Release();

public:
    void                LoadImgFile     (const TCHAR*, const char*);
    void                DrawImg         (HDC hDC, Image * img, FLOAT fx, FLOAT fy, FLOAT fCX, FLOAT fCY);
    void                DrawImg         (HDC hdc, const TCHAR * ObjName, const TCHAR * fileName, FLOAT fx, FLOAT fy);
    void                DrawImg         (HDC hDC, const TCHAR * ObjName, const TCHAR * fileName, FLOAT fx, FLOAT fy, FLOAT fCX, FLOAT fCY);

public:
    Image*              GetImage        (const TCHAR * ObjName, const TCHAR * fileName);
    vector<ObjImg*>*    GetImageVector  (const TCHAR* objName);
    ObjImg*             GetImageObjImg  (const TCHAR * ObjName, const TCHAR * fileName);

private:
    Image*              FindImage       (const TCHAR * ObjName, const TCHAR * fileName);

public:
    static CImageMgr*   GetInst()
    {
        if (nullptr == m_pInstance)
            m_pInstance = new CImageMgr;

        return m_pInstance;
    }
    void                DestroyInstance()
    {
        if (m_pInstance)
        {
            m_pInstance->Release();

            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }

private:
    static CImageMgr*           m_pInstance;

    map<const TCHAR*, vector<ObjImg*>*>   m_MapImage;
};

#define IMG_LOAD(Key, Path) CImageMgr::GetInst()->LoadImgFile(Key, Path)
#define IMG_DRAW_I(Hdc, IMG, Fx, Fy, Fcx, Fcy) CImageMgr::GetInst()->DrawImg(Hdc, IMG, Fx, Fy, Fcx, Fcy)
#define IMG_DRAW_B(Hdc, Key, Filename, Fx, Fy) CImageMgr::GetInst()->DrawImg(Hdc, Key, Filename, Fx, Fy)
#define IMG_GET(Key, Value) CImageMgr::GetInst()->GetImage(Key, Value)
#define IMG_GET_V(Key) CImageMgr::GetInst()->GetImageVector(Key)
#define IMG_GET_O(Key, Value) CImageMgr::GetInst()->GetImageObjImg(Key, Value)