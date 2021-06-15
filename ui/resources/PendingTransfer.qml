import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import api.ui.qcn 2.0

Item { id: pendingTransfers

	property alias count: pTList.count

	FontLoader { id: linea_basic; source: "qrc:/resources/linea-basic-10.ttf" }
	FontLoader { id: awesome; source: "qrc:/resources/fontawesome-webfont.ttf" }

	Text { id: emptyPTText
		text: qsTr("Empty")
		anchors.centerIn: parent
		font.pixelSize: 80
		font.weight: Font.Light
		color: "#10000000"
		visible: pTList.count > 0 ? false : true
	}

	Component { id: pTDelegate

		Item { id: pTWrapper
			width: parent.width
			height: 150
			anchors.horizontalCenter: parent.horizontalCenter
			Rectangle { id: pTRect
				width: parent.width - 20
				height: parent.height - 20
				anchors.centerIn: parent
				clip: true

				Row { id: pTRow
					anchors.fill: parent
					Item { id: fileIconWrapper
						height: parent.height
						width: parent.height

						Text { id: fileIcon
							text: qsTr("\ue007")
							font.family: linea_basic.name
							font.pixelSize: parent.width / 3
							anchors.centerIn: parent
							color: "#333"
						}
					}
					Item { id: content
						height: parent.height
						width: parent.width - fileIconWrapper.width - pTAction.width

						Column { id: infoCol
							height: parent.height - 30
							width: parent.width - 20
							anchors.centerIn: parent
							spacing: 5

							Item { id: pTFileName
								width: parent.width
								height: 30
								Text {
									width: parent.width - 20
									anchors.verticalCenter: parent.verticalCenter
									text: qsTr(filename)
									elide: Text.ElideMiddle
								}
							}

							Item { id: pTFileSize
								width: parent.width
								height: 30
								Text {
									width: parent.width - 20
									anchors.verticalCenter: parent.verticalCenter
									text: qsTr("<b>Size </b> : "+filesize)
								}
							}

							Item { id: pTFrom
								width: parent.width
								height: 30
								Text {
									width: parent.width - 20
									anchors.verticalCenter: parent.verticalCenter
									text: qsTr("<b>From </b> : "+clientname)
								}
							}
						}
					}
					Item { id: pTAction
						height: parent.height
						width: height / 2

						Column {
							anchors.fill: parent
							QcnButton {
								icon: qsTr("\ue01c")
								iconFont: Qt.font({	family: linea_basic.name, pixelSize: 20 })
								height: parent.width
								width: parent.width
								radius: 0
								shadowRadius: 3
								color: "#fbfbfb"
								textColor: "#333"
                                onClicked: Qcn.rejectTransfer(id)
							}
							QcnButton {
								icon: qsTr("M")
								iconFont: Qt.font({	family: linea_basic.name, pixelSize: 20 })
								height: parent.width
								width: parent.width
								radius: 0
								shadowRadius: 3
								color: "#fbfbfb"
								textColor: "#333"
                                onClicked: Qcn.acceptTransfer(id)
							}
						}
					}
				}
			}
			DropShadow { 
				anchors.fill: pTRect
				source: pTRect
				horizontalOffset: 0
				verticalOffset: 0
				radius: 8
				samples: 16
				color: "#30000000"
				transparentBorder: true
			}
		}
	}

	ScrollView {
		anchors.fill: parent
		flickableItem.interactive: true

		style: ScrollViewStyle {
			transientScrollBars: true
			handle: Item {
				implicitWidth: 14
				implicitHeight: 26
				Rectangle {
					color: "#50000000"
					anchors.fill: parent
					anchors.margins: 4
					radius: 4
				}
			}
		}

		ListView { id:pTList
			anchors.fill: parent
			anchors.topMargin: 5
			delegate: pTDelegate
            model: Qcn.pendingTransfers
			spacing: 5
		}
	}
}
