import QtQuick 2.0
import QtGraphicalEffects 1.0
import api.ui.qcn 2.0

Item { id: item
	width: 70
	height: parent.height
	anchors.left: parent.left

    property string theme: Qcn.theme
	property alias title : applicationNameText.text
	property real tabHeight : 60

	signal messengerClicked
	signal transferManagerClicked
	signal settingsClicked
	signal quickConnectClicked
	signal fileTransferClicked

	FontLoader { id: linea_basic; source: "qrc:/resources/linea-basic-10.ttf" }

	Item { id:sidePane
		anchors.fill: parent
		property int currentId: 0

		Column{
			anchors.fill: parent

			Item { id: applicationName
				width: parent.width
				height: item.tabHeight

				Text {
					id: applicationNameText
					color: item.theme
					font.pixelSize: 24
					anchors.centerIn: parent
				}
			}

			Item { id: messenger
				width: parent.width
				height: item.tabHeight

				property int idno: 0
				property string color: sidePane.currentId == idno ? item.theme : "#999"

				Text { id: messengerIcon
					anchors.centerIn: parent
					font.family: linea_basic.name
					text: qsTr(".")
					color: parent.color
					font.pixelSize: 24
				}

				MouseArea{
					anchors.fill: parent
					cursorShape: Qt.PointingHandCursor
					onClicked: {
						sidePane.currentId = parent.idno
                        Qcn.unreadMessages = 0
						messengerClicked()
					}
				}

				Rectangle { id: msgRemainingBlock
                    visible: sidePane.currentId == parent.idno ? false : Qcn.unreadMessages === 0 ? false : true
					anchors.bottom: parent.bottom
					anchors.right: parent.right
					height: remainingMsg.implicitWidth + 12
					width: height
					radius: width/2
					color: "#10000000"

					Connections{
                        target: Qcn
						onUnreadMessagesChanged: {
                            if(sidePane.currentId == parent.idno && Qcn.unreadMessages != 0)
                                Qcn.unreadMessages = 0
						}
					}

					Text { id: remainingMsg
                        text: Qcn.unreadMessages
						anchors.centerIn: parent
                        color: Qcn.theme
						font.pixelSize: 10
					}
				}
			}

			Item { id: transferManager
				width: parent.width
				height: item.tabHeight

				property int idno: messenger.idno + 1
				property string color: sidePane.currentId == idno ? item.theme : "#999"

				Text { id: transferManagerIcon
					anchors.centerIn: parent
					font.family: linea_basic.name
					text: qsTr("F")
					color: parent.color
					font.pixelSize: 24
				}

				MouseArea{
					anchors.fill: parent
					cursorShape: Qt.PointingHandCursor
					onClicked: {
						sidePane.currentId = parent.idno
                        Qcn.unseenTransfers = 0
						transferManagerClicked()
					}
				}

				Rectangle { id: transferRemainingBlock
                    visible: sidePane.currentId == parent.idno ? false : Qcn.unseenTransfers === 0 ? false : true
					anchors.bottom: parent.bottom
					anchors.right: parent.right
					height: remainingTransfer.implicitWidth+12
					width: height
					radius: width/2
					color: "#10000000"

					Connections{
                        target: Qcn
						onUnseenTransfersChanged: {
                            if(sidePane.currentId == parent.idno && Qcn.unseenTransfers != 0)
                                Qcn.unseenTransfers = 0
						}
					}

					Text { id: remainingTransfer
                        text: Qcn.unseenTransfers
						anchors.centerIn: parent
                        color: Qcn.theme
						font.pixelSize: 10
					}
				}
			}

			Item { id: settings
				width: parent.width
				height: item.tabHeight

				property int idno: transferManager.idno + 1
				property string color: sidePane.currentId == idno ? item.theme : "#999"

				Text { id: settingsIcon
					anchors.centerIn: parent
					font.family: linea_basic.name
					text: qsTr("P")
					color: parent.color
					font.pixelSize: 24
				}

				MouseArea{
					anchors.fill: parent
					cursorShape: Qt.PointingHandCursor
					onClicked: {
						sidePane.currentId = parent.idno
						settingsClicked()
					}
				}
			}

			Item { id: quickConnect
				width: parent.width
				height: item.tabHeight

				property string color: "#999"

				Text { id: quickConnectIcon
					anchors.centerIn: parent
					font.family: linea_basic.name
					text: qsTr("8")
					color: parent.color
					font.pixelSize: 24
				}

				MouseArea{
					anchors.fill: parent
					cursorShape: Qt.PointingHandCursor
					onClicked: {
						quickConnectClicked()
					}
				}
			}

			Item { id: fileTransfer
				width: parent.width
				height: item.tabHeight

				property string color: "#999"

				Text { id: fileTransferIcon
					anchors.centerIn: parent
					font.family: linea_basic.name
					text: qsTr("\ue007")
					color: parent.color
					font.pixelSize: 24
				}

				MouseArea{
					anchors.fill: parent
					cursorShape: Qt.PointingHandCursor
					onClicked: {
						fileTransferClicked()
					}
				}
			}
		}
	}
}
