#!/bin/sh
LD_LIBRARY_PATH=/usr/lib/arm-linux-gnueabihf${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/usr/lib/arm-linux-gnueabihf/qt5/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
