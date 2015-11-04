#ifndef __LOG_PLUS_H__
#define __LOG_PLUS_H__

class Logplus
{
private:
    Logplus();
    ~Logplus();

public:
    static Logplus* GetInstance();

private:
    static Logplus* m_Instance;
};

#endif
