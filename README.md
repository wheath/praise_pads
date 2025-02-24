# praise_pads
Allows musicians to add chord synths between songs

## Requirements
- Qt Quick
- Qt Multimedia
- C++17
- CMake

## Overview
- Simple grid of 12 chords.  
- Plays 12 different audio loops.
- allow user to set sound files associated with each chord
- fade smoothly from one to the next when pressing next chord (volume linearly decays on one while it linearly increases on the other)
- control fade speed between chords
- control fade speed in and out when just activating and deactivating
- control loop overlap, e.g, 1 sec means the audio starts replaying from the beginning 1 sec before the current playback terminates, linearly transitioning volume between current and next iteration

## Interface Design
- 3 x 4 grid of colored rounded buttons with optional text labels
- buttons to control the number of audio loops to play
- Button to control fade speed between chords


