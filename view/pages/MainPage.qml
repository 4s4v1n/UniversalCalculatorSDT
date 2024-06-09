import QtQuick

import "../components"
import "../conversion.js" as Conversion

Item {
    id: root

    property regexp memoryRegex: /^-?[0-9a-fA-F]+(\\.[0-9a-fA-F]+)?$/

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

        onTextButtonClicked: {
            top_panel.numberLine.insert(inputValue.length, text)
        }

        onClearAllButtonClicked: {
            top_panel.inputValue = ""

            switch (currentNumberType) {
            case "complexNumber":
                complexNumberController.clearAll()
                break
            case "fractionNumber":
                fractionNumberController.clearAll()
                break
            case "pNumber":
                pNumberController.clearAll()
                break
            }
        }

        onClearEntryButtonClicked: {
            top_panel.inputValue = top_panel.inputValue.slice(0, -1)

            switch (currentNumberType) {
            case "complexNumber":
                complexNumberController.clearEntry()
                break
            case "fractionNumber":
                fractionNumberController.clearEntry()
                break
            case "pNumber":
                pNumberController.clearEntry()
                break
            }
        }

        onCalculateButtonClicked: {
            switch (currentNumberType) {
            case "complexNumber":
                top_panel.inputValue = complexNumberController.calculate()
                break
            case "fractionNumber":
                top_panel.inputValue = fractionNumberController.calculate()
                break
            case "pNumber":
                top_panel.inputValue = pNumberController.calculate()
                break
            }
        }

        onMemoryClearClicked: {
            switch (currentNumberType) {
            case "complexNumber":
                complexNumberController.memoryClear()
                break
            case "fractionNumber":
                fractionNumberController.memoryClear()
                break
            case "pNumber":
                pNumberController.memoryClear()
                break
            }
        }

        onMemorySaveClicked: {
            if (!top_panel.inputValue.match(memoryRegex)) {
                return;
            }

            switch (currentNumberType) {
            case "complexNumber":
                complexNumberController.memorySave(top_panel.inputValue);
                break
            case "fractionNumber":
                fractionNumberController.memorySave(top_panel.inputValue);
                break
            case "pNumber":
                pNumberController.memorySave(top_panel.inputValue);
                break
            }
        }

        onMemoryReadClicked: {
            switch (currentNumberType) {
            case "complexNumber":
                top_panel.inputValue = complexNumberController.memoryRead()
                break
            case "fractionNumber":
                top_panel.inputValue = fractionNumberController.memoryRead()
                break
            case "pNumber":
                top_panel.inputValue = pNumberController.memoryRead()
                break
            }
        }

        onMemoryAddClicked: {
            if (top_panel.inputValue.match(memoryRegex)) {
                switch (currentNumberType) {
                case "complexNumber":
                    complexNumberController.memoryAdd(top_panel.inputValue)
                    break
                case "fractionNumber":
                    fractionNumberController.memoryAdd(top_panel.inputValue)
                    break
                case "pNumber":
                    pNumberController.memoryAdd(top_panel.inputValue)
                    break
                }
            }
        }

        onNumberTypeChanged: (numberType) => {
            currentNumberType = numberType
            top_panel.numberType = numberType

            if (numberType === "pNumber") {
                top_panel.enableControls()
            } else {
                top_panel.disableControls()
            }

            if (numberType === "pNumber") {
                memoryRegex = /^-?[0-9a-fA-F]+(\\.[0-9a-fA-F]+)?$/
            } else if (numberType === "complexNumber") {
                memoryRegex = /^\(([-+]?\d*\.?\d+)([-+]\d*\.?\d+)i\)$/
            } else {
                memoryRegex = /^-?[0-9]+?\/[0-9]+$/
            }
        }
    }
}
