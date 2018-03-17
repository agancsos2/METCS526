#!/bin/bash
APP_ROOT=$(dirname "$0")
##echo $APP_ROOT
g++ $APP_ROOT/*.cpp \
	$APP_ROOT/amgCommon/*.cpp \
    $APP_ROOT/amgArtwork/*.cpp \
	-o $APP_ROOT/../bin/Gancsos_Abel_HW1
