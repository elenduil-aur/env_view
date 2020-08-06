
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Process environment viewer")

    Item {
        id: rootWidget
        anchors.fill: parent

        TextField {
            id: filterEdit
            width: parent.width; height: 24
            placeholderText: qsTr("Filter output by var name")
            font.family: "monospace"
        }

        // Import from ./EnvList.qml.
        EnvList { y: filterEdit.y + filterEdit.height; filterString: filterEdit.text }
    }
}
