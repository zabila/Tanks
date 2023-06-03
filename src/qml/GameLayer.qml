import QtQuick 2.0
import QtQuick.Controls 2.15
import MyEnums 1.0

Item {
    id: gameLayer

    Keys.onPressed: {
        if (event.key === Qt.Key_Left)
            player.move(EDirection.LEFT);
        else if (event.key === Qt.Key_Right)
            player.move(EDirection.RIGHT);
        else if (event.key === Qt.Key_Up)
            player.move(EDirection.UP);
        else if (event.key === Qt.Key_Down)
            player.move(EDirection.DOWN);
        else if (event.key === Qt.Key_Space)
            player.shoot()
    }

    Column
    {
        x: 30; y: x
        spacing: 10
        Row
        {
            spacing: 10
            Rectangle
            {
                id: map
                height: 500
                width: height
                border.width: 2
                border.color: "blue"

                Rectangle
                {
                    id: playertTank
                    color: "black"
                    width: 30
                    height: 30
                    focus: true
                    x: player.position.x
                    y: player.position.y
                }

                Repeater
                {
                    model: tanks

                    Rectangle
                    {
                        color: "yellow"
                        width: 30
                        height: 30
                        focus: true
                        x: modelData.position.x
                        y: modelData.position.y
                    }

                }

                Repeater
                {
                    model: walls

                    Rectangle
                    {
                        color: "green"
                        width: 30
                        height: 30
                        focus: true
                        x: modelData.position.x
                        y: modelData.position.y
                    }

                }
            }

            Rectangle
            {
                id: statistic
                width: 230
                height: map.height
                color: "red"
            }
        }

        Rectangle
        {
            id: additionalInformation
            height: 100
            width: map.width + statistic.width + 10
            color: "red"
        }
    }

    Connections {
        target: playerTankController
    }

    Connections {
        target: enemyTanksController
    }

    Connections {
        target: wallController
    }

    property var player;
    property var tanks;
    property var walls;

    Component.onCompleted: {
        gameController.initMap(map.width, map.height)
        player = playerTankController.playerTank
        tanks = enemyTanksController.enemyTanks
        walls = wallController.walls
    }
}
