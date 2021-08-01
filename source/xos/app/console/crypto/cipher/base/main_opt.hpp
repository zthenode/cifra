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
///   Date: 2/3/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP

#include "xos/app/console/crypto/base/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPT "encrypt"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTUSE "encrypt plain text"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPT "decrypt"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTUSE "decrypt cipher text"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPT "key"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTUSE "encryption key"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_S "k::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_C 'k'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPT "iv"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTUSE "initialization vector"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_S "i::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_C 'i'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTION \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGS XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGS
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGV XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGV

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace base {

/// class main_optt
template 
<class TExtends = crypto::base::main, 
 class TImplements = typename TExtends::implements>

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

    /// constructor / destructor
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

    /// ...encipher_run
    virtual int encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_encipher_run(argc, argv, env))) {
            int err2 = 0;
            err = encipher_run(argc, argv, env);
            if ((err2 = after_encipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_encipher_run;
        return err;
    }
    virtual int before_set_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_encipher_run(argc, argv, env))) {
            int err2 = 0;
            err = set_encipher_run(argc, argv, env);
            if ((err2 = after_set_encipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...decipher_run
    virtual int decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_decipher_run(argc, argv, env))) {
            int err2 = 0;
            err = decipher_run(argc, argv, env);
            if ((err2 = after_decipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_decipher_run;
        return err;
    }
    virtual int before_set_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_decipher_run(argc, argv, env))) {
            int err2 = 0;
            err = set_decipher_run(argc, argv, env);
            if ((err2 = after_set_decipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...get_key_run
    virtual int get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_key = 0;
        size_t sizeof_cipher_key = 0;

        if ((cipher_key = this->cipher_key(sizeof_cipher_key))) {
            this->output_x(cipher_key, sizeof_cipher_key);
        }
        return err;
    }
    virtual int before_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_key_run(argc, argv, env))) {
            int err2 = 0;
            err = get_key_run(argc, argv, env);
            if ((err2 = after_get_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_key_run;
        return err;
    }
    virtual int before_set_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_get_key_run(argc, argv, env))) {
            int err2 = 0;
            err = set_get_key_run(argc, argv, env);
            if ((err2 = after_set_get_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...get_iv_run
    virtual int get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_iv = 0;
        size_t sizeof_cipher_iv = 0;

        if ((cipher_iv = this->cipher_iv(sizeof_cipher_iv))) {
            this->output_x(cipher_iv, sizeof_cipher_iv);
        }
        return err;
    }
    virtual int before_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_iv_run(argc, argv, env))) {
            int err2 = 0;
            err = get_iv_run(argc, argv, env);
            if ((err2 = after_get_iv_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_iv_run;
        return err;
    }
    virtual int before_set_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_get_iv_run(argc, argv, env))) {
            int err2 = 0;
            err = set_get_iv_run(argc, argv, env);
            if ((err2 = after_set_get_iv_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...cipher_key... / ...cipher_iv...
    virtual byte_t* cipher_key_data(size_t& sizeof_cipher_key) const {
        sizeof_cipher_key= 0;
        return 0;
    }
    virtual const byte_t* cipher_key(size_t& sizeof_cipher_key) const {
        sizeof_cipher_key= 0;
        return 0;
    }
    virtual byte_t* cipher_iv_data(size_t& sizeof_cipher_iv) const {
        sizeof_cipher_iv = 0;
        return 0;
    }
    virtual const byte_t* cipher_iv(size_t& sizeof_cipher_iv) const {
        sizeof_cipher_iv = 0;
        return 0;
    }
    virtual byte_t* cipher_test_data(size_t& sizeof_cipher_test) const {
        sizeof_cipher_test = 0;
        return 0;
    }
    virtual const byte_t* cipher_test(size_t& sizeof_cipher_test) const {
        sizeof_cipher_test = 0;
        return 0;
    }

    /// ...on...option...
    virtual int on_encrypt_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->all_set_encipher_run(argc, argv, env);
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_decrypt_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->all_set_decipher_run(argc, argv, env);
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_set_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_get_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->all_set_get_key_run(argc, argv, env);
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = this->on_set_key_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = this->on_get_key_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual int on_set_iv_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_get_iv_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->all_set_get_iv_run(argc, argv, env);
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_iv_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = this->on_set_iv_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = this->on_get_iv_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C:
            err = on_encrypt_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C:
            err = on_decrypt_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_C:
            err = this->on_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_C:
            err = this->on_iv_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTUSE;
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace cipher
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP
