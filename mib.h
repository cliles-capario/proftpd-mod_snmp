/*
 * ProFTPD - mod_snmp MIB
 * Copyright (c) 2008-2012 TJ Saunders
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA.
 *
 * As a special exemption, TJ Saunders and other respective copyright holders
 * give permission to link this program with OpenSSL, and distribute the
 * resulting executable, without including the source code for OpenSSL in the
 * source distribution.
 */

#include "mod_snmp.h"
#include "asn1.h"

#ifndef MOD_SNMP_MIB_H
#define MOD_SNMP_MIB_H

/* SNMPv2-MIB
 *
 * .iso.org.dod.internet.mgmt.mib-2.system
 *   1   3   6      1     2     1     1
 *
 * .iso.org.dod.internet.snmpV2.snmpModules.snmpMIB.snmpMIBObjects.snmpTrap
 *   1   3   6      1      6        3          1          1           4
 */

#define SNMP_MGMT_SYS_OID_BASE		1, 3, 6, 1, 2, 1, 1
#define SNMP_MGMT_SYS_OID_BASELEN	7

#define SNMP_MGMT_SYS_MIB_NAME_PREFIX	"mgmt.mib-2.system."

#define SNMP_MGMT_SYS_OID_UPTIME	SNMP_MGMT_SYS_OID_BASE, 1
#define SNMP_MGMT_SYS_OIDLEN_UPTIME	SNMP_MGMT_SYS_OID_BASELEN + 1

#define SNMP_SNMP2_TRAP_OID_BASE	1, 3, 6, 1, 6, 3, 1, 1, 4
#define SNMP_SNMP2_TRAP_OID_BASELEN	9

#define SNMP_SNMP2_TRAP_MIB_NAME_PREFIX	"snmpV2.snmpModules.snmpMIB.snmpMIBObjects.snmpTrap."

#define SNMP_SNMP2_TRAP_OID_OID		SNMP_SNMP2_TRAP_OID_BASE, 1
#define SNMP_SNMP2_TRAP_OIDLEN_OID	SNMP_SNMP2_TRAP_OID_BASELEN + 1

/* PROFTPD-MIB
 *
 * .iso.org.dod.internet.private.enterprises.proftpd.modules.snmp
 *   1   3   6      1       4        1        17852     2      2
 *
 */

#define SNMP_OID_BASE		1, 3, 6, 1, 4, 1, 17852, 2, 2
#define SNMP_OID_BASELEN	9

#define SNMP_MIB_NAME_PREFIX	"proftpd.modules.snmp."

/* Groups under .snmp */
#define SNMP_CONN_OID_BASE		SNMP_OID_BASE, 0
#define SNMP_CONN_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_DAEMON_OID_BASE		SNMP_OID_BASE, 1
#define SNMP_DAEMON_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_FTP_OID_BASE		SNMP_OID_BASE, 2
#define SNMP_FTP_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_SNMP_OID_BASE		SNMP_OID_BASE, 3
#define SNMP_SNMP_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_SSL_OID_BASE		SNMP_OID_BASE, 4
#define SNMP_SSL_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_SSH_OID_BASE		SNMP_OID_BASE, 5
#define SNMP_SSH_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_SQL_OID_BASE		SNMP_OID_BASE, 6
#define SNMP_SQL_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_QUOTA_OID_BASE		SNMP_OID_BASE, 7
#define SNMP_QUOTA_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_BAN_OID_BASE		SNMP_OID_BASE, 8
#define SNMP_BAN_OID_BASELEN		SNMP_OID_BASELEN + 1

#define SNMP_GEOIP_OID_BASE		SNMP_OID_BASE, 9
#define SNMP_GEOIP_OID_BASELEN		SNMP_OID_BASELEN + 1

/* Connection MIBs */
#define SNMP_MIB_CONN_OID_SERVER_NAME		SNMP_CONN_OID_BASE, 1
#define SNMP_MIB_CONN_OIDLEN_SERVER_NAME	SNMP_CONN_OID_BASELEN + 1

