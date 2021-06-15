import QtQuick 2.5
import QtQuick.Controls 2.1
import QtGraphicalEffects 1.0
import api.ui.qcn 2.0

Popup { id: item
	height: 200
	width: 400
	x: (parent.width - 60 - width)/2
	y: (parent.height - height)/2
	modal: true

	FontLoader { id: awesome; source: "qrc:/resources/fontawesome-webfont.ttf" }

	background: Item{
		implicitHeight: 200
		implicitWidth: 400
		Rectangle { id: popupBack
			anchors.fill: parent
		}
		DropShadow { 
			anchors.fill: popupBack
			source: popupBack
			horizontalOffset: 0
			verticalOffset: 0
			radius: 16
			samples: 32
			color: "#60000000"
			transparentBorder: true
		}
	}

	contentItem: Item { 
		anchors.fill: parent
		Text { id: quickConnectText
			text: qsTr("Quick Connect")
			font.pixelSize: 24
			anchors.top: parent.top
			anchors.topMargin: 10
			anchors.horizontalCenter: parent.horizontalCenter
		}

		Item { id: quickConnectForm
			anchors.centerIn: parent
			height: 40
			width: quickConnectUrl.width + quickConnectBtn.width

			Row {
				anchors.fill: parent
				TextField { id: quickConnectUrl
					height: parent.height
					width: 300
					placeholderText: qsTr(" URL")
					onAccepted:{
                        Qcn.quickConnect(quickConnectUrl.text)
						quickConnectUrl.text = ""
						close()
					}
					background: Rectangle {
						implicitHeight: 40
						implicitWidth: 200
						color: parent.activeFocus ? "transparent" : "#f6f6f6"
                        border.color: parent.activeFocus ? Qcn.theme : "#888"
						border.width: parent.activeFocus ? 2 : 0
					}
				}
				QcnButton { id: quickConnectBtn
					shadow: false
					radius: 0
					icon: qsTr("\uf0c1")
					onClicked:{
                        Qcn.quickConnect(quickConnectUrl.text)
						quickConnectUrl.text = ""
						close()
					}
				}
			}
		}
	}
}
