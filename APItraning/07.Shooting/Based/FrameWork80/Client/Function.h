#ifndef  __functions_h__
#define __functions_h__
template <typename T>
void SAFEDELETE(T& obj)
{
    if (obj)
    {
        delete obj;
        obj = nullptr;
    }
}
#endif // ! __functions_h__
