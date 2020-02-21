#include "CurlExample.h"

#include <stdio.h>
#include <curl/curl.h>

#include "rapidjson/reader.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/error/en.h"

using namespace rapidjson;


extern "C" int _10_at_a_time(void);
extern "C" int anyauthput(int argc, char **argv);
extern "C" int certinfo(void);
extern "C" int chkspeed(int argc, char *argv[]);
extern "C" int cookie_interface(void);
extern "C" int curlx(int argc, char **argv);
extern "C" int debug(void);
extern "C" int externalsocket(void);
extern "C" int fileupload(void);
extern "C" int _fopen(int argc, char *argv[]);
extern "C" int ftp_wildcard(int argc, char **argv);
extern "C" int ftpget(void);
extern "C" int ftpgetinfo(void);
extern "C" int ftpgetresp(void);
extern "C" int ftpsget(void);
extern "C" int ftpupload(void);
extern "C" int ftpuploadfrommem(void);
extern "C" int ftpuploadresume(void);
extern "C" int getinfo(void);
extern "C" int getinmemory(void);
extern "C" int getredirect(void);
extern "C" int http_post(void);
extern "C" int http2_download(int argc, char **argv);
extern "C" int http2_pushinmemory(void);
extern "C" int http2_serverpush(void);
extern "C" int http2_upload(int argc, char **argv);
extern "C" int httpcustomheader(void);
extern "C" int httpput(int argc, char **argv);
extern "C" int https(void);
extern "C" int imap_append(void);
extern "C" int imap_copy(void);
extern "C" int imap_create(void);
extern "C" int imap_delete(void);
extern "C" int imap_examine(void);
extern "C" int imap_fetch(void);
extern "C" int imap_list(void);
extern "C" int imap_lsub(void);
extern "C" int imap_multi(void);
extern "C" int imap_noop(void);
extern "C" int imap_search(void);
extern "C" int imap_ssl(void);
extern "C" int imap_store(void);
extern "C" int imap_tls(void);
extern "C" int multi_app(void);
extern "C" int multi_debugcallback(void);
extern "C" int multi_double(void);
extern "C" int multi_formadd(void);
extern "C" int multi_single(void);
extern "C" int multithread(int argc, char **argv);
extern "C" int persistent(void);
extern "C" int pop3_dele(void);
extern "C" int pop3_list(void);
extern "C" int pop3_multi(void);
extern "C" int pop3_noop(void);
extern "C" int pop3_retr(void);
extern "C" int pop3_ssl(void);
extern "C" int pop3_stat(void);
extern "C" int pop3_tls(void);
extern "C" int pop3_top(void);
extern "C" int pop3_uidl(void);
extern "C" int post_callback(void);
extern "C" int postinmemory(void);
extern "C" int postit2_formadd(int argc, char *argv[]);
extern "C" int resolve(void);
extern "C" int rtsp(int argc, char * const argv[]);
extern "C" int sendrecv(void);
extern "C" int sepheaders(void);
extern "C" int sftpget(void);
extern "C" int sftpuploadresume(void);
extern "C" int shared_connection_cache(void);
extern "C" int simple(void);
extern "C" int simplepost(void);
extern "C" int simplessl(void);
extern "C" int smtp_expn(void);
extern "C" int smtp_mail(void);
extern "C" int smtp_multi(void);
extern "C" int smtp_ssl(void);
extern "C" int smtp_tls(void);
extern "C" int smtp_vrfy(void);
extern "C" int threaded_shared_conn(void);
extern "C" int threaded_ssl(int argc, char **argv);
extern "C" int url2file(int argc, char *argv[]);
extern "C" int usercertinmem(void);

