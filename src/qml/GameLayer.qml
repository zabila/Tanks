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
                color: "blue"

                Rectangle
                {
                    color: "black"
                    width: 30
                    height: 30
                    focus: true
                    x: player.position.x
                    y: player.position.y
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

    property var player: playerTankController.playerTank
    property var tanks: enemyTanksController.ememyTanks

    Component.onCompleted: {
        console.log("---------------");
        console.log(player);
        console.log(player.position);
        console.log(player.position.x);
        console.log(player.position.y);
        console.log(player.speed);
        player.draw();
        player.move(EDirection.UP);
        player.shoot();
        console.log("---------------");

        for (var i = 0; i < tanks.length; i++) {
            var tank = tanks[i];
            console.log("---------------");
            console.log(tank);
            console.log(tank.position);
            console.log(tank.position.x);
            console.log(tank.position.y);
            console.log(tank.speed);
            tank.draw();
            tank.move(EDirection.UP);
            tank.shoot();
            console.log("---------------");
        }
    }
}
