import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import api.ui.qcn 2.0

ApplicationWindow { id:root
	visible: true
	minimumWidth: 800
	minimumHeight: 600
	x:(Screen.width-800)/2
	y:(Screen.height-600)/2
	flags: Qt.FramelessWindowHint

	property string textColor:  "#333"
	property string rootBgColor: "#f9f9f9"

	Welcome{
		onUpdated: {
            Qcn.userName = username
            Qcn.downloadDir = ddir
            Qcn.theme = themeColor
		}
	}

	Item {
		anchors.fill: parent

		SideBar{ id: sb
            title: qsTr("𝓺𝓬𝓷")
		}

		Rectangle { id:window
			height: parent.height
			anchors.left: sb.right
			anchors.right: parent.right
			color: root.rootBgColor

			AppControls { id: appControls
				anchors.top:parent.top
				width: parent.width
				height: 40
				onClose: Qt.quit()
				onMaximized: root.showMaximized()
				onMinimized: root.showMinimized()
				onDrag: {
					root.x += dragX
					root.y += dragY
				}
			}

			MainView { id:mainView
				textColor: root.textColor
				bgColor: root.rootBgColor
				sideBar: sb
				anchors.left: parent.left
				anchors.right: parent.right
				anchors.top: appControls.bottom
				anchors.bottom: statusBar.top
			}

			StatusBar { id:statusBar
				width:parent.width
				height: 24
				anchors.bottom: parent.bottom
				onSizeChanged: {
					root.width += sizeX
					root.height += sizeY
				}
			}
		}

		InnerShadow {
			anchors.fill: window
			cached: true
			horizontalOffset: 1
			verticalOffset: 0
			radius: 4
			samples: 32
			color: "#10000000"
			smooth: true
			source: window
		}

	}
}

