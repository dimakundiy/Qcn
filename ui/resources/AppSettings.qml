import QtQuick 2.5
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2
import QtQml 2.2
import api.ui.qcn 2.0

Item { id: item
	clip: true

    property string theme: Qcn.theme
	property string textColor: "#333"
	property string bgColor: "#f7f7f7"

	property alias username: userName.text
	property alias ddir: downloadDirVal.text
	property alias themeColor: colorDialog.color

	signal updated()

	FontLoader { id: linea_basic; source: "qrc:/resources/linea-basic-10.ttf" }
	FontLoader { id: awesome; source: "qrc:/resources/fontawesome-webfont.ttf" }

	Column{

		anchors.top: parent.top
		anchors.bottom: saveBtn.top
		anchors.left: parent.left
		anchors.right: parent.right

		Item{
			width: 300
			height: userName.height + userNameLabel.height + 50

			Column {
				anchors.fill: parent

				Text { id: userNameLabel
					text: qsTr("User Name")
					font.pixelSize: 14
					height: 30
					width: parent.width
				}

				TextField { id: userName
					font.pixelSize: 14
                    text: Qcn.userName
                    placeholderText: Qcn.userName
					height: 40
					width: parent.width
				}
			}
		}

		Item {
			width: 300
			height: downloadDirLabel.height + downloadDir.height + 50

			Column {
				anchors.fill: parent

				Text { id: downloadDirLabel
					text: qsTr("Default Download Directory")
					font.pixelSize: 14
					height: 40
					width: parent.width
				}

				Item { id: downloadDir
					width: parent.width
					height: 40

					TextField { id: downloadDirVal
						anchors.left: parent.left
						anchors.right: selectBtn.left
						height: parent.height
                        placeholderText: Qcn.downloadDir
						text: dirDialog.folder
					}

                    QcnButton { id: selectBtn
						anchors.right: parent.right
						iconFont: awesome.name
						radius: 0
						shadow: false
						icon: qsTr("\uf07b")
						onClicked: {
							dirDialog.open()
						}
					}
				}
			}

			FileDialog { id: dirDialog
				selectExisting: true
				selectFolder: true
                folder: "file://"+Qcn.downloadDir
			}
		}

		Item {
			width: 300
			height: colorThemeLabel.height + colorView.height + 50

			Column {
				anchors.fill: parent


				Text { id: colorThemeLabel
					text: qsTr("Color Theme")
					font.pixelSize: 14
					height: 40
					width: parent.width
				}

				Rectangle { id: colorView
					color: colorDialog.color
					width: 100
					height: 100

					Text { id: colorText
						anchors.centerIn: parent
						text: colorDialog.color
					}

					MouseArea{
						anchors.fill: parent
						onClicked: {
							colorDialog.open()
						}
					}
				}
			}

			ColorDialog { id: colorDialog
				currentColor: item.theme
				color: currentColor
			}
		}
	}

	Item { id: saveBtn
		width: 300
		height: 40
		anchors.bottom: parent.bottom

        QcnButton {
			icon: qsTr("\uf0c7")
			iconFont: awesome.name
			text: qsTr("Save")
			onClicked: {
                Qcn.userName = username;
                Qcn.downloadDir = ddir;
                Qcn.theme = themeColor
				item.updated()
			}
		}
	}
}
