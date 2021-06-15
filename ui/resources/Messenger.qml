import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import api.ui.qcn 2.0

Item { id: item

    property string theme: Qcn.theme
	property string textColor: "#333"
	property string bgColor: "#fff"

	FontLoader { id: awesome; source: "qrc:/resources/fontawesome-webfont.ttf" }

	Item { id: messageBox
		height: parent.height
		anchors.left: parent.left
		anchors.right: userListBox.left

		Rectangle { id: msgViewBox
			anchors.left: parent.left
			anchors.right: parent.right
			anchors.top: parent.top
			anchors.bottom: msgInputBox.top
			color: "#fff"
			anchors.bottomMargin: 20
			anchors.rightMargin: 20
			clip: true

			Component { id: msgDelegate

				Rectangle { id: msgWrapper
					//border.width: 1
					//border.color: item.theme
					anchors.margins: 5
					color: "#f9f9f9"
					height: userNameItem.height + messageItem.height
					width: userNameItem.width > messageItem.width ? userNameItem.width : messageItem.width
					radius: 5
					clip: true

					Component.onCompleted: {
						if(sent)
							anchors.right = parent.right
						else
							anchors.left = parent.left
					}

					Item { id:userNameItem
						anchors.top: parent.top
						anchors.left: parent.left
						height: userName.height + 20
						width: userName.width + 20
						clip: true

						Text { id: userName
							anchors.verticalCenter: parent.verticalCenter
							x: 10
							width: implicitWidth > msgViewBox.width*2/3 ? msgViewBox.width*2/3 : implicitWidth
							text: (sent? "To : " : "From : ") + "<b>" + user + "</b>"
							color: item.theme
							font.weight: Font.Bold
							font.pixelSize: 12
							wrapMode: Text.Wrap
						}
					}

					Item { id:messageItem
						anchors.top: userNameItem.bottom
						anchors.left: parent.left
						height: msgbody.height + 20
						width: msgbody.width + 20
						clip: true

						Text {
							id: msgbody
							anchors.verticalCenter: parent.verticalCenter
							x: 10
							width: implicitWidth > msgViewBox.width*2/3 ? msgViewBox.width*2/3 : implicitWidth
							text: message
							wrapMode: Text.Wrap
							color: "#333"
							font.pixelSize: 20
							font.weight: Font.Light
						}
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

				ListView { id:msgView
					anchors.fill: parent
					anchors.topMargin: 5
					delegate: msgDelegate
                    model: Qcn.messages
					spacing: 5
					currentIndex: count - 1
				}
			}
		}

		DropShadow { id: dropMsgViewBox
			anchors.fill: msgViewBox
			source: msgViewBox
			horizontalOffset: 0
			verticalOffset: 0
			radius: 7
			samples: 32
			color: "#20000000"
			transparentBorder: true
		}

		Rectangle { id:msgInputBox
			anchors.left: parent.left
			anchors.right: parent.right
			anchors.bottom: parent.bottom
			height: 40
			anchors.topMargin: 20
			anchors.rightMargin: 20
			color: "#fff"

			TextField { id:msgInput
				height: parent.height
				anchors.left: parent.left
				anchors.right: sendBtn.left
				font.pixelSize: 14

				style: TextFieldStyle {
					background: Rectangle{
						id:msgInputStyle
						color:"transparent"
					}
				}

				onAccepted:{
					if(userList.currentIndex >= 0)
					{
                        Qcn.sendMessage(text);
						text = ""
					}
				}

				onActiveFocusChanged: {
					if(activeFocus)
					{
						dropMsgInputBox.radius = 16
						msgInputBox.color = "#fff"
					}
					else
					{
						dropMsgInputBox.radius = 7
						msgInputBox.color = "#fcfcfc"
					}
				}
			}

			Rectangle { id: sendBtn
				width: parent.height
				height: parent.height
				anchors.right: parent.right
				color: item.bgColor

                QcnButton { id: sendBtnImage
					iconFont: awesome.name
					icon: "\uf1d8"
					shadow: false
					radius: 0
					anchors.centerIn: parent
				}

				MouseArea{
					anchors.fill: parent
					cursorShape: Qt.PointingHandCursor
					onClicked: {
						if(userList.currentIndex >= 0)
						{
                            Qcn.sendMessage(text);
							msgInput.text = ""
						}
					}
				}
			}
		}

		DropShadow { id: dropMsgInputBox
			anchors.fill: msgInputBox
			source: msgInputBox
			horizontalOffset: 0
			verticalOffset: 0
			radius: 7
			samples: 32
			color: "#20000000"
			transparentBorder: true
		}
	}

	Rectangle { id:userListBox
		height: parent.height
		anchors.right: parent.right
		anchors.leftMargin: 20
		width: 250
		color: "#fff"
		clip: true

		Component { id: userDelegate

			Item { id: wrapper
				width: parent.width
				height: 40

				property int idno : id

				Item { id:status
					width: parent.height
					height: parent.height
					visible: false

					Rectangle { id: statusLight
						height: parent.height/5
						width: parent.width/5
						anchors.centerIn: parent
						color: item.theme
						radius: width*0.5
					}
				}

				Text { id: user
					anchors.left: status.right
					anchors.right: parent.right
					anchors.verticalCenter: parent.verticalCenter
					text: name
					color: "#666"
				}

				states: State {
					name: "Current"
					when: wrapper.ListView.isCurrentItem
					PropertyChanges { target: status; visible: true }
					PropertyChanges { target: user; color: item.theme }
				}
				transitions: Transition {
					NumberAnimation { properties: "visible"; duration: 50 }
				}
				MouseArea {
					anchors.fill: parent
					onClicked: {
						wrapper.ListView.view.currentIndex = index
					}
				}
			}
		}

		Component { id: highlightBar

			Rectangle{
				width: userList.width;
				height: 40
				y: userList.currentItem.y;
				Behavior on y { NumberAnimation { duration: 50 } }
				color: "#fff"
			}
		}

		ScrollView{
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

			ListView { id:userList
				anchors.fill: parent
                model: Qcn.users
				delegate: userDelegate
				highlight: highlightBar
				highlightFollowsCurrentItem: false
                onCurrentIndexChanged: Qcn.selectedUser = currentIndex > -1 ? currentItem.idno : -1
			}
		}
	}

	DropShadow { id: dropUserListBox
		anchors.fill: userListBox
		source: userListBox
		horizontalOffset: 0
		verticalOffset: 0
		radius: 7
		samples: 32
		color: "#20000000"
		transparentBorder: true
	}
}
