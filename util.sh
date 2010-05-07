#! /bin/bash

##
# Warning: this script isn't safe. it doesn't check before deleting/writing.
# Make sure you understand it before running it, or you may lose work.
#
##

option=$1
arg=$2

ITER=100


XPARSER_LOC=/home/brice/files/uni/COM3001/Mike/xparser_1.0/xparser
MODEL_DIR=/home/brice/files/uni/COM3001/Mike/com3001/antModel/
MODEL_XML=/home/brice/files/uni/COM3001/Mike/com3001/antModel/antModel.xml
WORKING_DIR=/home/brice/files/uni/COM3001/Mike/com3001/working/
FRAME_MAKER=/home/brice/files/uni/COM3001/Mike/com3001/make_frames2.py
MBOARD_DIR=/home/brice/files/uni/COM3001/Mike/libmboard

function usage {
    echo "util.sh (option)

where option is one of:
    --cleanbuild            Cleans the Xparser generated files from the model 
                            directory
    
    --make-movie                 Makes a movie from the generated xml files.

    --run [num]             Runs the simulation. Must specify a number of 
                            iterations to run.
    
    --frames                Creates the frames from the xml files without 
                            making the movie
    
    --movie                 Makes the movie without first generating the frames
    
    --build                 Build an executable from the model.
    
    --cleanrun              Cleans generated .xml and .png files
    
    --clean-run-movie [num] Does everything at once, cleans, builds, runs the 
                            simulation and then makes a movie.
                            
    -h --help               Shows this usage message
    "
}

function movie-only {
    echo "== Making Movie from existing frames"
    #move to where they are
    cd $WORKING_DIR

    #make ordered list 
    ls -1 | grep -E "[0-9]+\.png"|sort -n > frames.txt

    #encode into a movie
    mencoder 'mf://@frames.txt' -mf type=png:fps=5 -ovc lavc -lavcopts vcodec=wmv2 -oac copy -o movie.avi
}

function frames-only {
    echo "== Making frames"
    #make the frames
    $FRAME_MAKER $WORKING_DIR $WORKING_DIR
}

function make-movie {
    echo "== Making frames and encodeing movie"
    frames-only
    movie-only
}

function cleanrun {
    echo "== Cleaning Run data"
    
    cd $WORKING_DIR
    find ./ -name "[0-9]*.xml" ! -name "0.xml" -exec rm {} \;
    find ./ -name "[0-9]*.png" -exec rm {} \; 
    rm frames.txt
}

function build {
    echo "== Building executable"
    $XPARSER_LOC $MODEL_XML
    cd $MODEL_DIR
    pwd
    make LIBMBOARD_DIR=$MBOARD_DIR
}

function cleanbuild {
    echo "== Cleaning Build Files"
    cd $MODEL_DIR
    ls -1 > ALLFILES
    sort MANIFEST MANIFEST ALLFILES| uniq -u | xargs rm
}

function runsim {
    echo "== Running simulation"
    cd $MODEL_DIR
    cp 0.xml $WORKING_DIR
    echo $arg
    if [[ $arg ]]; then
        ./main $arg ${WORKING_DIR}0.xml
    else
        usage
        exit
    fi
}

case "$1" in
    "--cleanbuild")  
        cleanbuild
        ;;
    "--frames")
        frames-only
        ;;
    "--make-movie")
        make-movie
        ;;
    "--movie")
        movie-only
        ;;
    "--run")
        runsim
        ;;
    "--build")
        build
        ;;
    "--cleanrun")
        cleanrun
        ;;
    "--do-all")
        cleanrun
        cleanbuild
        build
        runsim
        make-movie
        ;;
    "-h"|"--help")
        usage
        ;;
    *)
        usage
        ;;
esac
    
    
    
    
    
    
    