int CurlExample::test_10_at_a_time(void){return _10_at_a_time();}
// int CurlExample::test_anyauthput(const std::vector<std::string>> &args){return anyauthput(argc, argv);}
int CurlExample::test_certinfo(void){return certinfo();}
// int CurlExample::test_chkspeed(const std::vector<std::string>> &args){return chkspeed(argc, argv);}
int CurlExample::test_cookie_interface(void){return cookie_interface();}
// int CurlExample::test_curlx(const std::vector<std::string>> &args){return curlx(argc, argv);}
int CurlExample::test_debug(void){return debug();}
int CurlExample::test_externalsocket(void){return externalsocket();}
int CurlExample::test_fileupload(void){return fileupload();}
// int CurlExample::test_fopen(const std::vector<std::string>> &args){return _fopen(argc, argv);}
// int CurlExample::test_ftp_wildcard(const std::vector<std::string>> &args){return ftp_wildcard(argc, argv);}
int CurlExample::test_ftpget(void){return ftpget();}
int CurlExample::test_ftpgetinfo(void){return ftpgetinfo();}
int CurlExample::test_ftpgetresp(void){return ftpgetresp();}
int CurlExample::test_ftpsget(void){return ftpsget();}
int CurlExample::test_ftpupload(void){return ftpupload();}
int CurlExample::test_ftpuploadfrommem(void){return ftpuploadfrommem();}
int CurlExample::test_ftpuploadresume(void){return ftpuploadresume();}
int CurlExample::test_getinfo(void){return getinfo();}
int CurlExample::test_getinmemory(void){return getinmemory();}
int CurlExample::test_getredirect(void){return getredirect();}
int CurlExample::test_http_post(void){return http_post();}
// int CurlExample::test_http2_download(const std::vector<std::string>> &args){return http2_download(argc, argv);}
int CurlExample::test_http2_pushinmemory(void){return http2_pushinmemory();}
int CurlExample::test_http2_serverpush(void){return http2_serverpush();}
// int CurlExample::test_http2_upload(const std::vector<std::string>> &args){return http2_upload(argc, argv);}
int CurlExample::test_httpcustomheader(void){return httpcustomheader();}
// int CurlExample::test_httpput(const std::vector<std::string>> &args){return httpput(argc, argv);}
int CurlExample::test_https(void){return https();}
int CurlExample::test_imap_append(void){return imap_append();}
int CurlExample::test_imap_copy(void){return imap_copy();}
int CurlExample::test_imap_create(void){return imap_create();}
int CurlExample::test_imap_delete(void){return imap_delete();}
int CurlExample::test_imap_examine(void){return imap_examine();}
int CurlExample::test_imap_fetch(void){return imap_fetch();}
int CurlExample::test_imap_list(void){return imap_list();}
int CurlExample::test_imap_lsub(void){return imap_lsub();}
int CurlExample::test_imap_multi(void){return imap_multi();}
int CurlExample::test_imap_noop(void){return imap_noop();}
int CurlExample::test_imap_search(void){return imap_search();}
int CurlExample::test_imap_ssl(void){return imap_ssl();}
int CurlExample::test_imap_store(void){return imap_store();}
int CurlExample::test_imap_tls(void){return imap_tls();}
int CurlExample::test_multi_app(void){return multi_app();}
int CurlExample::test_multi_debugcallback(void){return multi_debugcallback();}
int CurlExample::test_multi_double(void){return multi_double();}
int CurlExample::test_multi_formadd(void){return multi_formadd();}
int CurlExample::test_multi_single(void){return multi_single();}
// int CurlExample::test_multithread(const std::vector<std::string>> &args){return multithread(argc, argv);}
int CurlExample::test_persistent(void){return persistent();}
int CurlExample::test_pop3_dele(void){return pop3_dele();}
int CurlExample::test_pop3_list(void){return pop3_list();}
int CurlExample::test_pop3_multi(void){return pop3_multi();}
int CurlExample::test_pop3_noop(void){return pop3_noop();}
int CurlExample::test_pop3_retr(void){return pop3_retr();}
int CurlExample::test_pop3_ssl(void){return pop3_ssl();}
int CurlExample::test_pop3_stat(void){return pop3_stat();}
int CurlExample::test_pop3_tls(void){return pop3_tls();}
int CurlExample::test_pop3_top(void){return pop3_top();}
int CurlExample::test_pop3_uidl(void){return pop3_uidl();}
int CurlExample::test_post_callback(void){return post_callback();}
int CurlExample::test_postinmemory(void){return postinmemory();}
// int CurlExample::test_postit2_formadd(const std::vector<std::string>> &args){return postit2_formadd(argc, argv);}
int CurlExample::test_resolve(void){return resolve();}
// int CurlExample::test_rtsp(const std::vector<std::string>> &args){return rtsp(argc, argv);}
int CurlExample::test_sendrecv(void){return sendrecv();}
int CurlExample::test_sepheaders(void){return sepheaders();}
int CurlExample::test_sftpget(void){return sftpget();}
int CurlExample::test_sftpuploadresume(void){return sftpuploadresume();}
int CurlExample::test_shared_connection_cache(void){return shared_connection_cache();}
int CurlExample::test_simple(void){return simple();}
int CurlExample::test_simplepost(void){return simplepost();}
int CurlExample::test_simplessl(void){return simplessl();}
int CurlExample::test_smtp_expn(void){return smtp_expn();}
int CurlExample::test_smtp_mail(void){return smtp_mail();}
int CurlExample::test_smtp_multi(void){return smtp_multi();}
int CurlExample::test_smtp_ssl(void){return smtp_ssl();}
int CurlExample::test_smtp_tls(void){return smtp_tls();}
int CurlExample::test_smtp_vrfy(void){return smtp_vrfy();}
int CurlExample::test_threaded_shared_conn(void){return threaded_shared_conn();}
// int CurlExample::test_threaded_ssl(const std::vector<std::string>> &args){return threaded_ssl(argc, argv);}
// int CurlExample::test_url2file(const std::vector<std::string>> &args){return url2file(argc, argv);}
//int CurlExample::test_usercertinmem(void){return usercertinmem();}
