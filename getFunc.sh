#!/bin/sh
echo $(basename $(ls /usr/share/man/man3 | sort -R | tail -n 1)) | cut -d. -f1