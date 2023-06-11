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
                height: gameController.mapHeight
                width: height
                border.width: 2
                border.color: "blue"

                Rectangle
                {
                    id: playertTank
                    color: "black"
                    width: player.size
                    height: player.size
                    focus: true
                    x: player.position.x
                    y: player.position.y
                }

                Repeater
                {
                    id: tanksRepeater
                    model: tanks
                    delegate: Rectangle
                    {
                        color: "yellow"
                        width: modelData.size
                        height: modelData.size
                        focus: true
                        x: modelData.position.x
                        y: modelData.position.y
                    }

                }

                Repeater
                {
                    id: wallsRepeater
                    model: walls
                    delegate: Rectangle
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


    Timer {
        interval: 500 // 500 milliseconds = 0.5 seconds
        running: true
        repeat: true
        onTriggered: {
             var tankDirections = [EDirection.DOWN, EDirection.LEFT, EDirection.RIGHT, EDirection.UP]
             for (var i = 0; i < tanks.length; i++) {
             var randomIndex = Math.floor(Math.random() * tankDirections.length);
             var randomDirection = tankDirections[randomIndex];
             for(var j = 0; j < 5 ; j++)
             {
                tanks[i].move(randomDirection);
             }
            }
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

    property var player : playerTankController.playerTank
    property var tanks : enemyTanksController.enemyTanks
    property var walls : wallController.walls

    onWallsChanged: {
        if (walls.length != wallController.walls.length)
        {
           walls = wallController.walls
        }
    }
}
