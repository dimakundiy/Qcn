import QtQuick 2.5
import QtQuick.Controls 2.0

Item { id: item

	property string textColor
	property string bgColor

	clip: true

	Item {
		height: parent.height
		width: parent.width > 750 ? 750 : parent.width
		anchors.horizontalCenter: parent.horizontalCenter
		Item {id: tabView
			height: 40
			width: parent.width
			anchors.top: parent.top
			Row {
				clip: true
				anchors.fill: parent
				QcnButton { id: requestedBtn
					width: parent.width / 2
					radius: 0
					active: true
					activeColor: "#fff"
					text: qsTr("Requested"+"  ("+pendingTransfer.count+")")
					onClicked: {
						active = true
						activeBtn.active = false
						pendingTransfer.visible = true
						activeTransfer.visible = false
					}
				}
				QcnButton { id: activeBtn
					width: parent.width / 2
					radius: 0
					active: false
					activeColor: "#fff"
					text: qsTr("Active"+"  ("+activeTransfer.count+")")
					onClicked: {
						active = true
						requestedBtn.active = false
						pendingTransfer.visible = false
						activeTransfer.visible = true
					}
				}
			}
		}

		Item { id: transferView
			anchors.top: tabView.bottom
			anchors.bottom: parent.bottom
			width: parent.width
			PendingTransfer { id: pendingTransfer
				anchors.fill: parent
				anchors.topMargin: 30
			}
			ActiveTransfer { id: activeTransfer
				anchors.fill: parent
				anchors.topMargin: 30
				visible: false
			}
		}
	}
}