#define SNMP_MIB_CONN_OID_SERVER_ADDR		SNMP_CONN_OID_BASE, 2
#define SNMP_MIB_CONN_OIDLEN_SERVER_ADDR	SNMP_CONN_OID_BASELEN + 1

#define SNMP_MIB_CONN_OID_SERVER_PORT		SNMP_CONN_OID_BASE, 3
#define SNMP_MIB_CONN_OIDLEN_SERVER_PORT	SNMP_CONN_OID_BASELEN + 1

#define SNMP_MIB_CONN_OID_CLIENT_ADDR		SNMP_CONN_OID_BASE, 4
#define SNMP_MIB_CONN_OIDLEN_CLIENT_ADDR	SNMP_CONN_OID_BASELEN + 1

#define SNMP_MIB_CONN_OID_PID			SNMP_CONN_OID_BASE, 5
#define SNMP_MIB_CONN_OIDLEN_PID		SNMP_CONN_OID_BASELEN + 1

#define SNMP_MIB_CONN_OID_USER_NAME		SNMP_CONN_OID_BASE, 6
#define SNMP_MIB_CONN_OIDLEN_USER_NAME		SNMP_CONN_OID_BASELEN + 1

#define SNMP_MIB_CONN_OID_PROTOCOL		SNMP_CONN_OID_BASE, 7
#define SNMP_MIB_CONN_OIDLEN_PROTOCOL		SNMP_CONN_OID_BASELEN + 1

/* Daemon MIBs */
#define SNMP_MIB_DAEMON_OID_SOFTWARE		SNMP_DAEMON_OID_BASE, 1 
#define SNMP_MIB_DAEMON_OIDLEN_SOFTWARE		SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_VERSION		SNMP_DAEMON_OID_BASE, 2
#define SNMP_MIB_DAEMON_OIDLEN_VERSION		SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_ADMIN		SNMP_DAEMON_OID_BASE, 3
#define SNMP_MIB_DAEMON_OIDLEN_ADMIN		SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_UPTIME		SNMP_DAEMON_OID_BASE, 4
#define SNMP_MIB_DAEMON_OIDLEN_UPTIME		SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_VHOST_COUNT		SNMP_DAEMON_OID_BASE, 5
#define SNMP_MIB_DAEMON_OIDLEN_VHOST_COUNT	SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_CONN_COUNT		SNMP_DAEMON_OID_BASE, 6
#define SNMP_MIB_DAEMON_OIDLEN_CONN_COUNT 	SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_CONN_TOTAL		SNMP_DAEMON_OID_BASE, 7
#define SNMP_MIB_DAEMON_OIDLEN_CONN_TOTAL 	SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_CONN_REFUSED_TOTAL \
  SNMP_DAEMON_OID_BASE, 8
#define SNMP_MIB_DAEMON_OIDLEN_CONN_REFUSED_TOTAL \
  SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_RESTART_COUNT	SNMP_DAEMON_OID_BASE, 9
#define SNMP_MIB_DAEMON_OIDLEN_RESTART_COUNT	SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_SEGFAULT_COUNT	SNMP_DAEMON_OID_BASE, 10
#define SNMP_MIB_DAEMON_OIDLEN_SEGFAULT_COUNT	SNMP_DAEMON_OID_BASELEN + 1

#define SNMP_MIB_DAEMON_OID_MAXINST_COUNT	SNMP_DAEMON_OID_BASE, 11
#define SNMP_MIB_DAEMON_OIDLEN_MAXINST_COUNT	SNMP_DAEMON_OID_BASELEN + 1

/* ftp.sessions MIBs */
#define SNMP_FTP_SESS_OID_BASE			SNMP_FTP_OID_BASE, 1
#define SNMP_FTP_SESS_OID_BASELEN		SNMP_FTP_OID_BASELEN + 1

#define SNMP_MIB_FTP_SESS_OID_SESS_COUNT	SNMP_FTP_SESS_OID_BASE, 1
#define SNMP_MIB_FTP_SESS_OIDLEN_SESS_COUNT 	SNMP_FTP_SESS_OID_BASELEN + 1

