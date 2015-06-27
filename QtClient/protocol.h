#ifndef PROTOCOL
#define PROTOCOL

#include <memory.h>

#define GLXY_FIRST_ID 11280

enum GL_XYID
{
    GLXY_FIRST = GLXY_FIRST_ID,

    GLXY_TEST,   //测试

};

//协议:测试
struct msgTest
{
    enum { XY_ID = GLXY_TEST };

    int nFlag; //test

    msgTest() { reset(); }

    void reset() { memset( this, 0, sizeof(*this)); }



};

#endif // PPROTOCOL

