sudo ip link set can0 type can bitrate 1000000
sudo ip link set can0 up
sudo ifconfig can0 txqueuelen 10000

sleep 0.5

dmesg | fgrep -i becomes
