# msp430_OSX
This is a way to compile and burn C files on your msp430 microcontroller from Mac OS X

################################
## Install xcode and homebrew ##
################################
------------------------------
xcode-select --install

/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

brew update

------------------------------


###############################
## Install gcc and toolchain ##
###############################
------------------------------
brew tap sampsyo/mspgcc

brew install msp430-libc

brew install mspdebug

brew install git

git clone https://github.com/sampsyo/homebrew-mspgcc.git

cd homebrew-mspgcc

./addlinks.sh

------------------------------


########################
## Build libmsp430.so ##
########################
------------------------------
- Download MSP Debug Stack Developer's Package from http://www.ti.com/tool/mspds
- Unzip it on the Downloads directory

brew install boost

brew install hidapi

sudo cp -R /usr/local/Cellar/hidapi/0.8.0-rc1/include/hidapi/hidapi.h ~/Downloads/MSPDebugStack_OS_Package/ThirdParty/include

sudo cp -R /usr/local/Cellar/hidapi/0.8.0-rc1/lib/libhidapi.a ~/Downloads/MSPDebugStack_OS_Package/ThirdParty/lib64

cd ~/Downloads/MSPDebugStack_OS_Package

make STATIC=1

sudo make install

sudo mv /usr/local/lib/libmsp430.dylib /usr/local/lib/libmsp430.so


#############
## Testing ##
#############
------------------------------
- Download the files execute.sh and hello_msp.c from this source and connect your msp430

mspdebug tilib --allow-fw-update

sh execute.sh

# msp430_Linux
This is a way to compile and burn C files on your msp430 microcontroller from Linux

######################
## Install packages ##
######################
---------------------------------
sudo apt-get update

sudo apt-get install build-essential libusb-dev msp430-libc gcc-msp430 libreadline-dev git

----------------------------------

#######################
## Install LibMSP430 ##
#######################
----------------------------------
- Download from here libmsp430.so to your Downloads directory

cd ~/Downloads

git clone https://github.com/dlbeer/mspdebug.git

cd mspdebug/

make

sudo make install

sudo cp libmsp430.so /usr/lib

----------------------------------

##############################
## Update Firmware and test ##
##############################
----------------------------------
- Download the files execute.sh and hello_msp.c from this source and connect your msp430

mspdebug tilib -d /dev/ttyACM0 --allow-fw-update

sh execute.sh
