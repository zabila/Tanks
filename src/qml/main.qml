import QtQuick 2.0
import QtQuick.Controls 2.15
import MyEnums 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Game Window")

    Connections {
        target: gameController
    }
    property var tanks: gameController.ememyTanks

    Component.onCompleted: {

        for (var i = 0; i < tanks.length; i++) {
            var tank = tanks[i];
            console.log("---------------");
            console.log(tank);
            console.log(tank.position);
            console.log(tank.position.x);
            console.log(tank.position.y);
            console.log(tank.speed);
            tank.draw();
            tank.move(Direction.UP);
            tank.shoot();
            console.log("---------------");
        }
    }

    Rectangle {
        color: "black"
        width: 30
        height: 30
//        x: gameController.player.postion.x
//        y: gameController.player.postion.y
    }

    Column {
        anchors.fill: parent

        Grid {
            columns: 30
            rows: 30
            spacing: 2


            Repeater {

                 model: tanks

                delegate: Rectangle {
                    id: tank

                    width: 20
                    height: 20
                    x: model.position.x * (width + parent.spacing)
                    y: model.position.y * (height + parent.spacing)

                    Text {
                        anchors.centerIn: parent
                        text: model.health
                    }

                }

            }

        }

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            Keys.onPressed: {
                if (event.key === Qt.Key_Left)
                    test()
                else if (event.key === Qt.Key_Right)
                    gameController.movePlayer(3);
                else if (event.key === Qt.Key_Up)
                    gameController.movePlayer(0);
                else if (event.key === Qt.Key_Down)
                    gameController.movePlayer(1);
            }

            Button {
                text: "Start Game"
                onClicked: gameController.startGame()
            }

            Button {
                text: "End Game"
                onClicked: gameController.endGame()
            }

        }

    }

}