#define SNMP_MIB_FTP_SESS_OID_SESS_TOTAL	SNMP_FTP_SESS_OID_BASE, 2
#define SNMP_MIB_FTP_SESS_OIDLEN_SESS_TOTAL 	SNMP_FTP_SESS_OID_BASELEN + 1

#define SNMP_MIB_FTP_SESS_OID_CMD_INVALID_TOTAL \
  SNMP_FTP_SESS_OID_BASE, 3
#define SNMP_MIB_FTP_SESS_OIDLEN_CMD_INVALID_TOTAL \
  SNMP_FTP_SESS_OID_BASELEN + 1

/* ftp.logins MIBs */
#define SNMP_FTP_LOGINS_OID_BASE		SNMP_FTP_OID_BASE, 2
#define SNMP_FTP_LOGINS_OID_BASELEN		SNMP_FTP_OID_BASELEN + 1

#define SNMP_MIB_FTP_LOGINS_OID_TOTAL		SNMP_FTP_LOGINS_OID_BASE, 1
#define SNMP_MIB_FTP_LOGINS_OIDLEN_TOTAL 	SNMP_FTP_LOGINS_OID_BASELEN + 1

#define SNMP_MIB_FTP_LOGINS_OID_ERR_TOTAL 	SNMP_FTP_LOGINS_OID_BASE, 2
#define SNMP_MIB_FTP_LOGINS_OIDLEN_ERR_TOTAL 	SNMP_FTP_LOGINS_OID_BASELEN + 1

#define SNMP_MIB_FTP_LOGINS_OID_ERR_BAD_USER_TOTAL \
  SNMP_FTP_LOGINS_OID_BASE, 3
#define SNMP_MIB_FTP_LOGINS_OIDLEN_ERR_BAD_USER_TOTAL \
  SNMP_FTP_LOGINS_OID_BASELEN + 1

#define SNMP_MIB_FTP_LOGINS_OID_ERR_BAD_PASSWD_TOTAL \
  SNMP_FTP_LOGINS_OID_BASE, 4
#define SNMP_MIB_FTP_LOGINS_OIDLEN_ERR_BAD_PASSWD_TOTAL \
  SNMP_FTP_LOGINS_OID_BASELEN + 1

#define SNMP_MIB_FTP_LOGINS_OID_ERR_GENERAL_TOTAL \
  SNMP_FTP_LOGINS_OID_BASE, 5
#define SNMP_MIB_FTP_LOGINS_OIDLEN_ERR_GENERAL_TOTAL \
  SNMP_FTP_LOGINS_OID_BASELEN + 1

#define SNMP_MIB_FTP_LOGINS_OID_ANON_COUNT	SNMP_FTP_LOGINS_OID_BASE, 6
#define SNMP_MIB_FTP_LOGINS_OIDLEN_ANON_COUNT 	SNMP_FTP_LOGINS_OID_BASELEN + 1

#define SNMP_MIB_FTP_LOGINS_OID_ANON_TOTAL	SNMP_FTP_LOGINS_OID_BASE, 7
#define SNMP_MIB_FTP_LOGINS_OIDLEN_ANON_TOTAL 	SNMP_FTP_LOGINS_OID_BASELEN + 1

/* ftp.dataTransfers MIBs */
#define SNMP_FTP_XFERS_OID_BASE			SNMP_FTP_OID_BASE, 3
#define SNMP_FTP_XFERS_OID_BASELEN		SNMP_FTP_OID_BASELEN + 1

#define SNMP_MIB_FTP_XFERS_OID_DIR_LIST_TOTAL \
  SNMP_FTP_XFERS_OID_BASE, 1
#define SNMP_MIB_FTP_XFERS_OIDLEN_DIR_LIST_TOTAL \
  SNMP_FTP_XFERS_OID_BASELEN + 1

#define SNMP_MIB_FTP_XFERS_OID_DIR_LIST_ERR_TOTAL \
  SNMP_FTP_XFERS_OID_BASE, 2
