#!/bin/bash

esy dune build &&
esy dune build executable/IrminWebApp.re &&
esy dune build executable/IrminWebApp.bc &&
esy buildjs &&
JSFILE=./_esy/default/store/b/irmin_web-f98e1975/default/executable/IrminWebApp.js
cp $JSFILE ~/public/. &&
node $JSFILE