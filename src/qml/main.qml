import QtQuick 2.0
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Game Window")

    Connections {
        target: gameManager
        onStarted: console.log("Game started")
        onEnded: console.log("Game ended")
    }

    Row {
        spacing: 10
        anchors.centerIn: parent

        Button {
            text: "Start Game"
            onClicked: gameManager.startGame()
        }

        Button {
            text: "End Game"
            onClicked: gameManager.endGame()
        }

    }

}
