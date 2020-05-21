import QtQuick 2.4

Item {
    width: 400
    height: 400

    Rectangle {
        id: rectangle
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#0032b7"
            }

            GradientStop {
                position: 1
                color: "#3b71ff"
            }
        }
        anchors.fill: parent

        TextInput {
            id: textInput
            x: 160
            y: 190
            width: 80
            height: 20
            text: qsTr("Text Input")
            font.pixelSize: 12
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:170;anchors_y:100}
}
##^##*/
