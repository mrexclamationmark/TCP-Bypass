/* SPDX-License-Identifier: GPL-2.0-only
* mrexclamationmarks TCP bypass
* TCP bypass is a congestion control bypass for linux.
* using qdiscs is better than congestion control algorithms.
*/

#include <linux/module.h>
#include <net/tcp.h>

void tcp_bypass_cong_control(void){
return;
}

void tcp_bypass_cong_avoid(void) {
return;
}

void tcp_bypass_undo_cwnd(void) {
return;
}

void tcp_bypass_ssthresh(void) {
return;
}

static struct tcp_congestion_ops tcp_bypass __read_mostly = {
	.ssthresh	= tcp_bypass_ssthresh,
	.undo_cwnd	= tcp_bypass_undo_cwnd,
	.cong_avoid	= tcp_bypass_cong_avoid,
	.cong_control   = tcp_bypass_cong_control,
	.owner		= THIS_MODULE,
	.name		= "bypass",
};

static int __init tcp_bypass_register(void)
{
	return tcp_register_congestion_control(&tcp_bypass);
}

static void __exit tcp_bypass_unregister(void)
{
	tcp_unregister_congestion_control(&tcp_bypass);
}

module_init(tcp_bypass_register);
module_exit(tcp_bypass_unregister);

MODULE_AUTHOR("mrexclamationmark");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("TCP Bypass");
