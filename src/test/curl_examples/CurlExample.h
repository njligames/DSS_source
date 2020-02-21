#ifndef CURL_EXAMPLE
#define CURL_EXAMPLE

#include <string>
#include <vector>

class CurlExample
{
  public:
    CurlExample(){}
    virtual ~CurlExample(){}
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/10-at-a-time.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_10_at_a_time(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/anyauthput.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_anyauthput(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/certinfo.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_certinfo(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/chkspeed.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_chkspeed(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/cookie_interface.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_cookie_interface(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/curlx.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_curlx(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/debug.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_debug(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/externalsocket.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_externalsocket(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/fileupload.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_fileupload(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/fopen.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_fopen(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/ftp-wildcard.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_ftp_wildcard(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/ftpget.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_ftpget(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/ftpgetinfo.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_ftpgetinfo(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/ftpgetresp.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_ftpgetresp(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/ftpget.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_ftpsget(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/ftpupload.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_ftpupload(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/ftpuploadfrommem.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_ftpuploadfrommem(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/ftpuploadresume.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_ftpuploadresume(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/getinfo.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_getinfo(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/getinmemory.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_getinmemory(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/getredirect.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_getredirect(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/http_post.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_http_post(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/http2_download.html">Original Curl Example</http2_download>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_http2_download(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/http2_pushinmemory.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_http2_pushinmemory(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/http2_serverpush.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_http2_serverpush(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/http2_upload.html">Original Curl Example</http2_upload>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_http2_upload(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/httpcustomheader.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_httpcustomheader(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/httpput.html">Original Curl Example</httpput>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_httpput(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/https.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_https(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_append.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_append(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_copy.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_copy(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_create.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_create(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_delete.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_delete(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_examine.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_examine(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_fetch.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_fetch(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_list.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_list(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_lsub.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_lsub(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_multi.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_multi(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_noop.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_noop(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_search.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_search(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_ssl.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_ssl(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_store.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_store(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/imap_tls.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_imap_tls(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/multi_app.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_multi_app(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/multi_debugcallback.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_multi_debugcallback(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/multi_double.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_multi_double(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/multi_formadd.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_multi_formadd(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/multi_single.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_multi_single(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/multithread.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_multithread(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/persistent.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_persistent(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_dele.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_dele(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_list.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_list(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_multi.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_multi(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_noop.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_noop(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_retr.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_retr(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_ssl.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_ssl(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_stat.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_stat(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_tls.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_tls(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_top.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_top(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/pop3_uidl.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_pop3_uidl(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/post_callback.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_post_callback(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/postinmemory.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_postinmemory(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/postit2_formadd.html">Original Curl Example</postit2_formadd>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_postit2_formadd(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/resolve.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_resolve(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/rtsp.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_rtsp(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/sendrecv.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_sendrecv(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/sepheaders.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_sepheaders(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/sftpget.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_sftpget(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/sftpuploadresume.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_sftpuploadresume(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/shared_connection_cache.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_shared_connection_cache(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/simple.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_simple(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/simplepost.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_simplepost(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/simplessl.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_simplessl(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/smtp_expn.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_smtp_expn(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/smtp_mail.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_smtp_mail(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/smtp_multi.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_smtp_multi(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/smtp_ssl.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_smtp_ssl(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/smtp_tls.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_smtp_tls(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/smtp_vrfy.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_smtp_vrfy(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/threaded_shared_conn.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
    int test_threaded_shared_conn(void);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/threaded_ssl.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_threaded_ssl(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/url2file.html">Original Curl Example</a>

     @param argc Number of arguments
     @param argv String array of arguments
     @return zero for success, one for failure.
     */
    // int test_url2file(const std::vector<std::string>> &args);
    
    /**
     <a href="https://curl.haxx.se/libcurl/c/usercertinmem.html">Original Curl Example</a>

     @return zero for success, one for failure.
     */
//    int test_usercertinmem(void);

};

#endif

