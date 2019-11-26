#!/bin/bash

AUTO_ADDED_PACKAGES=$(apt-mark showauto)
apt-get remove --purge -y $BUILD_PACKAGES $AUTO_ADDED_PACKAGES
