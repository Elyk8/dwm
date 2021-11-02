#!/bin/sh
sed -n '/Layout layouts/,/};/p' $HOME/.local/src/dwm/config.h |
  grep '^\s*{' |
  awk -F'[\"//]' '{print $2 " " $5 "\t\t" NR-1}' |
  sed -e 's/\[\\\\\]/\[\\\]/' \
    -e '$d' |
  xmenu
