import QtQuick 2.5
import QtQuick.Controls 1.4  //基础的控件
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Window {
    id:root
    visible: true

    width: 400
    height: 350
    title: qsTr("客户端")

    Button {
        text: qsTr("注册")
        onClicked: msgBox.show("kakak")
    }

    MessageDialog{
        id: msgBox
        title: qsTr("Hi")

        function show( caption )
        {
            msgBox.text = caption;
            msgBox.open();
        }
    }
}

