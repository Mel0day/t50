/*
 *  T50 - Experimental Mixed Packet Injector
 *
 *  Copyright (C) 2010 - 2014 - T50 developers
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <common.h>

void show_version(void)
{
  printf("T50 Experimental Mixed Packet Injector Tool %s\n"
         "Originally created by Nelson Brito <nbrito@sekure.org>\n"
         "Maintained by Fernando Mercês <fernando@mentebinaria.com.br>\n",
         VERSION);
}

/* Help and usage message */
void usage(void)
{
  show_version();

  printf("\n"
         "Usage: t50 <host>[/CIDR] [options]\n\n"

         "Common Options:\n"
         "    --threshold NUM           Threshold of packets to send     (default 1000)\n"
         "    --flood                   This option supersedes the \'threshold\'\n"
         "    --encapsulated            Encapsulated protocol (GRE)      (default OFF)\n"
         " -B,--bogus-csum              Bogus checksum                   (default OFF)\n"
#ifdef  __HAVE_TURBO__
  			"    --turbo                   Extend the performance           (default OFF)\n"
#endif  /* __HAVE_TURBO__ */
        " -v,--version                 Print version and exit \n"
  			" -h,--help                    Display this help and exit\n\n"
         "GRE Options:\n"
         "    --gre-seq-present         GRE sequence # present           (default OFF)\n"
         "    --gre-key-present         GRE key present                  (default OFF)\n"
         "    --gre-sum-present         GRE checksum present             (default OFF)\n"
         "    --gre-key NUM             GRE key                          (default RANDOM)\n"
         "    --gre-sequence NUM        GRE sequence #                   (default RANDOM)\n"
         "    --gre-saddr ADDR          GRE IP source IP address         (default RANDOM)\n"
         "    --gre-daddr ADDR          GRE IP destination IP address    (default RANDOM)\n\n"
         "DCCP/TCP/UDP Options:\n"
         "    --sport NUM               DCCP|TCP|UDP source port         (default RANDOM)\n"
         "    --dport NUM               DCCP|TCP|UDP destination port    (default RANDOM)\n\n"
         "IP Options:\n"
         " -s,--saddr ADDR              IP source IP address             (default RANDOM)\n"
         "    --tos NUM                 IP type of service               (default 0x%x)\n"
         "    --id NUM                  IP identification                (default RANDOM)\n"
         "    --frag-offset NUM         IP fragmentation offset          (default 0)\n"
         "    --ttl NUM                 IP time to live                  (default 255)\n"
         "    --protocol PROTO          IP protocol                      (default TCP)\n\n",
         IPTOS_PREC_IMMEDIATE);

  /* FIXME: Future call: icmp_usage(); */
  printf("ICMP Options:\n"
         "    --icmp-type NUM           ICMP type                        (default %d)\n"
         "    --icmp-code NUM           ICMP code                        (default 0)\n"
         "    --icmp-gateway ADDR       ICMP redirect gateway            (default RANDOM)\n"
         "    --icmp-id NUM             ICMP identification              (default RANDOM)\n"
         "    --icmp-sequence NUM       ICMP sequence #                  (default RANDOM)\n\n",
         ICMP_ECHO);

  /* FIXME: Future call: igmp_usage(); */
  printf("IGMP Options:\n"
         "    --igmp-type NUM           IGMPv1/v3 type                   (default 0x%x)\n"
         "    --igmp-code NUM           IGMPv1/v3 code                   (default 0)\n"
         "    --igmp-group ADDR         IGMPv1/v3 address                (default RANDOM)\n"
         "    --igmp-qrv NUM            IGMPv3 QRV                       (default RANDOM)\n"
         "    --igmp-suppress           IGMPv3 suppress router-side      (default OFF)\n"
         "    --igmp-qqic NUM           IGMPv3 QQIC                      (default RANDOM)\n"
         "    --igmp-grec-type NUM      IGMPv3 group record type         (default 1)\n"
         "    --igmp-sources NUM        IGMPv3 # of sources              (default 2)\n"
         "    --igmp-multicast ADDR     IGMPv3 group record multicast    (default RANDOM)\n"
         "    --igmp-address ADDR,...   IGMPv3 source address(es)        (default RANDOM)\n\n",
         IGMP_HOST_MEMBERSHIP_QUERY);

  /* FIXME: Future call: tcp_usage(); */
  printf("TCP Options:\n"
         "    --acknowledge NUM         TCP ACK sequence #               (default RANDOM)\n"
         "    --sequence NUM            TCP SYN sequence #               (default RANDOM)\n"
         "    --data-offset NUM         TCP data offset                  (default %d)\n"
         " -F,--fin                     TCP FIN flag                     (default OFF)\n"
         " -S,--syn                     TCP SYN flag                     (default OFF)\n"
         " -R,--rst                     TCP RST flag                     (default OFF)\n"
         " -P,--psh                     TCP PSH flag                     (default OFF)\n"
         " -A,--ack                     TCP ACK flag                     (default OFF)\n"
         " -U,--urg                     TCP URG flag                     (default OFF)\n"
         " -E,--ece                     TCP ECE flag                     (default OFF)\n"
         " -C,--cwr                     TCP CWR flag                     (default OFF)\n"
         " -W,--window NUM              TCP Window size                  (default NONE)\n"
         "    --urg-pointer NUM         TCP URG pointer                  (default NONE)\n"
         "    --mss NUM                 TCP Maximum Segment Size         (default NONE)\n"
         "    --wscale NUM              TCP Window Scale                 (default NONE)\n"
         "    --tstamp NUM:NUM          TCP Timestamp (TSval:TSecr)      (default NONE)\n"
         "    --sack-ok                 TCP SACK-Permitted               (default OFF)\n"
         "    --ttcp-cc NUM             T/TCP Connection Count (CC)      (default NONE)\n"
         "    --ccnew NUM               T/TCP Connection Count (CC.NEW)  (default NONE)\n"
         "    --ccecho NUM              T/TCP Connection Count (CC.ECHO) (default NONE)\n"
         "    --sack NUM:NUM            TCP SACK Edges (Left:Right)      (default NONE)\n"
         "    --md5-signature           TCP MD5 signature included       (default OFF)\n"
         "    --authentication          TCP-AO authentication included   (default OFF)\n"
         "    --auth-key-id NUM         TCP-AO authentication key ID     (default 1)\n"
         "    --auth-next-key NUM       TCP-AO authentication next key   (default 1)\n"
         "    --nop                     TCP No-Operation                 (default EOL)\n\n",
         (int)(sizeof(struct tcphdr) / 4));

  /* FIXME: Future call: egp_usage(); */
  printf("EGP Options:\n"
         "    --egp-type NUM            EGP type                         (default %d)\n"
         "    --egp-code NUM            EGP code                         (default %d)\n"
         "    --egp-status NUM          EGP status                       (default %d)\n"
         "    --egp-as NUM              EGP autonomous system            (default RANDOM)\n"
         "    --egp-sequence NUM        EGP sequence #                   (default RANDOM)\n"
         "    --egp-hello NUM           EGP hello interval               (default RANDOM)\n"
         "    --egp-poll NUM            EGP poll interval                (default RANDOM)\n\n",
         EGP_NEIGHBOR_ACQUISITION,
         EGP_ACQ_CODE_CEASE_CMD,
         EGP_ACQ_STAT_ACTIVE_MODE);

  /* FIXME: Future call: rip_usage(); */
  printf("RIP Options:\n"
         "    --rip-command NUM         RIPv1/v2 command                 (default 2)\n"
         "    --rip-family NUM          RIPv1/v2 address family          (default %d)\n"
         "    --rip-address ADDR        RIPv1/v2 router address          (default RANDOM)\n"
         "    --rip-metric NUM          RIPv1/v2 router metric           (default RANDOM)\n"
         "    --rip-domain NUM          RIPv2 router domain              (default RANDOM)\n"
         "    --rip-tag NUM             RIPv2 router tag                 (default RANDOM)\n"
         "    --rip-netmask ADDR        RIPv2 router subnet mask         (default RANDOM)\n"
         "    --rip-next-hop ADDR       RIPv2 router next hop            (default RANDOM)\n"
         "    --rip-authentication      RIPv2 authentication included    (default OFF)\n"
         "    --rip-auth-key-id NUM     RIPv2 authentication key ID      (default 1)\n"
         "    --rip-auth-sequence NUM   RIPv2 authentication sequence #  (default RANDOM)\n\n",
         AF_INET);

  /* FIXME: Future call: dccp_usage(); */
  printf("DCCP Options:\n"
         "    --dccp-data-offset NUM    DCCP data offset                 (default VARY)\n"
         "    --dccp-cscov NUM          DCCP checksum coverage           (default 0)\n"
         "    --dccp-ccval NUM          DCCP HC-Sender CCID              (default RANDOM)\n"
         "    --dccp-type NUM           DCCP type                        (default %d)\n"
         "    --dccp-extended           DCCP extend for sequence #       (default OFF)\n"
         "    --dccp-sequence-1 NUM     DCCP sequence #                  (default RANDOM)\n"
         "    --dccp-sequence-2 NUM     DCCP extended sequence #         (default RANDOM)\n"
         "    --dccp-sequence-3 NUM     DCCP sequence # low              (default RANDOM)\n"
         "    --dccp-service NUM        DCCP service code                (default RANDOM)\n"
         "    --dccp-acknowledge-1 NUM  DCCP acknowledgment # high       (default RANDOM)\n"
         "    --dccp-acknowledge-2 NUM  DCCP acknowledgment # low        (default RANDOM)\n"
         "    --dccp-reset-code NUM     DCCP reset code                  (default RANDOM)\n\n",
         DCCP_PKT_REQUEST);

  /* FIXME: Future call: rsvp_usage(); */
  printf("RSVP Options:\n"
         "    --rsvp-flags NUM          RSVP flags                       (default 1)\n"
         "    --rsvp-type NUM           RSVP message type                (default 1)\n"
         "    --rsvp-ttl NUM            RSVP time to live                (default 254)\n"
         "    --rsvp-session-addr ADDR  RSVP SESSION destination address (default RANDOM)\n"
         "    --rsvp-session-proto NUM  RSVP SESSION protocol ID         (default 1)\n"
         "    --rsvp-session-flags NUM  RSVP SESSION flags               (default 1)\n"
         "    --rsvp-session-port NUM   RSVP SESSION destination port    (default RANDOM)\n"
         "    --rsvp-hop-addr ADDR      RSVP HOP neighbor address        (default RANDOM)\n"
         "    --rsvp-hop-iface NUM      RSVP HOP logical interface       (default RANDOM)\n"
         "    --rsvp-time-refresh NUM   RSVP TIME refresh interval       (default 360)\n"
         "    --rsvp-error-addr ADDR    RSVP ERROR node address          (default RANDOM)\n"
         "    --rsvp-error-flags NUM    RSVP ERROR flags                 (default 2)\n"
         "    --rsvp-error-code NUM     RSVP ERROR code                  (default 2)\n"
         "    --rsvp-error-value NUM    RSVP ERROR value                 (default 8)\n"
         "    --rsvp-scope NUM          RSVP SCOPE # of address(es)      (default 1)\n"
         "    --rsvp-address ADDR,...   RSVP SCOPE address(es)           (default RANDOM)\n"
         "    --rsvp-style-option NUM   RSVP STYLE option vector         (default 18)\n"
         "    --rsvp-sender-addr ADDR   RSVP SENDER TEMPLATE address     (default RANDOM)\n"
         "    --rsvp-sender-port NUM    RSVP SENDER TEMPLATE port        (default RANDOM)\n"
         "    --rsvp-tspec-traffic      RSVP TSPEC service traffic       (default OFF)\n"
         "    --rsvp-tspec-guaranteed   RSVP TSPEC service guaranteed    (default OFF)\n"
         "    --rsvp-tspec-r NUM        RSVP TSPEC token bucket rate     (default RANDOM)\n"
         "    --rsvp-tspec-b NUM        RSVP TSPEC token bucket size     (default RANDOM)\n"
         "    --rsvp-tspec-p NUM        RSVP TSPEC peak data rate        (default RANDOM)\n"
         "    --rsvp-tspec-m NUM        RSVP TSPEC minimum policed unit  (default RANDOM)\n"
         "    --rsvp-tspec-M NUM        RSVP TSPEC maximum packet size   (default RANDOM)\n"
         "    --rsvp-adspec-ishop NUM   RSVP ADSPEC IS HOP count         (default RANDOM)\n"
         "    --rsvp-adspec-path NUM    RSVP ADSPEC path b/w estimate    (default RANDOM)\n"
         "    --rsvp-adspec-m NUM       RSVP ADSPEC minimum path latency (default RANDOM)\n"
         "    --rsvp-adspec-mtu NUM     RSVP ADSPEC composed MTU         (default RANDOM)\n"
         "    --rsvp-adspec-guaranteed  RSVP ADSPEC service guaranteed   (default OFF)\n"
         "    --rsvp-adspec-Ctot NUM    RSVP ADSPEC ETE composed value C (default RANDOM)\n"
         "    --rsvp-adspec-Dtot NUM    RSVP ADSPEC ETE composed value D (default RANDOM)\n"
         "    --rsvp-adspec-Csum NUM    RSVP ADSPEC SLR point composed C (default RANDOM)\n"
         "    --rsvp-adspec-Dsum NUM    RSVP ADSPEC SLR point composed D (default RANDOM)\n"
         "    --rsvp-adspec-controlled  RSVP ADSPEC service controlled   (default OFF)\n"
         "    --rsvp-confirm-addr ADDR  RSVP CONFIRM receiver address    (default RANDOM)\n\n");

  /* FIXME: Future call: ipsec_usage(); */
  printf("IPSEC Options:\n"
         "    --ipsec-ah-length NUM     IPSec AH header length           (default NONE)\n"
         "    --ipsec-ah-spi NUM        IPSec AH SPI                     (default RANDOM)\n"
         "    --ipsec-ah-sequence NUM   IPSec AH sequence #              (default RANDOM)\n"
         "    --ipsec-esp-spi NUM       IPSec ESP SPI                    (default RANDOM)\n"
         "    --ipsec-esp-sequence NUM  IPSec ESP sequence #             (default RANDOM)\n\n");

  /* FIXME: Future call: eigrp_usage(); */
  printf("EIGRP Options:\n"
         "    --eigrp-opcode NUM        EIGRP opcode                     (default %d)\n"
         "    --eigrp-flags NUM         EIGRP flags                      (default RANDOM)\n"
         "    --eigrp-sequence NUM      EIGRP sequence #                 (default RANDOM)\n"
         "    --eigrp-acknowledge NUM   EIGRP acknowledgment #           (default RANDOM)\n"
         "    --eigrp-as NUM            EIGRP autonomous system          (default RANDOM)\n"
         "    --eigrp-type NUM          EIGRP type                       (default %d)\n"
         "    --eigrp-length NUM        EIGRP length                     (default NONE)\n"
         "    --eigrp-k1 NUM            EIGRP parameter K1 value         (default 1)\n"
         "    --eigrp-k2 NUM            EIGRP parameter K2 value         (default 0)\n"
         "    --eigrp-k3 NUM            EIGRP parameter K3 value         (default 1)\n"
         "    --eigrp-k4 NUM            EIGRP parameter K4 value         (default 0)\n"
         "    --eigrp-k5 NUM            EIGRP parameter K5 value         (default 0)\n"
         "    --eigrp-hold NUM          EIGRP parameter hold time        (default 360)\n"
         "    --eigrp-ios-ver NUM.NUM   EIGRP IOS release version        (default 12.4)\n"
         "    --eigrp-rel-ver NUM.NUM   EIGRP PROTO release version      (default 1.2)\n"
         "    --eigrp-next-hop ADDR     EIGRP [in|ex]ternal next-hop     (default RANDOM)\n"
         "    --eigrp-delay NUM         EIGRP [in|ex]ternal delay        (default RANDOM)\n"
         "    --eigrp-bandwidth NUM     EIGRP [in|ex]ternal bandwidth    (default RANDOM)\n"
         "    --eigrp-mtu NUM           EIGRP [in|ex]ternal MTU          (default 1500)\n"
         "    --eigrp-hop-count NUM     EIGRP [in|ex]ternal hop count    (default RANDOM)\n"
         "    --eigrp-load NUM          EIGRP [in|ex]ternal load         (default RANDOM)\n"
         "    --eigrp-reliability NUM   EIGRP [in|ex]ternal reliability  (default RANDOM)\n"
         "    --eigrp-daddr ADDR/CIDR   EIGRP [in|ex]ternal address(es)  (default RANDOM)\n"
         "    --eigrp-src-router ADDR   EIGRP external source router     (default RANDOM)\n"
         "    --eigrp-src-as NUM        EIGRP external autonomous system (default RANDOM)\n"
         "    --eigrp-tag NUM           EIGRP external arbitrary tag     (default RANDOM)\n"
         "    --eigrp-proto-metric NUM  EIGRP external protocol metric   (default RANDOM)\n"
         "    --eigrp-proto-id NUM      EIGRP external protocol ID       (default 2)\n"
         "    --eigrp-ext-flags NUM     EIGRP external flags             (default RANDOM)\n"
         "    --eigrp-address ADDR      EIGRP multicast sequence address (default RANDOM)\n"
         "    --eigrp-multicast NUM     EIGRP multicast sequence #       (default RANDOM)\n"
         "    --eigrp-authentication    EIGRP authentication included    (default OFF)\n"
         "    --eigrp-auth-key-id NUM   EIGRP authentication key ID      (default 1)\n\n",
         EIGRP_OPCODE_UPDATE,
         EIGRP_TYPE_INTERNAL);

  /* FIXME: Future call: ospf_usage(); */
  printf("OSPF Options:\n"
         "    --ospf-type NUM           OSPF type                        (default %d)\n"
         "    --ospf-length NUM         OSPF length                      (default NONE)\n"
         "    --ospf-router-id ADDR     OSPF router ID                   (default RANDOM)\n"
         "    --ospf-area-id ADDR       OSPF area ID                     (default 0.0.0.0)\n"
         " -1,--ospf-option-MT          OSPF multi-topology / TOS-based  (default RANDOM)\n"
         " -2,--ospf-option-E           OSPF external routing capability (default RANDOM)\n"
         " -3,--ospf-option-MC          OSPF multicast capable           (default RANDOM)\n"
         " -4,--ospf-option-NP          OSPF NSSA supported              (default RANDOM)\n"
         " -5,--ospf-option-L           OSPF LLS data block contained    (default RANDOM)\n"
         " -6,--ospf-option-DC          OSPF demand circuits supported   (default RANDOM)\n"
         " -7,--ospf-option-O           OSPF Opaque-LSA                  (default RANDOM)\n"
         " -8,--ospf-option-DN          OSPF DOWN bit                    (default RANDOM)\n"
         "    --ospf-netmask ADDR       OSPF router subnet mask          (default RANDOM)\n"
         "    --ospf-hello-interval NUM OSPF HELLO interval              (default RANDOM)\n"
         "    --ospf-hello-priority NUM OSPF HELLO router priority       (default 1)\n"
         "    --ospf-hello-dead NUM     OSPF HELLO router dead interval  (default 360)\n"
         "    --ospf-hello-design ADDR  OSPF HELLO designated router     (default RANDOM)\n"
         "    --ospf-hello-backup ADDR  OSPF HELLO backup designated     (default RANDOM)\n"
         "    --ospf-neighbor NUM       OSPF HELLO # of neighbor(s)      (default NONE)\n"
         "    --ospf-address ADDR,...   OSPF HELLO neighbor address(es)  (default RANDOM)\n"
         "    --ospf-dd-mtu NUM         OSPF DD MTU                      (default 1500)\n"
         "    --ospf-dd-dbdesc-MS       OSPF DD master/slave bit option  (default RANDOM)\n"
         "    --ospf-dd-dbdesc-M        OSPF DD more bit option          (default RANDOM)\n"
         "    --ospf-dd-dbdesc-I        OSPF DD init bit option          (default RANDOM)\n"
         "    --ospf-dd-dbdesc-R        OSPF DD out-of-band resync       (default RANDOM)\n"
         "    --ospf-dd-sequence NUM    OSPF DD sequence #               (default RANDOM)\n"
         "    --ospf-dd-include-lsa     OSPF DD include LSA header       (default OFF)\n"
         "    --ospf-lsa-age NUM        OSPF LSA age                     (default 360)\n"
         "    --ospf-lsa-do-not-age     OSPF LSA do not age              (default OFF)\n"
         "    --ospf-lsa-type NUM       OSPF LSA type                    (default %d)\n"
         "    --ospf-lsa-id ADDR        OSPF LSA ID address              (default RANDOM)\n"
         "    --ospf-lsa-router ADDR    OSPF LSA advertising router      (default RANDOM)\n"
         "    --ospf-lsa-sequence NUM   OSPF LSA sequence #              (default RANDOM)\n"
         "    --ospf-lsa-metric NUM     OSPF LSA metric                  (default RANDOM)\n"
         "    --ospf-lsa-flag-B         OSPF Router-LSA border router    (default RANDOM)\n"
         "    --ospf-lsa-flag-E         OSPF Router-LSA external router  (default RANDOM)\n"
         "    --ospf-lsa-flag-V         OSPF Router-LSA virtual router   (default RANDOM)\n"
         "    --ospf-lsa-flag-W         OSPF Router-LSA wild router      (default RANDOM)\n"
         "    --ospf-lsa-flag-NT        OSPF Router-LSA NSSA translation (default RANDOM)\n"
         "    --ospf-lsa-link-id ADDR   OSPF Router-LSA link ID          (default RANDOM)\n"
         "    --ospf-lsa-link-data ADDR OSPF Router-LSA link data        (default RANDOM)\n"
         "    --ospf-lsa-link-type NUM  OSPF Router-LSA link type        (default %d)\n"
         "    --ospf-lsa-attached ADDR  OSPF Network-LSA attached router (default RANDOM)\n"
         "    --ospf-lsa-larger         OSPF ASBR/NSSA-LSA ext. larger   (default OFF)\n"
         "    --ospf-lsa-forward ADDR   OSPF ASBR/NSSA-LSA forward       (default RANDOM)\n"
         "    --ospf-lsa-external ADDR  OSPF ASBR/NSSA-LSA external      (default RANDOM)\n"
         "    --ospf-vertex-router      OSPF Group-LSA type router       (default RANDOM)\n"
         "    --ospf-vertex-network     OSPF Group-LSA type network      (default RANDOM)\n"
         "    --ospf-vertex-id ADDR     OSPF Group-LSA vertex ID         (default RANDOM)\n"
         "    --ospf-lls-extended-LR    OSPF LLS Extended option LR      (default OFF)\n"
         "    --ospf-lls-extended-RS    OSPF LLS Extended option RS      (default OFF)\n"
         "    --ospf-authentication     OSPF authentication included     (default OFF)\n"
         "    --ospf-auth-key-id NUM    OSPF authentication key ID       (default 1)\n"
         "    --ospf-auth-sequence NUM  OSPF authentication sequence #   (default RANDOM)\n\n",
         OSPF_TYPE_HELLO,
         LSA_TYPE_ROUTER,
         LINK_TYPE_PTP);

  printf("Some considerations while running this program:\n"
         " 1. There is no limitation of using as many options as possible.\n"
         " 2. Report %s bugs at %s.\n"
         " 3. Some header fields with default values MUST be set to \'0\' for RANDOM.\n"
         " 4. Mandatory arguments to long options are mandatory for short options too.\n"
         " 5. Be nice when using %s, the author DENIES its use for DoS/DDoS purposes.\n"
         " 6. Running %s with \'--protocol T50\' option sends ALL protocols sequentially.\n\n",
         PACKAGE, SITE, PACKAGE, PACKAGE);

  fflush(stdout);
  exit(EXIT_FAILURE);
}
