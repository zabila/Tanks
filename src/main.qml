import QtQuick 2.0
import QtQuick.Controls 2.15

ApplicationWindow {
    id: applicatin
    title: "Tank Game"
    width: 800
    height: 670
    visible: true

    Loader { id: pageLoader
        anchors.fill: parent
        source: "qml/StartMenuLayer.qml"
    }
}
