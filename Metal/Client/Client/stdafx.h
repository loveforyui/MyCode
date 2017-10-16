// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <map>
#include <vector>
#include <list>
#include <io.h>

//gdi+
#include <Ole2.h>
#include <gdiplus.h>

#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

using namespace std;

#include "Includes.h"
#include "Managers.h"
