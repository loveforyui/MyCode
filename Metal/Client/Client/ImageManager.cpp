#include "stdafx.h"
#include "ImageManager.h"

CImageMgr* CImageMgr::m_pInstance = nullptr;

CImageMgr::CImageMgr()
{
    Initialize();
}

CImageMgr::~CImageMgr()
{
    Release();
}

void CImageMgr::                Initialize          ()
{
}

void CImageMgr::                Update              ()
{
}

void CImageMgr::                Release             ()
{
    for (map<const TCHAR*, vector<ObjImg*>*>::iterator iter = m_MapImage.begin();
        iter != m_MapImage.end(); ++iter)
    {
        for (vector<ObjImg*>::iterator i = (*iter).second->begin();
            i != (*iter).second->end();)
        {
            (*i)->Release();
            i = (*iter).second->erase(i);
        }
        (*iter).second->clear();
    }
}

void CImageMgr::                LoadImgFile         (const TCHAR* objName, const char* filePath)
{
    _finddata_t _fd = {};

    long handle = 0;

    char szFullPath[256] = "";
    strcpy_s(szFullPath, filePath);
    strcat_s(szFullPath, "*.*");
    handle = _findfirst(szFullPath, &_fd);

    if (-1 == handle)
    {
        MessageBox(g_hWnd, L"Not found file!", L"Failed !", MB_OK);
        return;
    }

    int iRes = 0;

    // next -> 경로의 이미지 저장
    vector<ObjImg*>* temp = new vector<ObjImg*>;

    while (-1 != iRes)
    {
        memset(szFullPath, 0, sizeof(szFullPath));
        strcpy_s(szFullPath, filePath);
        strcat_s(szFullPath, _fd.name);

        TCHAR* wPath = new TCHAR[strlen(szFullPath) + 1];
        TCHAR* wName = new TCHAR[strlen(_fd.name) + 1];

        MultiByteToWideChar(CP_ACP, 0, szFullPath, strlen(szFullPath) + 1
            , wPath, strlen(szFullPath) + 1);

        MultiByteToWideChar(CP_ACP, 0, _fd.name, strlen(_fd.name) + 1
            , wName, strlen(_fd.name) + 1);

        Image* img = new Image(wPath);
        ObjImg* objimg = new ObjImg;
        objimg->fileName = wName;
        objimg->filePath = wPath;
        //lstrcpy(objimg->FilePath, wPath);
        //lstrcpy(objimg->FileName, wName);
        objimg->image = img;        

        if (!strcmp(_fd.name, ".") || !strcmp(_fd.name, ".."))
        {
            iRes = _findnext(handle, &_fd);
            continue;
        }
        else
        {
            temp->push_back(objimg);
            iRes = _findnext(handle, &_fd);
        }
    }

    m_MapImage.insert(make_pair(objName, temp));
}

void CImageMgr::                DrawImg             (HDC hDC, Image* img, FLOAT fx, FLOAT fy, FLOAT fCX, FLOAT fCY)
{
    Graphics graphics(hDC);

    if (img)
        graphics.DrawImage(
                 img
                 , fx
                 , fy
                 , fCX
                 , fCY );
}

void CImageMgr::                DrawImg             (HDC hDC, const TCHAR * ObjName, const TCHAR * fileName, FLOAT fx, FLOAT fy)
{
    // 매개변수로 받은 hdc가 본체

    Graphics graphics(hDC);
    
    Image* img = FindImage(ObjName, fileName);

    if (img)
        graphics.DrawImage(
            img
            , fx
            , fy
            , Gdiplus::REAL(img->GetWidth())
            , Gdiplus::REAL(img->GetHeight())
        );
}

void CImageMgr::                DrawImg             (HDC hDC, const TCHAR * ObjName, const TCHAR * fileName, FLOAT fx, FLOAT fy, FLOAT fCX, FLOAT fCY)
{
    // 매개변수로 받은 hdc가 본체

    Graphics graphics(hDC);
    
    Image* img = FindImage(ObjName, fileName);
    
    if(img)
        graphics.DrawImage(
                 img
                 , fx
                 , fy
                 , fCX
                 , fCY );
}

void CImageMgr::DrawImg(HDC hDC, Image* img, FLOAT fx, FLOAT fy, FLOAT fCX, FLOAT fCY, FLOAT angle)
{
    Graphics graphics(hDC);
    
    Gdiplus::Matrix mat;
    mat.RotateAt(angle, Gdiplus::PointF(float(fx + fCX/2), float(fy + fCY/2))); // 좌표기준으로 회전

    graphics.SetTransform(&mat);
    
    if(img)
        graphics.DrawImage(
                 img
                 , fx
                 , fy
                 , fCX
                 , fCY );
}

Image * CImageMgr::             GetImage            (const TCHAR * ObjName, const TCHAR * fileName)
{
    // TODO: 여기에 반환 구문을 삽입합니다.
    return FindImage(ObjName, fileName);
}

vector<ObjImg*>* CImageMgr::    GetImageVector      (const TCHAR * objName)
{
    return m_MapImage[objName];
}

ObjImg * CImageMgr::            GetImageObjImg      (const TCHAR * ObjName, const TCHAR * fileName)
{
    for (size_t i = 0 ; i < m_MapImage[ObjName]->size(); ++i)
    {
        if (lstrcmp(m_MapImage[ObjName]->at(i)->fileName, fileName))
        {
            return m_MapImage[ObjName]->at(i);
        }
    }
    return nullptr;
}

Image* CImageMgr::              FindImage           (const TCHAR * ObjName, const TCHAR * fileName)
{
    for (auto i : m_MapImage)
    {
        if (!lstrcmp(ObjName, i.first))
        {
            for (vector<ObjImg*>::iterator iter = i.second->begin();
                iter != i.second->end(); ++iter)
            {
                if (!lstrcmp(fileName, (*iter)->fileName))
                {
                    return ((*iter)->image);
                }
            }
        }
    }
    return nullptr;
}
