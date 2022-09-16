#!/bin/bash
if [ ! -d ".build" ]; then
    mkdir .build
fi
mv $1.tex .build
cd .build
pdflatex $1.tex
mv project.pdf $1.tex ..
