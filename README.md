**TCP-Bypass**

TCP-Bypass is used to bypass linux's tcp congestion control algorithms in place of qdiscs.

**How to use:**

Replace Kconfig, Makefile and tcp_bypass.c in the kernel source directory (linux-x.x.x/net/ipv4/)

Run make menuconfig and select TCP-Bypass (CONFIG_TCP_CONG_BYPASS) under CONFIG_TCP_CONG_ADVANCED in Networking support>Networking options>TCP: advanced congestion control

**(Optional)** 

Also set net.ipv4.tcp_congestion_control = bypass

**TODO**

1. Make patchfile

2. Replace function tcp_reno_undo_cwnd with something simpler (for now it is needed for bypass to show up in net.ipv4.tcp_avaliable_congestion_control).
