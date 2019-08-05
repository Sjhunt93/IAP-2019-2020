# Unit Tests

This document outlines each of the unit tests and details the expected inputs and outcomes for each specific test


# Overview

The Aserve unit tester is a small application embeded inside Aserve that remotely sends messages to your IAP project and expects to receive a set list of messages in return.

A unit test is normal software development is test designed to validate some code inside the software that performs a specific task.

# Setup

To view the unit test pannel in Aserve select it from the dropdown menu (it is hidden by default).

<img src="Images/aserveunitmenu.png" />

Once open you should see the unit test pannel appear on the right hand side.

<img src="Images/unittests.png" />

# Description

Each of the tests are listed in the scrolling menu, the coloured circle depicts the current state of each test. Red means the test failed, orange means the test is currently running and green means the test has passed. To run a test simply select it from the menu and then hit the *Run Selected Test* button. Error messages will be shown in the text box below.

# Saving

Once a test has been run the solution to the test will be copied from your Xcode project to the Solutions/Unit Tests folder inside your project folder. The files are prepended with *Failed* if the test fails or *Pass* if they pass. When re-opening Aserve, this folder is scanned and the interface updates accordingly, keeping track of each test. It is important that you **do not** manually edit the files in this folder. You should ensure that you keep a backup copy of each unit test that has passed inside codebook.

<img src="Images/unittestfiles.png"/>

## File paths

There may be occasions where you need to specify the location of your project and Solutions folder. To do this open settings -> unit test setup (from the dropdown menu). **However you should speak to a member of staff before changing any of the settings - as the project should be setup automatically for you.**



# The Tests

The table bellow outlines each test and the tutorial exercise they correspond to.





| Number | Unit Test Name | Exercise Number | Exercise Name |
| --- | --- | --- | --- |
| 1 | Midi Note to Frequency | 3.3 | <a href="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/Part%201/3%20-%20Processing%20MIDI%20Input.md">Our first monophonic synthesizer</a> |
| 2 | Drum Sampler | 4.4 |  <a href="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/Part%201/4%20-%20Flow%20Control.md">Fixing the drum sampler </a> |
| 3 | Chord Machine | 5.3 | <a href="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/Part%201/5%20-%20Functions.md">Chord Machine </a> |
| 4 | Fix noteoff | 6.4 | noteoff |


# Test 4: Fix noteoff
*Tests: <a href="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/Part%201/6%20-%20Functions%20II.md">Exercise 6.4</a>*

This unit test tests that you have correctly implemented the expected behaviour for note off messages for a monophonic synthesiser. The oscillator should always play note on messages when received but only switch off when the note number of a note off messages matches the frequency of the oscillator that is currently playing.

| # | Input From Aserve | Output expected from project |
| --- | --- | --- |
| 1 | Note on MIDI message a | Switch on Oscillator 0 with correct frequency and amplitude | 
| 2 | Note on MIDI message b | Update Oscillator 0 with correct frequency and amplitude | 
| 3 | Note off MIDI message a | Nothing as oscillator is playing note b |
| 4 | note off MIDI message b | Switch off Oscillator 0 as note off number matches the playing oscillator |



