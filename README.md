**TCP-Bypass**

TCP-Bypass is used to bypass linux's tcp congestion control options in place of qdiscs (do no TCP congestion control and use qdiscs instead for QoS).

**How to use:**

Replace Kconfig, Makefile and tcp_bypass.c in the kernel source directory (linux-x.x.x/net/ipv4/)

Run make menuconfig in the root of the kernel source directory and select TCP-Bypass (CONFIG_TCP_CONG_BYPASS) under CONFIG_TCP_CONG_ADVANCED in Networking support>Networking options>TCP: advanced congestion control

**Patchfile:**

The patchfile will be the stable release version of TCP Bypass after extensive testing and 0 bugs are found while tcp_bypass.c will be the testing version (always being developed regardless of bugs).

**(Optional):** 

Also set net.ipv4.tcp_congestion_control = bypass

**TODO:**

1. Make patchfile (once its finalized).
