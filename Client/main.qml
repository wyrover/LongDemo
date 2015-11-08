import QtQuick 2.5
import QtQuick.Window 2.2
import Login_Gui 1.0

Window {
    visible: true

    width: 400
    height: 360
/*
    MainForm {
        anchors.fill: parent
    }
    */

    Login_Gui {
        id: loginDialog
        anchors.fill: parent
    }
}

