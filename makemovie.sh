#! /bin/bash

##
# Warning: this script isn't safe. it doesn't check before deleting/writing.
# Make sure you understand it before running it, or you may lose work.
#
# It is an ugly kludge, and would be far more efficient if we stayed in python
# instead of starting the interpreter every time.
##

rm frames.txt
rm *.png


items=`ls -1 ./antModel/*.xml | awk 'BEGIN { FS = "[/]+" }{print $3}'| grep -E "[0-9]+\.xml"|sort -n`




for item in $items ;do
    echo "=== Processing $item"
    ./view_one.py ./antModel/$item ./`echo $item | grep -Eo "[0-9]*"`.png
    echo ""
done

for item in $items ;do
    echo "`echo $item | grep -Eo "[0-9]*"`.png" >> frames.txt
done

mencoder 'mf://@frames.txt' -mf type=png:fps=5 -ovc lavc -lavcopts vcodec=wmv2 -oac copy -o animation.avi



