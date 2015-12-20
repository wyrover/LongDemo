#ifndef CGLOBALDATA_H
#define CGLOBALDATA_H

//单例类
class CGlobalData
{
private:
    CGlobalData();

public:
    static CGlobalData* getInstance();

    //写下本地
    void InitData();

    void LoadParameter();


private:
    static CGlobalData* _instance;
    bool _bLogonAuto;	 //自动登录
    bool _bRemberPwd;   //记住密码
};

#endif // CGLOBALDATA_H
