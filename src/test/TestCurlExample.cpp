#include <string>
#include "TestCurlExample.h"

//#ifdef WRAP_EXAMPLES
#include "curl_examples/CurlExample.h"
//#endif

//using namespace google_test_sample;
using namespace std;

TestCurlExample::TestCurlExample() {}

TestCurlExample::~TestCurlExample() {};

void TestCurlExample::SetUp() {};

void TestCurlExample::TearDown() {};

//#ifdef WRAP_EXAMPLES

TEST(test_10_at_a_time, ShouldReturnZero) {
    CurlExample curlExample;
    ASSERT_EQ(curlExample.test_10_at_a_time(), 0);
}

TEST(test_cookie_interface, ShouldReturnZero) {
    CurlExample curlExample;
    ASSERT_EQ(curlExample.test_cookie_interface(), 0);
}

TEST(test_debug, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_debug(), 0);
}

TEST(test_externalsocket, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_externalsocket(), 0);
}

TEST(test_fileupload, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_fileupload(), 0);
}

TEST(test_ftpget, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_ftpget(), 0);
}

TEST(test_ftpgetinfo, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_ftpgetinfo(), 0);
}

TEST(test_ftpgetresp, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_ftpgetresp(), 0);
}

TEST(test_ftpsget, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_ftpsget(), 0);
}

TEST(test_ftpupload, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_ftpupload(), 0);
}

TEST(test_ftpuploadfrommem, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_ftpuploadfrommem(), 0);
}

TEST(test_ftpuploadresume, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_ftpuploadresume(), 0);
}

TEST(test_getinfo, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_getinfo(), 0);
}

TEST(test_getinmemory, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_getinmemory(), 0);
}

TEST(test_getredirect, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_getredirect(), 0);
}

TEST(test_http_post, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_http_post(), 0);
}

TEST(test_http2_pushinmemory, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_http2_pushinmemory(), 0);
}

TEST(test_http2_serverpush, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_http2_serverpush(), 0);
}

TEST(test_httpcustomheader, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_httpcustomheader(), 0);
}

TEST(test_https, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_https(), 0);
}

TEST(test_imap_append, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_append(), 0);
}

TEST(test_imap_copy, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_copy(), 0);
}

TEST(test_imap_create, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_create(), 0);
}

TEST(test_imap_delete, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_delete(), 0);
}

TEST(test_imap_examine, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_examine(), 0);
}

TEST(test_imap_fetch, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_fetch(), 0);
}

TEST(test_imap_list, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_list(), 0);
}

TEST(test_imap_lsub, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_lsub(), 0);
}

TEST(test_imap_multi, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_multi(), 0);
}

TEST(test_imap_noop, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_noop(), 0);
}

TEST(test_imap_search, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_search(), 0);
}

TEST(test_imap_ssl, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_ssl(), 0);
}

TEST(test_imap_store, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_store(), 0);
}

TEST(test_imap_tls, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_imap_tls(), 0);
}

TEST(test_multi_app, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_multi_app(), 0);
}

TEST(test_multi_debugcallback, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_multi_debugcallback(), 0);
}

TEST(test_multi_double, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_multi_double(), 0);
}

TEST(test_multi_formadd, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_multi_formadd(), 0);
}

TEST(test_multi_single, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_multi_single(), 0);
}

TEST(test_persistent, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_persistent(), 0);
}

TEST(test_pop3_dele, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_dele(), 0);
}

TEST(test_pop3_list, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_list(), 0);
}

TEST(test_pop3_multi, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_multi(), 0);
}

TEST(test_pop3_noop, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_noop(), 0);
}

TEST(test_pop3_retr, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_retr(), 0);
}

TEST(test_pop3_ssl, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_ssl(), 0);
}

TEST(test_pop3_stat, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_stat(), 0);
}

TEST(test_pop3_tls, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_tls(), 0);
}

TEST(test_pop3_top, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_top(), 0);
}

TEST(test_pop3_uidl, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_pop3_uidl(), 0);
}

TEST(test_post_callback, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_post_callback(), 0);
}

TEST(test_postinmemory, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_postinmemory(), 0);
}

TEST(test_resolve, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_resolve(), 0);
}

TEST(test_sendrecv, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_sendrecv(), 0);
}

TEST(test_sepheaders, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_sepheaders(), 0);
}

TEST(test_sftpget, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_sftpget(), 0);
}

TEST(test_sftpuploadresume, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_sftpuploadresume(), 0);
}

TEST(test_shared_connection_cache, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_shared_connection_cache(), 0);
}

TEST(test_simple, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_simple(), 0);
}

TEST(test_simplepost, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_simplepost(), 0);
}

TEST(test_simplessl, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_simplessl(), 0);
}

TEST(test_smtp_expn, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_smtp_expn(), 0);
}

TEST(test_smtp_mail, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_smtp_mail(), 0);
}

TEST(test_smtp_multi, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_smtp_multi(), 0);
}

TEST(test_smtp_ssl, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_smtp_ssl(), 0);
}

TEST(test_smtp_tls, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_smtp_tls(), 0);
}

TEST(test_smtp_vrfy, ShouldReturnZero) {
  CurlExample curlExample;
  ASSERT_EQ(curlExample.test_smtp_vrfy(), 0);
}

//TEST(test_threaded_shared_conn, ShouldReturnZero) {
//  CurlExample curlExample;
//  ASSERT_EQ(curlExample.test_threaded_shared_conn(), 0);
//}

//TEST(test_usercertinmem, ShouldReturnZero) {
//  CurlExample curlExample;
//  ASSERT_EQ(curlExample.test_usercertinmem(), 0);
//}

//#endif

