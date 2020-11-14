#!/bin/sh
echo $(basename $(ls /usr/share/man/man3 | grep -e "[a-zA-Z0-9\_]" | sort -R | tail -n 1)) | cut -d. -f1