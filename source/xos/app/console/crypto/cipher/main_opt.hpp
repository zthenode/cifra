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
///   Date: 1/27/2021, 9/29/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPT_HPP

#include "xos/app/console/crypto/cipher/base/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPT "algorithm"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_AES_C "a"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_AES_S "aes"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_DES3_C "d"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_DES3_S "des3"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_RC4_C "r"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_RC4_S "rc4"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG "{ " \
    "(" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_AES_C ")" \
        XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_AES_S \
    " | (" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_DES3_C ")" \
           XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_DES3_S \
    " | (" XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_RC4_C ")" \
           XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_RC4_S \
    " }"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTUSE "cipher algorithm"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_CHARS \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ARGS \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGS

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ARGV \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGV

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {

/// class main_optt
template <class TExtends = crypto::cipher::base::main, class TImplements = typename TExtends::implements>
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
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...on...option...
    virtual int on_aes_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }
    virtual int on_des3_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }
    virtual int on_rc4_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        return err;
    }
    virtual int on_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_AES_C[0] == (optarg[0])))
                || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_AES_S))) {
                err = this->on_aes_cipher_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
            } else {
                if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_DES3_C[0] == (optarg[0])))
                    || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_DES3_S))) {
                    err = this->on_des3_cipher_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
                } else {
                    if ((!(optarg[1]) && (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_RC4_C[0] == (optarg[0])))
                        || !(chars_t::compare(optarg, XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG_RC4_S))) {
                        err = this->on_rc4_cipher_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
                    } else {
                        err = this->on_invalid_option_arg(optval, optarg, optname, optind, argc, argv, env);
                    }
                }
            }
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
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTVAL_C:
            err = on_cipher_algorithm_option(optval, optarg, optname, optind, argc, argv, env);
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
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ALGORITHM_OPTUSE;
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace cipher
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_OPT_HPP
