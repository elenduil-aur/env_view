
import QtQuick 2.0


ListView {
    id: envList
    property string filterString: ""
    model: environmentModel
    width: parent.width; height: 640

    Component {
        id: entryDelegate

        Row {
            readonly property bool filtered: filterString === ""
                                             || env_key.indexOf(filterString) !== -1;
            visible: filtered
            width: envList.width

            Rectangle {
                width: parent.width / 2; height: parent.height
                color: index % 2 === 0 ? "#d2d2d2" : "white";
                Text {
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    text: (index + 1) + ".\t" + env_key
                }
            }

            Rectangle {
                width: parent.width / 2; height: valueText.contentHeight
                color: index % 2 === 0 ? "#d2d2d2" : "white";
                Text {
                    id: valueText
                    width: parent.width
                    font.family: "monospace"
                    wrapMode: Text.WrapAnywhere
                    text: env_val
                }
            }
        }

    }

    delegate: entryDelegate

}
