/* SPDX-License-Identifier: GPL-2.0-only
* mrexclamationmarks TCP bypass
* TCP bypass is a congestion control bypass for linux.
* using qdiscs is better than congestion control algorithms. */

#include <linux/module.h>
#include <net/tcp.h>

/* tcp_congestion_ops function calls. */

void tcp_bypass_ssthresh(void) {
}

void tcp_bypass_cong_avoid(void) {
}

void tcp_bypass_set_state(void) {
}

void tcp_bypass_cwnd_event(void) {
}

void tcp_bypass_in_ack_event(void) {
}

void tcp_bypass_pkts_acked(void) {
}

void tcp_bypass_cong_control(void) {
}

/* tcp_bypass_undo_cwnd needs to return something */

u32 tcp_bypass_undo_cwnd(struct sock *sk) {

const struct tcp_sock *tp = tcp_sk(sk);

return tcp_snd_cwnd(tcp_sk(sk));
}

void tcp_bypass_sndbuf_expand(void) {
}

void tcp_bypass_get_info(void) {
}

void tcp_bypass_init(void) {
}

void tcp_bypass_release(void) {
}

static struct tcp_congestion_ops tcp_bypass __read_mostly = {
	.ssthresh	= tcp_bypass_ssthresh,
	.cong_avoid	= tcp_bypass_cong_avoid,
	.set_state	= tcp_bypass_set_state,
	.cwnd_event	= tcp_bypass_cwnd_event,
	.in_ack_event	= tcp_bypass_in_ack_event,
	.pkts_acked	= tcp_bypass_pkts_acked,
	.cong_control   = tcp_bypass_cong_control,
	.undo_cwnd	= tcp_bypass_undo_cwnd,
	.sndbuf_expand	= tcp_bypass_sndbuf_expand,
	.get_info	= tcp_bypass_get_info,
	.init		= tcp_bypass_init,
	.release	= tcp_bypass_release,
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
