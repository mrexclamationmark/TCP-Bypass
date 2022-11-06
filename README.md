**TCP-Bypass**

TCP-Bypass is used to bypass linux's tcp congestion control algorithms in place of qdiscs (otherwords, use qdiscs instead).

**How to use:**

Replace Kconfig, Makefile and tcp_bypass.c in the kernel source directory (linux-x.x.x/net/ipv4/)

Run make menuconfig in the root of the kernel source directory and select TCP-Bypass (CONFIG_TCP_CONG_BYPASS) under CONFIG_TCP_CONG_ADVANCED in Networking support>Networking options>TCP: advanced congestion control

**(Optional)** 

Also set net.ipv4.tcp_congestion_control = bypass

**TODO**

1. Make patchfile

**Known Issues:**

None yet.
