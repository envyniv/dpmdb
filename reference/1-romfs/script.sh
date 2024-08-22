#!/usr/bin/env bash
for f in romfs/*/*/*.zip; do
    unzip $f '*.bin' -d casestudy/_$(dirname $(dirname $f))
done