#define SNMP_MIB_FTP_XFERS_OIDLEN_DIR_LIST_ERR_TOTAL \
  SNMP_FTP_XFERS_OID_BASELEN + 1

#define SNMP_MIB_FTP_XFERS_OID_FILE_UPLOAD_TOTAL \
  SNMP_FTP_XFERS_OID_BASE, 3
#define SNMP_MIB_FTP_XFERS_OIDLEN_FILE_UPLOAD_TOTAL \
  SNMP_FTP_XFERS_OID_BASELEN + 1

#define SNMP_MIB_FTP_XFERS_OID_FILE_UPLOAD_ERR_TOTAL \
  SNMP_FTP_XFERS_OID_BASE, 4
#define SNMP_MIB_FTP_XFERS_OIDLEN_FILE_UPLOAD_ERR_TOTAL \
  SNMP_FTP_XFERS_OID_BASELEN + 1

#define SNMP_MIB_FTP_XFERS_OID_FILE_DOWNLOAD_TOTAL \
  SNMP_FTP_XFERS_OID_BASE, 5
#define SNMP_MIB_FTP_XFERS_OIDLEN_FILE_DOWNLOAD_TOTAL \
  SNMP_FTP_XFERS_OID_BASELEN + 1

#define SNMP_MIB_FTP_XFERS_OID_FILE_DOWNLOAD_ERR_TOTAL \
  SNMP_FTP_XFERS_OID_BASE, 6
#define SNMP_MIB_FTP_XFERS_OIDLEN_FILE_DOWNLOAD_ERR_TOTAL \
  SNMP_FTP_XFERS_OID_BASELEN + 1

#define SNMP_MIB_FTP_XFERS_OID_KB_UPLOAD_TOTAL \
  SNMP_FTP_XFERS_OID_BASE, 7
#define SNMP_MIB_FTP_XFERS_OIDLEN_KB_UPLOAD_TOTAL \
  SNMP_FTP_XFERS_OID_BASELEN + 1

#define SNMP_MIB_FTP_XFERS_OID_KB_DOWNLOAD_TOTAL \
  SNMP_FTP_XFERS_OID_BASE, 8
#define SNMP_MIB_FTP_XFERS_OIDLEN_KB_DOWNLOAD_TOTAL \
  SNMP_FTP_XFERS_OID_BASELEN + 1

/* ftp.timeouts MIBs */
#define SNMP_FTP_TIMEOUTS_OID_BASE		SNMP_FTP_OID_BASE, 4
#define SNMP_FTP_TIMEOUTS_OID_BASELEN		SNMP_FTP_OID_BASELEN + 1

#define SNMP_MIB_FTP_TIMEOUTS_OID_IDLE_TOTAL \
  SNMP_FTP_TIMEOUTS_OID_BASE, 1
#define SNMP_MIB_FTP_TIMEOUTS_OIDLEN_IDLE_TOTAL \
  SNMP_FTP_TIMEOUTS_OID_BASELEN + 1

#define SNMP_MIB_FTP_TIMEOUTS_OID_LOGIN_TOTAL \
  SNMP_FTP_TIMEOUTS_OID_BASE, 2
#define SNMP_MIB_FTP_TIMEOUTS_OIDLEN_LOGIN_TOTAL \
  SNMP_FTP_TIMEOUTS_OID_BASELEN + 1

#define SNMP_MIB_FTP_TIMEOUTS_OID_NOXFER_TOTAL \
  SNMP_FTP_TIMEOUTS_OID_BASE, 3
#define SNMP_MIB_FTP_TIMEOUTS_OIDLEN_NOXFER_TOTAL \
  SNMP_FTP_TIMEOUTS_OID_BASELEN + 1

#define SNMP_MIB_FTP_TIMEOUTS_OID_STALLED_TOTAL \
  SNMP_FTP_TIMEOUTS_OID_BASE, 4
#define SNMP_MIB_FTP_TIMEOUTS_OIDLEN_STALLED_TOTAL \
  SNMP_FTP_TIMEOUTS_OID_BASELEN + 1

