#! /bin/sh

# OPPGAVE 2

find -print | while read filename; do
    # do whatever you want with the file
    touch -t 201203101513 "$filename"
done

find ! \( -name "*.zip" -o -name "*.gz" \) -type f -mtime +7 -size +7k -execdir gzip {} \;
