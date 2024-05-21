import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import '../conversion.js' as Conversion

Rectangle {
    property alias inputValue: number_line.text
    property alias inputBase: base_spinbox.value
    property alias numberLine: number_line

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

    ColumnLayout {
        anchors.fill: parent

        spacing: 100

        TextInput {
            id: number_line

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignHCenter
            validator: RegularExpressionValidator {
                regularExpression: Conversion.regexFromBase(base_slider.value)
            }

            Layout.fillWidth: true
            Layout.fillHeight: true

            onTextChanged: {
                Controller.setExpression(text);
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
                    Controller.setBase(value)
                }

                Component.onCompleted: {
                    Controller.setBase(value)
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
                    Controller.setAccuracy(value)
                }

                Component.onCompleted: {
                    Controller.setAccuracy(value)
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
