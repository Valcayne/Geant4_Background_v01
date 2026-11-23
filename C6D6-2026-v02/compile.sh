#!/bin/bash
mkdir buildLocal
cd buildLocal
rm -r *
cmake ../
make
cd ../
