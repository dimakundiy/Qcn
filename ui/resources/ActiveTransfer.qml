import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import api.ui.qcn 2.0

Item { id: pendingTransfers

	property alias count: aTList.count

	FontLoader { id: linea_basic; source: "qrc:/resources/linea-basic-10.ttf" }
	FontLoader { id: awesome; source: "qrc:/resources/fontawesome-webfont.ttf" }

	Text { id: emptyATText
		text: qsTr("Empty")
		anchors.centerIn: parent
		font.pixelSize: 80
		font.weight: Font.Light
		color: "#10000000"
		visible: aTList.count > 0 ? false : true
	}

	Component { id: aTDelegate

		Item { id: aTWrapper
			width: parent.width
			height: 210
			anchors.horizontalCenter: parent.horizontalCenter
			Rectangle { id: aTRect
				width: parent.width - 20
				height: parent.height - 20
				anchors.centerIn: parent
				clip: true

				Row { id: aTRow
					anchors.fill: parent
					Item { id: fileIconWrapper
						height: parent.height
						width: 150

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
						width: parent.width - fileIconWrapper.width - aTAction.width

						Column { id: infoCol
							height: parent.height - 30
							width: parent.width - 20
							anchors.centerIn: parent
							spacing: 5

							Item { id: aTFileName
								width: parent.width
								height: 30
								Text {
									width: parent.width - 20
									anchors.verticalCenter: parent.verticalCenter
									text: qsTr(filename)
									elide: Text.ElideMiddle
								}
							}

							Item { id: aTFrom
								width: parent.width
								height: 30
								Text {
									width: parent.width - 20
									anchors.verticalCenter: parent.verticalCenter
									text: qsTr("<b>From </b> : "+clientname)
								}
							}

							Item { id: aTProgress
								width: parent.width
								height: 30
								ProgressBar {
									anchors.verticalCenter: parent.verticalCenter
									width: parent.width - 20
									minimumValue: 0
									maximumValue: 100
									value: progress
									style: ProgressBarStyle {
										background: Rectangle {
											implicitWidth: 200
											implicitHeight: 20
											color: "#fafafa"
											border.color: "#f8f8f8"
											anchors.fill: parent
										}
										progress: Rectangle {
                                            color: Qcn.theme
											anchors.margins: 1
										}
									}
								}
							}

							Item { id: aTFileSize
								width: parent.width
								height: 30
								Text {
									width: parent.width - 20
									anchors.verticalCenter: parent.verticalCenter
									text: qsTr(transfered+" / "+filesize+" ( "+rate+" MB/sec )")
								}
							}

							Item { id: aTTimeRemaining
								width: parent.width
								height: 30
								Text {
									width: parent.width - 20
									anchors.verticalCenter: parent.verticalCenter
									text: qsTr(timeRemaining+" remaining ")
								}
							}

						}
					}
					Item { id: aTAction
						height: parent.height
						width: 150/2

						Column {
							anchors.fill: parent
                            QcnButton {
								icon: qsTr("\ue01f")
								iconFont: Qt.font({ family: linea_basic.name, pixelSize: 20 })
								height: parent.height
								width: parent.width
								radius: 0
								shadowRadius: 3
								color: "#fbfbfb"
								textColor: "#333"
                                onClicked: Qcn.stopTransfer(id)
							}
						}
					}
				}
			}
			DropShadow { 
				anchors.fill: aTRect
				source: aTRect
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

		ListView { id:aTList
			anchors.fill: parent
			anchors.topMargin: 5
			delegate: aTDelegate
            model: Qcn.runningTransfers
			spacing: 5

		}
	}

}

