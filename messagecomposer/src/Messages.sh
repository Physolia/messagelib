#! /bin/sh
# SPDX-License-Identifier: CC0-1.0
# SPDX-FileCopyrightText: none
$EXTRACTRC `find . -name '*.ui' -or -name '*.rc' -or -name '*.kcfg' -or -name '*.kcfg.cmake'` >> rc.cpp || exit 11
$XGETTEXT `find . -name '*.cpp' | grep -v '/autotests/' | grep -v '/tests/'` -o $podir/libmessagecomposer.pot
rm -f rc.cpp
