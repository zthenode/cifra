///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 1/30/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPT_HPP

#include "xos/app/console/version/main.hpp"
#include "xos/lib/cifra/version.hpp"

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPT "test"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTUSE "test"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTVAL_C 's'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPT "plain"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTUSE "plain text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPT "cipher"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTUSE "cipher text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTVAL_S "c::"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTVAL_C 'c'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPT "64"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTUSE "base 64"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTVAL_S "4"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTVAL_C '4'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPT "X"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTUSE "uppercase hex"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTVAL_S "X"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTVAL_C 'X'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPT "x"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTUSE "lowercase hex"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTVAL_S "x"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTVAL_C 'x'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPT "text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTUSE "text"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTVAL_S "t"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTVAL_C 't'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPT "no-line"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTUSE "no line feed"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTVAL_S "n"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS_BASE \
    XOS_VERSION_MAIN_USAGE_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS_BASE \
    XOS_VERSION_MAIN_USAGE_OPTIONS_OPTIONS \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS_BASE \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS_BASE \

#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGS "[source]"
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGV "[source] plain/cipher source",

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace base {

/// class main_optt
template <class TExtends = version::maint<lib::cifra::version>, class TImplements = typename TExtends::implements>
class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives; 
    
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructors / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::default_run(argc, argv, env);
        }
        return err;
    }

    /// ...version_run
    virtual int after_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }

    /// ...test_run
    virtual int test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_test_run(argc, argv, env))) {
            int err2 = 0;
            err = test_run(argc, argv, env);
            if ((err2 = after_test_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_test_run;
        return err;
    }
    virtual int before_set_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_test_run(argc, argv, env))) {
            int err2 = 0;
            err = set_test_run(argc, argv, env);
            if ((err2 = after_set_test_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...plain_run
    virtual int plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = plain_run(argc, argv, env);
            if ((err2 = after_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_plain_run;
        return err;
    }
    virtual int before_set_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = set_plain_run(argc, argv, env);
            if ((err2 = after_set_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...cipher_run
    virtual int cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = cipher_run(argc, argv, env);
            if ((err2 = after_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_cipher_run;
        return err;
    }
    virtual int before_set_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = set_cipher_run(argc, argv, env);
            if ((err2 = after_set_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...get_plain_run
    virtual int get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;

        if ((plain_text = this->plain_text(sizeof_plain_text))) {
            this->outln(plain_text, sizeof_plain_text);
        }
        return err;
    }
    virtual int before_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = get_plain_run(argc, argv, env);
            if ((err2 = after_get_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_plain_run;
        return err;
    }
    virtual int before_set_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_get_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = set_get_plain_run(argc, argv, env);
            if ((err2 = after_set_get_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...get_cipher_run
    virtual int get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* cipher_text = 0;
        size_t sizeof_cipher_text = 0;

        if ((cipher_text = this->cipher_text(sizeof_cipher_text))) {
            this->outln(cipher_text, sizeof_cipher_text);
        }
        return err;
    }
    virtual int before_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = get_cipher_run(argc, argv, env);
            if ((err2 = after_get_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_cipher_run;
        return err;
    }
    virtual int before_set_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_get_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = set_get_cipher_run(argc, argv, env);
            if ((err2 = after_set_get_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...plain... / ...cipher...
    virtual int on_plain_text_set(const char_t* to) {
        int err = 0;
        return err;
    }
    virtual const char_t* set_plain_text(const char_t* to) {
        return 0;
    }
    virtual const char_t* plain_text(size_t& length) const {
        length = 0;
        return 0;
    }
    virtual int on_cipher_text_set(const char_t* to) {
        int err = 0;
        return err;
    }
    virtual const char_t* set_cipher_text(const char_t* to) {
        return 0;
    }
    virtual const char_t* cipher_text(size_t& length) const {
        length = 0;
        return 0;
    }

    /// on...option
    virtual int on_test_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_set_plain_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_get_plain_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        err = this->all_set_get_plain_run(argc, argv, env);
        return err;
    }
    virtual int on_plain_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = this->on_set_plain_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = this->on_get_plain_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual int on_set_cipher_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_get_cipher_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        err = this->all_set_get_cipher_run(argc, argv, env);
        return err;
    }
    virtual int on_cipher_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = this->on_set_cipher_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = this->on_get_cipher_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual int on_base64_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_upper_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_lower_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_no_line_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual const char_t* no_line_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTVAL_C:
            err = on_test_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTVAL_C:
            err = on_plain_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTVAL_C:
            err = on_cipher_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTVAL_C:
            err = on_base64_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTVAL_C:
            err = on_upper_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTVAL_C:
            err = on_lower_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTVAL_C:
            err = on_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTVAL_C:
            err = on_no_line_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_MAIN_USAGE_OPTVAL_C:
            err = this->on_usage_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEST_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_CIPHER_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTVAL_C:
            chars = no_line_option_usage(optarg, longopt);
            break;
        case XOS_CONSOLE_MAIN_USAGE_OPTVAL_C:
            chars = this->usage_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPT_HPP
