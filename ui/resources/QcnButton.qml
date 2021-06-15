import QtQuick 2.5
import QtQuick.Controls 2.1
import QtGraphicalEffects 1.0
import api.ui.qcn 2.0

Item { id: btnRoot
	signal clicked

	property alias icon : btnIcon.text
	property alias iconFont: btnIcon.font

	property alias text : btnText.text
	property alias textFont: btnText.font

	property alias color : btnBack.color
	property string textColor : "#fbfbfb"

	property bool active : false
    property string activeTextColor : Qcn.theme
	property string activeColor : textColor

	property alias radius: btnBack.radius
	property alias shadow : dropBtnBack.visible
	property alias shadowRadius: dropBtnBack.radius
	property alias shadowColor: dropBtnBack.color

	height: 40
	width: content.width <  height ? height : content.width + 20

	Rectangle { id: btnBack
		anchors.fill: parent
        color: btnRoot.active ? btnRoot.activeColor : Qcn.theme
		radius: 4
		clip: true

		Row { id: content
			height: parent.height
			width: iconBlk.width + textBlk.width
			anchors.horizontalCenter: parent.horizontalCenter
			Item { id: iconBlk
				width: btnIcon.implicitWidth > 0 ? 30 : 0
				height: parent.height
				Text { id: btnIcon
					anchors.centerIn: parent
					color: active ? btnRoot.activeTextColor : btnRoot.textColor
				}
			}
			Item { id: textBlk
				width: btnText.implicitWidth
				height: parent.height
				Text { id: btnText
					font.weight: Font.Bold
					anchors.verticalCenter: parent.verticalCenter
					color: active ? btnRoot.activeTextColor : btnRoot.textColor
				}
			}
		}

		MouseArea { id: btnArea
			anchors.fill: parent
			cursorShape: Qt.PointingHandCursor
			onClicked: {
				btnRoot.clicked()
			}
		}
	}

	DropShadow { id: dropBtnBack
		anchors.fill: btnBack
		source: btnBack
		horizontalOffset: 0
		verticalOffset: 0
		radius: 8
		samples: 17
		color: "#30000000"
		transparentBorder: true
	}
}
