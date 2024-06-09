import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import '../conversion.js' as Conversion

Rectangle {
    property alias inputValue: number_line.text
    property alias inputBase: base_spinbox.value
    property alias numberLine: number_line
    property string numberType

    function disableControls() {
       base_spinbox.enabled = false
       base_slider.enabled = false
       accuracy_spinbox.enabled = false
       accuracy_slider.enabled = false
    }

    function enableControls() {
        base_spinbox.enabled = true
        base_slider.enabled = true
        accuracy_spinbox.enabled = true
        accuracy_slider.enabled = true
    }

    signal outputBaseValueChanged()

    component CalculatorText : Text {
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignHCenter

        Layout.fillHeight: true
        Layout.fillWidth: true
    }

    component CalculatorSpinBox : SpinBox {
        Layout.fillWidth: true
    }

    component CalculatorSlider: Slider {
        snapMode: Slider.SnapAlways
        Layout.fillWidth: true
    }

    onNumberTypeChanged: {
        number_line.text = ""
    }

    ColumnLayout {
        anchors.fill: parent

        spacing: 100

        TextInput {
            id: number_line

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignHCenter
            validator: RegularExpressionValidator {
                regularExpression: {
                    if (numberType === "pNumber") {
                        return Conversion.regexFromBase(base_slider.value)
                    } else if (numberType === "fractionNumber") {
                        return Conversion.regexFraction
                    } else {
                        return Conversion.regexComplex
                    }
                }
            }

            Layout.fillWidth: true
            Layout.fillHeight: true

            onTextChanged: {
                switch (numberType) {
                case "pNumber":
                    pNumberController.setExpression(text);
                    break;
                case "fractionNumber":
                    fractionNumberController.setExpression(text);
                    break;
                case "complexNumber":
                    complexNumberController.setExpression(text);
                    break;
                }
            }
        }

        GridLayout {
            rows: 2
            columns: 3

            Layout.fillWidth: true
            Layout.fillHeight: true

            CalculatorText {
                id: base_label
                text: qsTr("Основание")
            }

            CalculatorSpinBox {
                id: base_spinbox
                from: 2
                to: 16
                value: 2

                onValueChanged: {
                    base_slider.value = value
                    pNumberController.setBase(value)
                }

                Component.onCompleted: {
                    pNumberController.setBase(value)
                }
            }

            CalculatorSlider {
                id: base_slider
                from: 2
                to: 16
                stepSize: 1
                snapMode: Slider.SnapAlways

                onValueChanged: {
                    base_spinbox.value = value
                }
            }

            CalculatorText {
                id: accuracy_label
                text: qsTr("Точность")
            }

            CalculatorSpinBox {
                id: accuracy_spinbox
                from: 0
                to: 8
                value: 0

                onValueChanged: {
                    accuracy_slider.value = value
                    pNumberController.setAccuracy(value)
                }

                Component.onCompleted: {
                    pNumberController.setAccuracy(value)
                }
            }

            CalculatorSlider {
                id: accuracy_slider
                from: 0
                to: 8
                stepSize: 1

                onValueChanged: {
                    accuracy_spinbox.value = value
                }
            }
        }
    }
}
