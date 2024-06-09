import QtQml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../conversion.js" as Conversion

Item {
    property string inputValue
    property int inputBase
    property string currentNumberType

    signal textButtonClicked(string text)
    signal clearEntryButtonClicked
    signal clearAllButtonClicked
    signal calculateButtonClicked
    signal memoryReadClicked
    signal memorySaveClicked
    signal memoryAddClicked
    signal memoryClearClicked
    signal numberTypeChanged(string numberType)

    id: root

    GridLayout {
        id: grid_layout
        columns: 4
        rows: 5
        rowSpacing: 20
        columnSpacing: 10
        anchors.fill: parent

        component BaseButton: Button {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width / parent.columns
            Layout.preferredHeight: parent.height / parent.rows
        }

        component TextButton: BaseButton {
            enabled: Conversion.hexCharacterToDecimal(this.text) < inputBase
                     && inputValue !== "0"

            onClicked: textButtonClicked(this.text)
        }

        component ActionButton: BaseButton {
            enabled: true
            palette.buttonText: "red"
        }

        component OperationButton: TextButton {
            enabled: true
            palette.buttonText: "blue"
        }

        ActionButton {
            id: memory_clear
            text: "MC"
            onClicked: {
                memoryClearClicked()
            }
        }

        ActionButton {
            id: memory_save
            text: "MS"
            onClicked: {
                memorySaveClicked()
            }
        }

        ActionButton {
            id: memory_read
            text: "MR"
            onClicked: {
                memoryReadClicked()
            }
        }

        ActionButton {
            id: memory_add
            text: "M+"
            onClicked: {
                memoryAddClicked()
            }
        }

        TextButton {
            id: button_0
            text: "0"
        }

        TextButton {
            id: button_1
            text: "1"
        }

        TextButton {
            id: button_2
            text: "2"
        }

        TextButton {
            id: button_3
            text: "3"
        }

        TextButton {
            id: button_4
            text: "4"
        }

        TextButton {
            id: button_5
            text: "5"
        }

        TextButton {
            id: button_6
            text: "6"
        }

        TextButton {
            id: button_7
            text: "7"
        }

        TextButton {
            id: button_8
            text: "8"
        }

        TextButton {
            id: button_9
            text: "9"
        }

        TextButton {
            id: button_a
            text: "A"
        }

        TextButton {
            id: button_b
            text: "B"
        }

        TextButton {
            id: button_c
            text: "C"
        }

        TextButton {
            id: button_d
            text: "D"
        }

        TextButton {
            id: button_e
            text: "E"
        }

        TextButton {
            id: button_f
            text: "F"
        }

        OperationButton {
            id: button_plus
            text: "+"
        }

        OperationButton {
            id: button_minus
            text: "-"
        }

        OperationButton {
            id: button_multiply
            text: "*"
        }

        OperationButton {
            id: button_divide
            text: "/"
        }

        OperationButton {
            id: button_rev
            text: "~"
        }

        OperationButton {
            id: button_sqrt
            text: "^"
        }

        TextButton {
            id: button_dot
            text: "."
            enabled: true
        }

        ActionButton {
            id: button_ac
            text: "AC"

            onClicked: clearAllButtonClicked()
        }

        ActionButton {
            id: button_ce
            text: "CE"

            onClicked: clearEntryButtonClicked()
        }

        ActionButton {
            id: button_calculate
            text: "="

            onClicked: calculateButtonClicked()
        }

        ComboBox {
            Layout.fillHeight: true
            Layout.fillWidth: true

            model: ListModel {
                ListElement {
                    text: "complexNumber"
                }
                ListElement {
                    text: "pNumber"
                }
                ListElement {
                    text: "fractionNumber"
                }
            }
            onCurrentTextChanged: {
                numberTypeChanged(currentText)
            }
        }
    }
}
