#ifndef CGAMEDATA_H
#define CGAMEDATA_H
//这个类是单例类，用来存取一些数据的
class CGameData
{
public:
    static CGameData *ShareGameData();
    static CGameData *CreateGameData();
public:
    CGameData();
    virtual ~CGameData();
    virtual void ReSet();

public:
};

#endif // CGAMEDATA_H
