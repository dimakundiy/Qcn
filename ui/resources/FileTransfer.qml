import QtQuick 2.5
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
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

	contentItem: Item{
		anchors.fill: parent
		Text { id: fileTransferText
			text: qsTr("Send File")
			font.pixelSize: 24
			anchors.top: parent.top
			anchors.topMargin: 10
			anchors.horizontalCenter: parent.horizontalCenter
		}

		Rectangle{ id: fileTransferForm
			anchors.horizontalCenter: parent.horizontalCenter
			anchors.bottom: parent.bottom
			anchors.bottomMargin: 20
			height: fileSelectForm.height+sendFileForm.height
			width: filePathField.width + fileTransferBtn.width

			FileDialog{
				id: sendFileDialog
				selectFolder: false
				selectExisting: true
			}

			Column{
				anchors.fill: parent

				Row { id: fileSelectForm
					width: parent.width
					height: 40
					TextField { id: filePathField
						height: parent.height
						width: 300
						placeholderText: qsTr(" File Location")
						text: sendFileDialog.fileUrl
						background: Rectangle {
							implicitHeight: 40
							implicitWidth: 200
							color: parent.activeFocus ? "transparent" : "#f6f6f6"
                            border.color: parent.activeFocus ? Qcn.theme : "#888"
							border.width: parent.activeFocus ? 2 : 0
						}
					}
					QcnButton {id: fileTransferBtn
						icon: qsTr("\uf15b")
						radius: 0
						shadow: false
						onClicked:{
							sendFileDialog.open()
						}
					}
				}
				Item { id: sendFileForm
					width:  parent.width
					height: 60

					QcnButton { id: sendFileBtn
						anchors.bottom: parent.bottom
						anchors.right: parent.right
						icon: qsTr("\uf1d8")
						iconFont: awesome.name
						text: qsTr("Send")
						onClicked: {
                            Qcn.sendFile(filePathField.text);
							item.close()
						}
					}
				}
			}
		}
	}
}
