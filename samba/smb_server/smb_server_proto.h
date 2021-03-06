#ifndef __SMB_SERVER_SMB_SERVER_PROTO_H__
#define __SMB_SERVER_SMB_SERVER_PROTO_H__

#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2) PRINTF_ATTRIBUTE(a1, a2)
/* This file was automatically generated by mkproto.pl. DO NOT EDIT */

#ifndef _PUBLIC_
#define _PUBLIC_
#endif


/* The following definitions come from smb_server/handle.c  */

NTSTATUS smbsrv_init_handles(struct smbsrv_tcon *tcon, uint64_t limit);
struct smbsrv_handle *smbsrv_smb_handle_find(struct smbsrv_tcon *smb_tcon,
					     uint16_t fnum, struct timeval request_time);
struct smbsrv_handle *smbsrv_smb2_handle_find(struct smbsrv_tcon *smb_tcon,
					      uint64_t hid, struct timeval request_time);
struct smbsrv_handle *smbsrv_handle_new(struct smbsrv_session *session,
				        struct smbsrv_tcon *tcon,
				        TALLOC_CTX *mem_ctx,
					struct timeval request_time);

/* The following definitions come from smb_server/tcon.c  */

struct socket_address *smbsrv_get_my_addr(void *p, TALLOC_CTX *mem_ctx);
struct socket_address *smbsrv_get_peer_addr(void *p, TALLOC_CTX *mem_ctx);
NTSTATUS smbsrv_smb_init_tcons(struct smbsrv_connection *smb_conn);
NTSTATUS smbsrv_smb2_init_tcons(struct smbsrv_session *smb_sess);
struct smbsrv_tcon *smbsrv_smb_tcon_find(struct smbsrv_connection *smb_conn,
					 uint32_t tid, struct timeval request_time);
struct smbsrv_tcon *smbsrv_smb2_tcon_find(struct smbsrv_session *smb_sess,
					  uint32_t tid, struct timeval request_time);
struct smbsrv_tcon *smbsrv_smb_tcon_new(struct smbsrv_connection *smb_conn, const char *share_name);
struct smbsrv_tcon *smbsrv_smb2_tcon_new(struct smbsrv_session *smb_sess, const char *share_name);

/* The following definitions come from smb_server/session.c  */

NTSTATUS smbsrv_init_sessions(struct smbsrv_connection *smb_conn, uint64_t limit);
struct smbsrv_session *smbsrv_session_find(struct smbsrv_connection *smb_conn,
					   uint64_t vuid, struct timeval request_time);
struct smbsrv_session *smbsrv_session_find_sesssetup(struct smbsrv_connection *smb_conn, uint64_t vuid);
NTSTATUS smbsrv_session_sesssetup_finished(struct smbsrv_session *sess,
				           struct auth_session_info *session_info);
struct smbsrv_session *smbsrv_session_new(struct smbsrv_connection *smb_conn,
					  struct gensec_security *gensec_ctx);

/* The following definitions come from smb_server/blob.c  */

NTSTATUS smbsrv_blob_grow_data(TALLOC_CTX *mem_ctx,
			       DATA_BLOB *blob,
			       uint32_t new_size);
NTSTATUS smbsrv_blob_fill_data(TALLOC_CTX *mem_ctx,
			       DATA_BLOB *blob,
			       uint32_t new_size);
size_t smbsrv_blob_pull_string(struct smbsrv_request *req, 
			       const DATA_BLOB *blob,
			       uint16_t offset,
			       const char **str,
			       int flags);
size_t smbsrv_blob_push_string(TALLOC_CTX *mem_ctx,
			       DATA_BLOB *blob,
			       uint32_t len_offset,
			       uint32_t offset,
			       const char *str,
			       int dest_len,
			       int default_flags,
			       int flags);
NTSTATUS smbsrv_blob_append_string(TALLOC_CTX *mem_ctx,
				   DATA_BLOB *blob,
				   const char *str,
				   uint_t len_offset,
				   int default_flags,
				   int flags);
NTSTATUS smbsrv_push_passthru_fsinfo(TALLOC_CTX *mem_ctx,
				     DATA_BLOB *blob,
				     enum smb_fsinfo_level level,
				     union smb_fsinfo *fsinfo,
				     int default_str_flags);
NTSTATUS smbsrv_push_passthru_fileinfo(TALLOC_CTX *mem_ctx,
				       DATA_BLOB *blob,
				       enum smb_fileinfo_level level,
				       union smb_fileinfo *st,
				       int default_str_flags);
NTSTATUS smbsrv_pull_passthru_sfileinfo(TALLOC_CTX *mem_ctx,
					enum smb_setfileinfo_level level,
					union smb_setfileinfo *st,
					const DATA_BLOB *blob,
					int default_str_flags,
					struct smbsrv_request *req);
NTSTATUS smbsrv_push_passthru_search(TALLOC_CTX *mem_ctx,
				     DATA_BLOB *blob,
				     enum smb_search_data_level level,
				     union smb_search_data *file,
				     int default_str_flags);

/* The following definitions come from smb_server/management.c  */

void smbsrv_management_init(struct smbsrv_connection *smb_conn);
#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2)

#endif /* __SMB_SERVER_SMB_SERVER_PROTO_H__ */

