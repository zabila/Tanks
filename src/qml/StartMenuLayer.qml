import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Rectangle {
    width: applicatin.width
    height: applicatin.height

    Rectangle {
        id: menuPage
        width: parent.width
        height: parent.height
        color: "black"

        SequentialAnimation on opacity {
            running: true
            loops: Animation.Infinite
            PropertyAnimation {
                target: menuPage
                property: "opacity"
                from: 1
                to: 0.5
                duration: 1000
            }
            PropertyAnimation {
                target: menuPage
                property: "opacity"
                from: 0.5
                to: 1
                duration: 1000
            }
        }

        Column {
            anchors.centerIn: parent
            spacing: 10

            Button {
                id: startButton
                text: "Start Game"
                onClicked: {
                   gameController.startGame();
                   pageLoader.source = "GameLayer.qml"
                }
            }

            Button {
                id: optionsButton
                text: "Options"
                onClicked: {
                    console.log("Options button clicked")
                }
            }

            Button {
                id: quitButton
                text: "Quit Game"
                onClicked: {
                    console.log("Quit Game button clicked")
                }
            }
        }
    }

    Connections {
        target: gameController
    }
}
