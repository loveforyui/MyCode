#pragma once

class CObj;
class CCollisionManager
{
public:
    CCollisionManager();
    ~CCollisionManager();

public:
    static void CollisionRect   (OBJLIST& dst, OBJLIST& src);
    static void CollisionSphere (OBJLIST& dst, OBJLIST& src);
    static void COllisionImage  (OBJLIST& dst, OBJLIST& src);

private:
    static bool CheckSphere     (CObj* dst, CObj* src);
    static bool CheckImage      (CObj * dst, CObj * src);
};