/* ftp.notifications MIBs */
#define SNMP_FTP_NOTIFICATIONS_OID_BASE		SNMP_FTP_OID_BASE, 5
#define SNMP_FTP_NOTIFICATIONS_OID_BASELEN	SNMP_FTP_OID_BASELEN + 1

#define SNMP_MIB_FTP_NOTIFICATIONS_OID_LOGIN_BAD_PASSWORD \
  SNMP_FTP_NOTIFICATIONS_OID_BASE, 1
#define SNMP_MIB_FTP_NOTIFICATIONS_OIDLEN_LOGIN_BAD_PASSWORD \
  SNMP_FTP_NOTIFICATIONS_OID_BASELEN + 1

/* snmp MIBs */
#define SNMP_MIB_SNMP_OID_PKTS_RECVD_TOTAL	SNMP_SNMP_OID_BASE, 1 
#define SNMP_MIB_SNMP_OIDLEN_PKTS_RECVD_TOTAL 	SNMP_SNMP_OID_BASELEN + 1

#define SNMP_MIB_SNMP_OID_PKTS_SENT_TOTAL 	SNMP_SNMP_OID_BASE, 2 
#define SNMP_MIB_SNMP_OIDLEN_PKTS_SENT_TOTAL	SNMP_SNMP_OID_BASELEN + 1

#define SNMP_MIB_SNMP_OID_TRAPS_SENT_TOTAL	SNMP_SNMP_OID_BASE, 3 
#define SNMP_MIB_SNMP_OIDLEN_TRAPS_SENT_TOTAL 	SNMP_SNMP_OID_BASELEN + 1

#define SNMP_MIB_SNMP_OID_PKTS_AUTH_ERR_TOTAL \
  SNMP_SNMP_OID_BASE, 4 
#define SNMP_MIB_SNMP_OIDLEN_PKTS_AUTH_ERR_TOTAL \
  SNMP_SNMP_OID_BASELEN + 1

#define SNMP_MIB_SNMP_OID_PKTS_DROPPED_TOTAL \
  SNMP_SNMP_OID_BASE, 5 
#define SNMP_MIB_SNMP_OIDLEN_PKTS_DROPPED_TOTAL \
  SNMP_SNMP_OID_BASELEN + 1

/* XXX sslStats MIBs */

/* XXX sshStats MIBs */

/* XXX sqlStats MIBs */

/* XXX quotaStats MIBs */

/* XXX banStats MIBs */

/* XXX geoipStats MIBs */

/* The longest MIB that we support/define. */
#define SNMP_MIB_MAX_OIDLEN	14

/* The index at which the sysUpTime OID appears in our MIBs array. */
#define SNMP_MIB_SYS_UPTIME_IDX		1

/* The index at which the snmpTrapOID OID appears in our MIBs array. */
#define SNMP_MIB_SNMP2_TRAP_OID_IDX	2

struct snmp_mib {
  oid_t mib_oid[SNMP_MIB_MAX_OIDLEN];
  unsigned int mib_oidlen;
  unsigned int db_field;
  const char *mib_name;
  const char *instance_name;
  unsigned char smi_type;
};

struct snmp_mib *snmp_mib_get_by_idx(unsigned int mib_idx);
struct snmp_mib *snmp_mib_get_by_oid(oid_t *mib_oid, unsigned int mib_oidlen,
  int *lacks_instance_id);
int snmp_mib_get_idx(oid_t *mib_oid, unsigned int mib_oidlen,
  int *lacks_instance_id);
int snmp_mib_get_nearest_idx(oid_t *mib_oid, unsigned int mib_oidlen);

/* Returns the highest valid MIB index.  Why is this a runtime function,
 * rather than a compile-time constant?  Because of the conditional nature
 * of some of the MIBs e.g. pertaining to mod_tls or mod_sftp; those modules
 * may not be present/loaded.
 */
int snmp_mib_get_max_idx(void);

/* Resets the counter values in the database, as per RFC recommendation. */
int snmp_mib_reset_counters(void);

#endif
