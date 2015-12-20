import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import Login_Gui 1.0

Rectangle {
    id: logongui
    width: 400
    height: 360

    Login_Gui{
        id: login_gui
    }

    Text {
        id: username
        x: 35
        y: 96
        text: qsTr("用户名:")
        font.bold: true
        font.family: "Verdana"
        font.pointSize: 12
    }

    TextField {
        id: userid_edit
        x: 100
        y: 90
        width: 180
        height: 30
        placeholderText: qsTr("请输入您的用户名")
        //text: login_gui.user_id
    }

    Text {
        id: userpwd
        x: 35
        y: 177
        text: qsTr("密  码:")
        font.bold: true
        font.pointSize: 12
    }

    TextField {
        id: password_edit
        x: 100
        y: 170
        width: 180
        height: 30
        placeholderText: qsTr("请输入您的密码")
        maximumLength: 32
        echoMode: 2
        text: login_gui.password   
    }

    CheckBox {
        id: remember_pwd
        x: 76
        y: 220
        text: qsTr("记住密码")
        checked: login_gui.bAutoLogon
    }

    CheckBox {
        id: auto_login
        x: 240
        y: 220
        text: qsTr("自动登录")
        //checked: login_gui.flag_autologon
    }

    Button {
        id: regist_btn
        x: 300
        y: 90
        width: 80
        height: 30
        text: qsTr("注  册")
        onClicked:
        {
            //login_gui.OnRegister();
            console.log("注册");
        }
    }

    Button {
        id: login_btn
        x: 100
        y: 280
        width: 200
        height: 50
        text: qsTr("登   录")
        onClicked: login_req()
    }

    Button {
        id: findpwd
        x: 300
        y: 170
        width: 80
        height: 30
        text: qsTr("忘记密码？")
    }

    MessageDialog {
        id: msgBox
        width: 200
        height: 100

        title: qsTr("提示")
/*
        function onshow(strmsg) {
            msgBox.text = strmsg
            msgBox.open()
        }*/
    }

    //登录请求
    function login_req()
    {
        if(userid_edit.text == "")
        {
            msgBox.text = qsTr("请输入用户名");
            msgBox.open();
            return;
        }
        if(password_edit.text == "")
        {
            msgBox.text = qsTr("请输入密码");
            msgBox.open();
            return;
        }
        else if(password_edit.text.length < 6 || password_edit.text.length > 20)
        {
            msgBox.text = qsTr("密码建议6~20个字符");
            msgBox.open();
            return;
        }

        login_gui.userID = userid_edit.text;
        login_gui.password = password_edit.text;
        login_gui.flagRebPwd = remember_pwd.checked;
        login_gui.bAutoLogon = auto_login.checked;
        login_gui.OnLogin();
    }

    //Login_Gui.m_strUserid = userid_edit.text
}

