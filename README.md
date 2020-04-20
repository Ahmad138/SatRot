#  SatRot - Taking Everyone to Space  :satellite:    :earth_africa:   :crescent_moon:   :telescope:   :space_invader: :stars:  :rocket:
[![Build Status](https://travis-ci.org/Ahmad138/SatRot.svg?branch=master)](https://travis-ci.org/Ahmad138/SatRot)
![Version](https://img.shields.io/badge/version-v1.0-yellowgreen)
[![GitHub issues](https://img.shields.io/github/issues/Ahmad138/SatRot)](https://github.com/Ahmad138/SatRot/issues)
![GitHub closed issues](https://img.shields.io/github/issues-closed-raw/ahmad138/satrot?color=red)
![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed/ahmad138/satrot?color=brown)
[![GitHub forks](https://img.shields.io/github/forks/Ahmad138/SatRot)](https://github.com/Ahmad138/SatRot/network)
[![GitHub stars](https://img.shields.io/github/stars/Ahmad138/SatRot?color=orange)](https://github.com/Ahmad138/SatRot/stargazers)
[![GitHub license](https://img.shields.io/github/license/Ahmad138/SatRot)](https://github.com/Ahmad138/SatRot/blob/master/LICENSE)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/ahmad138/satrot)
![GitHub repo size](https://img.shields.io/github/repo-size/ahmad138/satrot)
![Twitter Follow](https://img.shields.io/twitter/follow/sat_rot?style=social)

<p align="center">
<img src="https://github.com/Ahmad138/SatRot/blob/master/Documents/Images/Logo/SatRot%20logo.png?raw=true" width="20%" height="20%" alt="SatRot Logo">
</p>

# Table of Contents   :ledger:
-   [Motivation](#motivation)
-   [What is SatRot?](#what-is-satrot?)
-   [How SatRot works](#how-satrot-works)
    -   [Applications/Usefulness](#applications-usefulness)
-   [Who is SatRot for?](#who-is-satrot-for?)
-   [Requirements](#requirements)
    -   [Mechanical](#mechanical)
    -   [Electrical and Electronics](#electrical-and-electronics)
    -   [Software](#software)
        -   [Dependencies and Packages](#dependencies-and-packages)
        -   [Device and Operating System](#device-and-operating-system)
      -   [Telecom](#telecom)
-   [How to:](#how-to)
    -   [Build and install](#build-and-install)
    -   [Use](#use)
    -   [Maintain](#maintain)
-   [Screenshots](#screenshots)
-   [Examples and Videos](#examples-and-videos)
-   [Documentation](#documentation)
-   [Issue Tracking](#issue-tracking)
-   [Social Media @sat_rot](#social-media-@sat_rot)
-   [Authors](#authors)
-   [Support Us](#support-us)
-   [License](#license)

# <a name="motivation"></a>Motivation   :muscle:  :fire:
There has being alot of interest buzzing around ever since the space race started in 1955. Equipments and materials to communicate with satellites especially low earth orbit (LEO) satellites have being expensive and inaccessible. These satellites (both natural and artificial) move really fast across the sky. Hand tracking becomes tedious and tiring. Solar panels also need to follow the sun across the sky for 90&deg; incident rays so as to increase it's efficiency.

This is where **satRot** comes in. SatRot takes everyone interested into the domain of the amateur satellite observation or communication community. 

# What is SatRot?    :sparkles:
**SatRot** is a very cheap, modular and smart satellite rotator. It has the ability to automatically and manually control a load device such as an antenna for satellite communications, solar panel to track sun, telescope to observe patch of the night sky and others. The construction materials are so cheap and easy to build that high school students can DIY build the system.

The GUI has 2 main modes. A manual mode that a user can use to manually track a celestrial body using a mouse on the system. this provides a solid flexiblity for serach and observation of the sky. The second mode is the automatic mode. This mode allows the user to set a satellite to track whenever the satellite comes into view. This can be used to automatically transmit or receive information from satellite when it rises and before setting. This uses a kernal interrupt so as not to monopolize CPU resources. Ability to search and predict which and when satellites are coming over your location anywhere on earth.

# How SatRot works   :wrench:
<p align="center">
<img src="https://github.com/Ahmad138/SatRot/blob/master/Documents/Images/Block%20Diagrams/Satellite%20Rotator%20Block%20Diagram.jpg?raw=true" width="110%" >
</p>

## Applications/Usefulness
- Can be used to track fast moving satellites. Especially those in LEO with short fly by times.
- Solar panel can be mounted to track the sun and increase its efficiency
- Can be used as a teaching aid for young students about satellite technologies
- Telescope can be mounted on it and used to track a celestrial body in the sky
- Tracking the ISS and the activities on-board becomes possible 
- When Starlink becomes fully operational, SatRot could be used to gain internet access anywhere in the world.

# Who is SatRot for?  :heart_eyes:
**SatRot** is for anyone interested in the realm of satellite technology, telecommunications, amateur radio, application of raspberry pi. In short, anyone is free to join, use and participate in the SatRot project. 

# Requirements  :eyes:

### Mechanical  :nut_and_bolt:
The mechanical requirements are not much. Most of the parts will be printed using a 3D printer and few fastening bolts, nuts and screws. (N.B: due to the covid-19 issue the world is facing, we cannot access the workshops to complete the mechanical parts). Bellow are the few items required at the moment.

 - Access to 3D printing
 - M2.5 bolts and nuts
 - Brass or plastic spaces 
 - Tripod stand

see [wiki](https://github.com/Ahmad138/SatRot/wiki/Mechanical-Requirements) for full mechanical requirements.

### Electrical and Electronics  :pager:
We wanted to make satrot modular, portable and completely standalone. This required some components that need to provide adequate power and control. Below are some requirements. 

- A4988 stepper driver chips
 - MPU-9250
 - Nema17 2A stepper motors
 - 12V batteries

see [wiki](https://github.com/Ahmad138/SatRot/wiki/Mechanical-Requirements) for full EE reequirements. A soldering skill and basic circuit knowledge is also required.
### Software  :computer:
The main coding language is C/C++ and as such, a basic understanding of C/C++ is required. The software engineering heavily relies on a GUI development. Qt development package is the ideal package for a project like this. 

#### Dependencies and Packages
```bash
# C++14

- sudo apt-get install -qq g++-6
- sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90
- sudo apt-get --yes install qt5-default qt514-meta-full qt514tools qt514webengine qt514base qt514imageformats qt514svg libqt5webkit5-dev qt514charts-no-lgpl qt514xmlpatterns
- sudo apt-get install zlib1g-dev g++ cmake doxygen graphviz libboost-all-dev libssl-dev
# only on the raspberry pi
- sudo apt-get install wiringpi 
```
Proceed to the software development section on [wiki](https://github.com/Ahmad138/SatRot/wiki/Software-Requirements) for more info.
#### Device and Operating System
The device used for the project is a [raspberry pi 3 B](https://www.raspberrypi.org/products/raspberry-pi-3-model-b/ "raspberry pi 3 B") with the [raspbian](https://www.raspberrypi.org/downloads/raspbian/ "raspbian") (GNU/Linux) operating system installed on it.

### Telecom   :satellite:
This section requires majorly:

 - Custom antenna
 - RTL-SDR
 - RG58 50ohm cable
 - SMA connectors

more on [wiki](https://github.com/Ahmad138/SatRot/wiki/Telecommunication-Requirements)
# How to ...
### Build and install
```bash
git clone https://github.com/Ahmad138/SatRot.git

# To install main-GUI on ubuntu
cd satrot/Software/SatRot-GUI
mkdir build && cd build
qmake ..
make

sudo make install
cd GUI-Main
./GUI-Main

# To install RotorDriver-GUI on raspberrypi 3
cd satrot/Software/RotorDriver-GUI
mkdir build && cd build
qmake ..
make

sudo make install
cd RotorDriver
./RotorDriver

# To run tests, cd into each module test you want to perform and run it. for example:
cd build/apiTest
make check

```

NB: If you are facing issues building using 'make', look at this [issue](https://github.com/Ahmad138/SatRot/issues/61) and see if it applies to you. if not, open a new issue and ask for help.

### Use

### Maintain
Project maintenance will be performed by the creators and contributors. Anyone is free to join us in maintaining and growing this project.
# Screenshots
# Examples and Videos

# Documentation
A detailed documentation is outlined in the [wiki](https://github.com/Ahmad138/satRot/wiki "wiki") section of the repository. Files, documents, construction materials, instructions, costs and others are all listed and defined over in the [wiki](https://github.com/Ahmad138/satRot/wiki "wiki") section.

For the newbee nerds out there, checkout our [Doxygen](https://ahmad138.github.io/SatRot/ "Doxygen") docummentation for the software.

# Issue Tracking
If there is any issue or suggestions (including spelling/grammatical errors) to the development of the project, feel free to open an 'issue' on the [issue](https://github.com/Ahmad138/satRot/issues "issue") tab and properly define the issue. The problem will be rectified as soon as possible by the community.

# Social Media &#64;sat_rot
Like, Follow, Share to stay updated and help us grow the community.
<p align="center">
<a href="https://www.twitter.com/sat_rot" target="_blank">
<img src="https://github.com/Ahmad138/satRot/blob/master/Documents/Images/Logo/Social%20media/twitter.png?raw=true" width="10%"></a> <a href="https://www.facebook.com/SatRot-109843980689069" target="_blank"><img
src="https://github.com/Ahmad138/satRot/blob/master/Documents/Images/Logo/Social%20media/facebook.png?raw=true" width="10%"></a> <a href="https://www.instagram.com/sat_rot/" target="_blank"> <img src="https://github.com/Ahmad138/satRot/blob/master/Documents/Images/Logo/Social%20media/instagram.png?raw=true" width="10%"></a> <a href="https://www.youtube.com/channel/UCDHKf9GR-runCQVeQGb74Bw" target="_blank"> <img
src="https://github.com/Ahmad138/satRot/blob/master/Documents/Images/Logo/Social%20media/youtube.png?raw=true" width="10%"> </a> 

</p>

# Authors 
Ahmad Muhammad   :see_no_evil: :nerd_face:
:robot: [Github](https://github.com/Ahmad138 "Github") | :bird: [Twitter](https://twitter.com/ahmadmf01 "Twitter") |  :clown_face: [Facebook](http://www.facebook.com/amfaruk01 "Facebook")

Mohamed Salih :hear_no_evil: :sunglasses:
:robot: [Github](https://github.com/sonOFsalah-2425778 "Github") 

Mohamed Salim :see_no_evil:  :blush:
:robot: [Github](https://github.com/2302420a "Github")

See who did what [here](https://github.com/Ahmad138/SatRot/wiki/Team "Team")

# Support Us 
You can support us by sending us a thank you note or bringing someone into the vast world of satellite technology. Your support gives us boost to continue maintaining this project. Also give us a shout out whenever possible.  
# License 
 **The MIT License**
<p align="center">  
<img src="https://github.com/Ahmad138/satRot/blob/master/Documents/Images/Logo/OSIApproved.png?raw=true" width="10%" height="10%">
</p>

Copyright (c) 2020  - SatRot

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
