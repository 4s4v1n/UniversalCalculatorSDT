import QtQuick

import "../components"
import "../conversion.js" as Conversion

Item {
    id: root

    readonly property regexp memoryRegex: /^-?[0-9a-fA-F]+(\\.[0-9a-fA-F]+)?$/

    TopPanel {
        id: top_panel
        height: parent.height / 4

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
    }

    BottomPanel {
        id: bottom_panel
        height: parent.height / 4 * 3
        inputValue: top_panel.inputValue
        inputBase: top_panel.inputBase

        anchors {
            top: top_panel.bottom
            left: parent.left
            right: parent.right
        }

        onTextButtonClicked: (text) => {
            top_panel.numberLine.insert(inputValue.length, text)
        }

        onClearAllButtonClicked: () => {
            top_panel.inputValue  = ""

            Controller.clearAll()
        }

        onClearEntryButtonClicked: () => {
            top_panel.inputValue = top_panel.inputValue.slice(0, -1)
            Controller.clearEntry()
        }

        onCalculateButtonClicked: () => {                          
            top_panel.inputValue = Controller.calculate()
        }

        onMemoryClearClicked: {
            Controller.memoryClear()
        }

        onMemorySaveClicked: {
            if (top_panel.inputValue.match(memoryRegex)) {
                Controller.memorySave(top_panel.inputValue)
            }
        }

        onMemoryReadClicked: {
            top_panel.inputValue = Controller.memoryRead()
        }

        onMemoryAddClicked: {
            if (top_panel.inputValue.match(memoryRegex)) {
                Controller.memoryAdd(top_panel.inputValue)
            }
        }
    }
}
