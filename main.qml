import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtMultimedia 5.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Praise Pads"

    // Add Audio element
    Audio {
        id: padAudio
        source: "a_warm_churchfront_pads.mp3"
        loops: Audio.Infinite
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20

        // Grid of chord pads
        Grid {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: Math.min(parent.width, parent.height * 0.8)
            columns: 4
            spacing: Math.min(parent.width, parent.height) * 0.02

            Repeater {
                model: 12
                delegate: Rectangle {
                    width: (parent.width - parent.spacing * 3) / 4
                    height: (parent.height - parent.spacing * 2) / 3
                    color: "transparent"

                    Button {
                        anchors.fill: parent
                        anchors.margins: parent.height * 0.05
                        text: "Chord " + (index + 1)
                        
                        background: Rectangle {
                            color: parent.pressed ? Qt.darker(getChordColor(index), 1.2) : getChordColor(index)
                            radius: height * 0.1
                        }

                        // Update first pad to use Audio element
                        onPressed: {
                            if (index === 0) {
                                padAudio.play()
                            } else {
                                audioController.playChord(index)
                            }
                        }
                        onReleased: {
                            if (index === 0) {
                                padAudio.stop()
                            } else {
                                audioController.stopChord(index)
                            }
                        }
                    }
                }
            }
        }

        // Controls
        RowLayout {
            Layout.fillWidth: true
            spacing: 20

            Label {
                text: "Fade Speed:"
            }

            Slider {
                id: fadeSpeedSlider
                from: 0.1
                to: 2.0
                value: 0.5
                //onValueChanged: audioController.setFadeSpeed(value)
            }

            Label {
                text: "Loop Overlap:"
            }

            Slider {
                id: loopOverlapSlider
                from: 0
                to: 2.0
                value: 1.0
                //onValueChanged: audioController.setLoopOverlap(value)
            }
        }
    }

    // Function to generate colors for the chord pads
    function getChordColor(index) {
        const colors = [
            "#FF6B6B", "#4ECDC4", "#45B7D1", "#96CEB4",
            "#FFEEAD", "#D4A5A5", "#9B59B6", "#3498DB",
            "#E74C3C", "#2ECC71", "#F1C40F", "#1ABC9C"
        ]
        return colors[index]
    }
} 