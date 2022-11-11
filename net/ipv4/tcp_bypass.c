/* SPDX-License-Identifier: GPL-2.0-only
 mrexclamationmarks TCP bypass
 TCP bypass is a congestion control bypass for linux.
 using qdiscs is better than congestion control algorithms. */

#include <linux/module.h>
#include <net/tcp.h>

/* tcp_congestion_ops function calls. */

static inline u32 tcp_bypass_ssthresh(struct sock *sk) {

	const struct tcp_sock *tp = tcp_sk(sk);

	return min_t(u32, tp->snd_ssthresh, 0);
}

static inline void tcp_bypass_cong_avoid(struct sock *sk, u32 ack, u32 acked) {
}

static inline void tcp_bypass_set_state(struct sock *sk, u8 new_state) {
}

static inline void tcp_bypass_cwnd_event(struct sock *sk, enum tcp_ca_event ev) {
}

static inline void tcp_bypass_in_ack_event(struct sock *sk, u32 flags) {
}

static inline void tcp_bypass_pkts_acked(struct sock *sk, const struct ack_sample *sample) {
}

static inline void tcp_bypass_cong_control(struct sock *sk, const struct rate_sample *rs) {
}

static inline u32 tcp_bypass_undo_cwnd(struct sock *sk) {

	const struct tcp_sock *tp = tcp_sk(sk);

	return max_t(u32, tp->snd_cwnd, 0);
}

static inline u32 tcp_bypass_sndbuf_expand(struct sock *sk) {

	return 0;
}

static inline size_t tcp_bypass_get_info(struct sock *sk, u32 ext, int *attr, union tcp_cc_info *info) {

	return 0;
}

static inline void tcp_bypass_init(struct sock *sk) {
}

static inline void tcp_bypass_release(struct sock *sk) {
}

static struct tcp_congestion_ops tcp_bypass __read_mostly = {
	.flags		= TCP_CONG_NON_RESTRICTED,
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

inline int __init tcp_bypass_register(void)
{
	return tcp_register_congestion_control(&tcp_bypass);
}

inline void __exit tcp_bypass_unregister(void)
{
	tcp_unregister_congestion_control(&tcp_bypass);
}

module_init(tcp_bypass_register);
module_exit(tcp_bypass_unregister);

MODULE_AUTHOR("mrexclamationmark");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("TCP Bypass");
