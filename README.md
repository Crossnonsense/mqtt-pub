Надо открыть три терминала.

В первом:
mosquitto -p 1884 -v

Во втором:
mosquitto -p 1884 -t test/t1


В третьем: 
gcc publisher.cpp -o publisher -lmosquitto
./publisher