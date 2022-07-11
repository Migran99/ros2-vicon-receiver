#!/bin/sh
echo "Installing shared libraries, please wait"
sudo cp DataStreamSDK_10.1/libViconDataStreamSDK_CPP.so /usr/lib
echo "."
sudo cp DataStreamSDK_10.1/libboost_system.so.1.68.0 /usr/lib
echo "."
sudo cp DataStreamSDK_10.1/libboost_thread.so.1.68.0 /usr/lib
echo "."
sudo cp DataStreamSDK_10.1/libboost_timer.so.1.68.0 /usr/lib
echo "."
sudo cp DataStreamSDK_10.1/libboost_chrono.so.1.68.0 /usr/lib
echo "."
sudo chmod 0755 /usr/lib/libViconDataStreamSDK_CPP.so /usr/lib/libboost_system.so.1.68.0 /usr/lib/libboost_thread.so.1.68.0 /usr/lib/libboost_timer.so.1.68.0 /usr/lib/libboost_chrono.so.1.68.0
echo "." 
sudo ldconfig
echo "."
echo "Installlation finished"

