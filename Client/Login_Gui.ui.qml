import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

Rectangle {
    id: login_gui
    width: 400
    height: 360

    TextField {
        id: userid_edit
        x: 140
        y: 90
        width: 180
        height: 30
        placeholderText: qsTr("请输入您的用户名")
    }

    TextField {
        id: password_edit
        x: 140
        y: 170
        width: 180
        height: 30
        placeholderText: qsTr("请输入您的密码")
        echoMode: TextInput.Password
        maximumLength: 32
    }

    CheckBox {
        id: reb_pwd
        x: 76
        y: 220
        text: qsTr("记住密码")
    }

    CheckBox {
        id: auto_login
        x: 240
        y: 220
        text: qsTr("自动登录")
    }

    Button {
        id: regist_btn
        x: 284
        y: 237
        width: 100
        height: 30
        text: qsTr("注册")
        onClicked: msgBox.onshow(qsTr("注册"))
    }

    Button {
        id: login_btn
        x: 100
        y: 280
        width: 200
        height: 50
        text: qsTr("登   录")
    }

    MessageDialog {
        id: msgBox
        width: 200
        height: 80

        title: qsTr("提示")

        function onshow(strmsg) {
            msgBox.text = strmsg
            msgBox.open()
        }
    }

    //Login_Gui.m_strUserid = userid_edit.text
}

