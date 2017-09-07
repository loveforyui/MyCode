#include "stdafx.h"
#include "Subject.h"


Subject::Subject()
{
    m_user = NULL;
}


Subject::~Subject()
{
    FREE_PTR(m_user);
}

void Subject::CreateUser(LPWSTR name, UINT kor, UINT eng, UINT math)
{
    m_user                  = new SUBJECT_SCORE;
    //m_user->_name_wc        = name;
    m_user->_name_wc = new WCHAR[64];
    wcscpy_s(m_user->_name_wc, 64, name);
    m_user->_korean_ui      = kor;
    m_user->_english_ui     = eng;
    m_user->_math_ui        = math;
    m_user->_total_ui       = kor + eng + math;
    m_user->_avg_f          = (FLOAT)m_user->_total_ui / 3;
}

const SUBJECT_SCORE & Subject::GetUserInfo()
{
    // TODO: 여기에 반환 구문을 삽입합니다.
    return *m_user;
}

//const SUBJECT_SCORE & Subject::GetUserInfo(LPWSTR name)
//{
//    // TODO: 여기에 반환 구문을 삽입합니다.
//}

//void Subject::SetUserName(LPCWSTR name)
//{
//    *(m_user->_name_wc) = *name;
//}
//
//wchar_t & Subject::GetUserInfoName()
//{
//    // TODO: 여기에 반환 구문을 삽입합니다.
//    return *(m_user->_name_wc);
//}
