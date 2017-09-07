#ifndef __SUBJECT_H_
#define __SUBJECT_H_

typedef struct
{
    LPWSTR                                  _name_wc;
    UINT                                    _korean_ui;
    UINT                                    _english_ui;
    UINT                                    _math_ui;
    UINT                                    _total_ui;
    FLOAT                                   _avg_f;

}SUBJECT_SCORE;

class Subject
{
private:
    SUBJECT_SCORE*                          m_user;
public:
    wchar_t m_subjectName_wc[5][32]         = {
                                                L"���� ����:",
                                                L"���� ����:",
                                                L"���� ����:",
                                                L"���� �հ�:",
                                                L"���� ���:"
                                            };

    Subject();
    ~Subject();

    void                    CreateUser      (LPWSTR name, UINT kor, UINT eng, UINT math);
    const SUBJECT_SCORE&    GetUserInfo     ();
    //const SUBJECT_SCORE&    GetUserInfo     (LPWSTR name);
    //void                    SetUserName     (LPCWSTR name);
    //wchar_t&                GetUserInfoName ();
};

#endif // !__SUBJECT_H_


