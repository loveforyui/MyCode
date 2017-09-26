#ifndef __macros_h__
#define __macros_h__

#define GetSet(_type, memberVal)\
    void set_##memberVal(_type& val)\
    {\
        memberVal = val;\
    }\
    const _type get_##memberVal(){return memberVal;}

#endif // !__macros_h__
