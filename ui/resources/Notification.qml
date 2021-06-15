import QtQuick 2.5
import QtQuick.Controls 2.1
import QtGraphicalEffects 1.0
import QtQml 2.2
import api.ui.qcn 2.0

Item { id: notification

	property alias text: notificationMsg.text
	property alias status: notification.state

	Behavior on visible {NumberAnimation {duration: 300} }
	Behavior on opacity {NumberAnimation {duration: 200} }

	clip: true
	height: 220
	width: 320
	x: parent.width - width - 20
	y: parent.height - height

	FontLoader { id: awesome; source: "qrc:/resources/fontawesome-webfont.ttf" }

	states: [
		State {
			name: "Active"
			PropertyChanges {
				target: notification
				opacity: 1
				visible: true
			}
			PropertyChanges {
				target: notificationTimer
				running: true
			}
		},
		State {
			name: "Inactive"
			PropertyChanges {
				target: notification
				opacity: 0
				visible: false
			}
		}
	]

	Timer { id: notificationTimer
		running: false
		interval: 5000
		repeat: false
		onTriggered: {
            Qcn.notificationStatus = "Inactive"
		}
	}

	Rectangle { id: notificationItem
		radius: 5
		height: 200
		width: 300
		anchors.centerIn: parent

		Item{
			anchors.fill: parent
			Item { id: closeItem
				height: 40
				width: height
				anchors.top: parent.top
				anchors.right: parent.right
				Text { 
					text: qsTr("\uf00d")
					font.pixelSize: 16
					anchors.centerIn: parent
					color: "#444"
				}
				MouseArea{
					anchors.fill: parent
					cursorShape: Qt.PointingHandCursor
					onClicked: {
                        Qcn.notificationStatus = "Inactive"
						notificationTimer.stop()
					}
				}
			}
			TextArea { id: notificationMsg
				font.weight: Font.Light
				font.pixelSize: 16
				wrapMode: TextArea.WordWrap
				width: parent.width - 20
				anchors.horizontalCenter: parent.horizontalCenter
				anchors.bottom: parent.border
				anchors.top: closeItem.bottom
				anchors.margins: 10
				readOnly: true
			}
		}

	}

	DropShadow { 
		anchors.fill: notificationItem
		source: notificationItem
		horizontalOffset: 0
		verticalOffset: 0
		radius: 16
		samples: 32
		color: "#20000000"
		transparentBorder: true
	}
}
