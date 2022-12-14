**TCP-Bypass**

TCP-Bypass is used to bypass linux's tcp congestion control options (do no TCP congestion control and use qdiscs or minstrel instead for QoS).

**How to use:**

Replace Kconfig, Makefile and tcp_bypass.c in the kernel source directory (linux-x.x.x/net/ipv4/).

Run make menuconfig in the root of the kernel source directory and select TCP-Bypass (CONFIG_TCP_CONG_BYPASS) under CONFIG_TCP_CONG_ADVANCED in Networking support>Networking options>TCP: advanced congestion control

Also set net.ipv4.tcp_congestion_control = bypass

**tcp_bypass.patch**

Version: linux-6.1

Copy the patchfile to your main kernel source directory and run "patch -p1 < tcp_bypass.patch"

**tcp_bypass_debug.patch**

This is a debug patchfile to see how many times a function is called (this was used to reorder the structs based on how many times the function was called in order to optimize it).

Copy the patchfile to your main kernel source directory and run "patch -p1 < tcp_bypass_debug.patch"

**Known Issues:**

None
