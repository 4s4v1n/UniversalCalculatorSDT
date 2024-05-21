import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "components"
import "pages"

ApplicationWindow {
    id: window
    width: 600
    height: 700
    flags: Qt.Window
    visible: true

    minimumWidth: 700
    maximumWidth: 700
    minimumHeight: 700
    maximumHeight: 700

    TabBar {
        id: bar
        width: parent.width

        TabButton {
            text: qsTr("Калькулятор")
        }

        TabButton {
            text: qsTr("Справка")
        }
    }

    StackLayout {
        anchors {
            top: bar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        currentIndex: bar.currentIndex

        MainPage {}
        ReferencePage {}
    }
}
