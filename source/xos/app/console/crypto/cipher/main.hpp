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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/27/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP

#include "xos/app/console/crypto/cipher/main_opt.hpp"
#include "xos/crypto/cipher/aes/devine/implemented.hpp"
#include "xos/crypto/cipher/des/openssl/implemented.hpp"
#include "xos/crypto/cipher/des3/openssl/implemented.hpp"
#include "xos/crypto/cipher/rc4/etiris/implemented.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_IVSIZE \
    xos::crypto::cipher::aes::IVMAX

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_KEYSIZE \
    xos::crypto::cipher::aes::KEYMAX

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_BLOCKSIZE \
    xos::crypto::cipher::aes::BLOCKSIZE

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_BLOCKSIZE 64
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_BLOCKSIZE*1024)

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives; 
    
    typedef xos::crypto::cipher::implement cipher_t;

    typedef xos::crypto::cipher::aes::implement aes_cipher_t;
    typedef xos::crypto::cipher::aes::devine::implemented devine_aes_cipher_t;
    typedef devine_aes_cipher_t default_aes_cipher_t;

    typedef xos::crypto::cipher::des::implement des_cipher_t;
    typedef xos::crypto::cipher::des::openssl::implemented openssl_des_cipher_t;
    typedef openssl_des_cipher_t default_des_cipher_t;

    typedef xos::crypto::cipher::des3::implement des3_cipher_t;
    typedef xos::crypto::cipher::des3::openssl::implemented openssl_des3_cipher_t;
    typedef openssl_des3_cipher_t default_des3_cipher_t;

    typedef xos::crypto::cipher::rc4::implement rc4_cipher_t;
    typedef xos::crypto::cipher::rc4::etiris::implemented etiris_rc4_cipher_t;
    typedef etiris_rc4_cipher_t default_rc4_cipher_t;

    enum cipher_algorithm_t {
        cipher_algorithm_none,
        cipher_algorithm_aes,
        cipher_algorithm_des3,
        cipher_algorithm_des,
        cipher_algorithm_rc4,
        next_cipher_algorithm,
        first_cipher_algorithm = (cipher_algorithm_none + 1),
        last_cipher_algorithm = (next_cipher_algorithm - 1)
    };

    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructors / destructor
    maint()
    : test_run_(0), 
      encipher_run_(0), decipher_run_(0), 
      cipher_test_run_(0), 
      cipher_algorithm_(cipher_algorithm_none), 
      cipher_iv_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_IVSIZE), 
      cipher_key_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_KEYSIZE), 
      encipher_block_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_BLOCKSIZE), 
      decipher_block_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_BLOCKSIZE), 
      block_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    /// ...test_run
    int (derives::*test_run_)(int argc, char_t** argv, char_t** env);
    virtual int test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->test_run_)) {
            err = (this->*test_run_)(argc, argv, env);
        } else {
            err = this->default_test_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->cipher_test_run(argc, argv, env);
        return err;
    }

    /// ...encipher_run
    int (derives::*encipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->encipher_run_)) {
            err = (this->*encipher_run_)(argc, argv, env);
        } else {
            err = this->default_encipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->cipher_test_run(argc, argv, env);
        return err;
    }

    /// ...decipher_run
    int (derives::*decipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->decipher_run_)) {
            err = (this->*decipher_run_)(argc, argv, env);
        } else {
            err = this->default_decipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->cipher_test_run(argc, argv, env);
        return err;
    }

    /// plain / cipher run
    virtual int plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->all_encipher_run(argc, argv, env);
        return err;
    }
    virtual int cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->all_decipher_run(argc, argv, env);
        return err;
    }

    /// cipher_test_run
    int (derives::*cipher_test_run_)(int argc, char_t** argv, char_t** env);
    virtual int cipher_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->cipher_test_run_)) {
            err = (this->*cipher_test_run_)(argc, argv, env);
        } else {
            this->aes_test_run(argc, argv, env);
            this->des3_test_run(argc, argv, env);
            this->rc4_test_run(argc, argv, env);
        }
        return err;
    }

    /// aes_test_run
    virtual int aes_test_run(int argc, char_t** argv, char_t** env) {
        static const byte_t cbc_key[8*3] = {
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
            0xf1,0xe0,0xd3,0xc2,0xb5,0xa4,0x97,0x86,
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
        };
        static const byte_t cbc_iv[8*2] = {
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10,
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef
        };
        static const byte_t plain_text[8*4] = {
            0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
            0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
            0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
            0x66,0x6F,0x72,0x20,0x00,0x31,0x00,0x00
        };
        static const byte_t cipher_text[8*4] = {
            0x38,0x2A,0xB1,0xB3,0xD5,0x33,0x6B,0x09,
            0x64,0xDE,0x64,0x01,0x32,0x4C,0x05,0x38,
            0x4B,0xBB,0x0A,0x3A,0x7B,0xF5,0xE5,0x0C,
            0x20,0xA7,0x80,0xD1,0x5E,0xC3,0x37,0xEF
        };
        byte_t encipher_text[sizeof(plain_text)] = {0}, 
               decipher_text[sizeof(plain_text)] = {0};
        size_t sizeof_cbc_key = sizeof(cbc_key), 
               sizeof_cbc_iv = sizeof(cbc_iv), 
               sizeof_plain_text = sizeof(plain_text),
               sizeof_cipher_text = sizeof(encipher_text), 
               sizeof_encipher_text = sizeof(encipher_text), 
               sizeof_decipher_text = sizeof(decipher_text);
        ssize_t length = 0;
        int err = 0;

        this->outln("aes");
        this->out("   plain-text: "); 
        this->output_x(plain_text, length = sizeof_plain_text);

        if ((plain_text) && (length)) {
            default_aes_cipher_t cbc(cbc_key, sizeof_cbc_key, cbc_iv, sizeof_cbc_iv);
            
            if (0 < (length = cbc.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                this->out("  cipher-text: "); 
                this->output_x(encipher_text, length);

                if ((bytes_t::compare(encipher_text, cipher_text, sizeof_cipher_text))) {
                    this->errln("encipher_text != cipher_text");
                    return 1;
                }
            } else {
                this->errln("failed on encrypt()");
                return 1;
            }
        }
        if ((decipher_text) && (length)) {
            default_aes_cipher_t cbc(cbc_key, sizeof_cbc_key, cbc_iv, sizeof_cbc_iv);

            if (sizeof_plain_text <= (length = cbc.decrypt(decipher_text, sizeof_decipher_text, encipher_text, length))) {
                this->out("decipher-text: "); 
                this->output_x(decipher_text, length);

                if ((bytes_t::compare(decipher_text, plain_text, sizeof_plain_text))) {
                    this->errln("decipher_text != plain_text");
                    return 1;
                }
            } else {
                this->errln("failed on decrypt()");
                return 1;
            }
        }
        this->outln();
        return err;
    }
    virtual int set_aes_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_test_run_ = &derives::aes_test_run;
        return err;
    }

    /// des3_test_run
    virtual int des3_test_run(int argc, char_t** argv, char_t** env) {
        static const byte_t cbc_key[8*3] = {
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
            0xf1,0xe0,0xd3,0xc2,0xb5,0xa4,0x97,0x86,
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
        };
        static const byte_t cbc_iv[8] = {
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
        };
        static const byte_t plain_text[8*4] = {
            0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
            0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
            0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
            0x66,0x6F,0x72,0x20,0x00,0x00,0x00,0x00
        };
        static const byte_t cipher_text[8*4] = {
            0x3F,0xE3,0x01,0xC9,0x62,0xAC,0x01,0xD0,
            0x22,0x13,0x76,0x3C,0x1C,0xBD,0x4C,0xDC,
            0x79,0x96,0x57,0xC0,0x64,0xEC,0xF5,0xD4,
            0x1C,0x67,0x38,0x12,0xCF,0xDE,0x96,0x75
        };
        byte_t encipher_text[sizeof(plain_text)] = {0}, 
               decipher_text[sizeof(plain_text)] = {0};
        size_t sizeof_cbc_key = sizeof(cbc_key), 
               sizeof_cbc_iv = sizeof(cbc_iv), 
               sizeof_plain_text = sizeof(plain_text),
               sizeof_cipher_text = sizeof(cipher_text), 
               sizeof_encipher_text = sizeof(encipher_text), 
               sizeof_decipher_text = sizeof(decipher_text);
        ssize_t length = 0;
        int err = 0;

        this->outln("des3");
        this->out("   plain-text: "); 
        this->output_x(plain_text, length = sizeof_plain_text);

        if ((plain_text) && (length)) {
            default_des3_cipher_t cbc(cbc_key, sizeof_cbc_key, cbc_iv, sizeof_cbc_iv);
            
            if (0 < (length = cbc.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                this->out("  cipher-text: "); 
                this->output_x(encipher_text, length);

                if ((bytes_t::compare(encipher_text, cipher_text, sizeof_cipher_text))) {
                    this->errln("encipher_text != cipher_text");
                    return 1;
                }
            } else {
                this->errln("failed on encrypt()");
                return 1;
            }
        }
        if ((decipher_text) && (length)) {
            default_des3_cipher_t cbc(cbc_key, sizeof_cbc_key, cbc_iv, sizeof_cbc_iv);

            if (sizeof_plain_text <= (length = cbc.decrypt(decipher_text, sizeof_decipher_text, encipher_text, length))) {
                this->out("decipher-text: "); 
                this->output_x(decipher_text, length);

                if ((bytes_t::compare(decipher_text, plain_text, sizeof_plain_text))) {
                    this->errln("decipher_text != plain_text");
                    return 1;
                }
            } else {
                this->errln("failed on decrypt()");
                return 1;
            }
        }
        this->outln();
        return err;
    }
    virtual int set_des3_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_test_run_ = &derives::des3_test_run;
        return err;
    }

    /// des_test_run
    virtual int des_test_run(int argc, char_t** argv, char_t** env) {
        static const byte_t cbc_key[8] = {
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
        };
        static const byte_t cbc_iv[8] = {
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10,
        };
        static const byte_t plain_text[8*4] = {
            0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
            0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
            0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
            0x66,0x6F,0x72,0x20,0x00,0x00,0x00,0x00,
        };
        static const byte_t cipher_text[8*4] = {
            0xcc,0xd1,0x73,0xff,0xab,0x20,0x39,0xf4,
            0xac,0xd8,0xae,0xfd,0xdf,0xd8,0xa1,0xeb,
            0x46,0x8e,0x91,0x15,0x78,0x88,0xba,0x68,
            0x1d,0x26,0x93,0x97,0xf7,0xfe,0x62,0xb4
        };
        byte_t encipher_text[sizeof(plain_text)] = {0}, 
               decipher_text[sizeof(plain_text)] = {0};
        size_t sizeof_cbc_key = sizeof(cbc_key), 
               sizeof_cbc_iv = sizeof(cbc_iv), 
               sizeof_plain_text = sizeof(plain_text),
               sizeof_cipher_text = sizeof(cipher_text), 
               sizeof_encipher_text = sizeof(encipher_text), 
               sizeof_decipher_text = sizeof(decipher_text);
        ssize_t length = 0;
        int err = 0;

        this->outln("des");
        this->out("   plain-text: "); 
        this->output_x(plain_text, length = sizeof_plain_text);

        if ((plain_text) && (length)) {
            default_des_cipher_t cbc(cbc_key, sizeof_cbc_key, cbc_iv, sizeof_cbc_iv);
            
            if (0 < (length = cbc.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                this->out("  cipher-text: "); 
                this->output_x(encipher_text, length);

                if ((bytes_t::compare(encipher_text, cipher_text, sizeof_cipher_text))) {
                    this->errln("encipher_text != cipher_text");
                    return 1;
                }
            } else {
                this->errln("failed on encrypt()");
                return 1;
            }
        }
        if ((decipher_text) && (length)) {
            default_des_cipher_t cbc(cbc_key, sizeof_cbc_key, cbc_iv, sizeof_cbc_iv);

            if (sizeof_plain_text <= (length = cbc.decrypt(decipher_text, sizeof_decipher_text, encipher_text, length))) {
                this->out("decipher-text: "); 
                this->output_x(decipher_text, length);

                if ((bytes_t::compare(decipher_text, plain_text, sizeof_plain_text))) {
                    this->errln("decipher_text != plain_text");
                    return 1;
                }
            } else {
                this->errln("failed on decrypt()");
                return 1;
            }
        }
        this->outln();
        return err;
    }
    virtual int set_des_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_test_run_ = &derives::des_test_run;
        return err;
    }

    /// rc4_test_run
    virtual int rc4_test_run(int argc, char_t** argv, char_t** env) {
        static const byte_t cbc_key[8] = {
            0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        };
        static const byte_t plain_text[8*3+4] = {
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78,
        };
        static const byte_t cipher_text[8*3+4] = {
            0x66, 0xa0, 0x94, 0x9f, 0x8a, 0xf7, 0xd6, 0x89,
            0x1f, 0x7f, 0x83, 0x2b, 0xa8, 0x33, 0xc0, 0x0c,
            0x89, 0x2e, 0xbe, 0x30, 0x14, 0x3c, 0xe2, 0x87,
            0x40, 0x01, 0x1e, 0xcf,
        };
        byte_t encipher_text[sizeof(plain_text)] = {0}, 
               decipher_text[sizeof(plain_text)] = {0};
        size_t sizeof_cbc_key = sizeof(cbc_key), 
               sizeof_plain_text = sizeof(plain_text),
               sizeof_cipher_text = sizeof(cipher_text), 
               sizeof_encipher_text = sizeof(encipher_text), 
               sizeof_decipher_text = sizeof(decipher_text);
        ssize_t length = 0;
        int err = 0;

        this->outln("rc4");
        this->out("   plain-text: "); 
        this->output_x(plain_text, length = sizeof_plain_text);

        if ((plain_text) && (length)) {
            default_rc4_cipher_t cbc(cbc_key, sizeof_cbc_key);
            
            if (0 < (length = cbc.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                this->out("  cipher-text: "); 
                this->output_x(encipher_text, length);

                if ((bytes_t::compare(encipher_text, cipher_text, sizeof_cipher_text))) {
                    this->errln("encipher_text != cipher_text");
                    return 1;
                }
            } else {
                this->errln("failed on encrypt()");
                return 1;
            }
        }
        if ((decipher_text) && (length)) {
            default_rc4_cipher_t cbc(cbc_key, sizeof_cbc_key);

            if (sizeof_plain_text <= (length = cbc.decrypt(decipher_text, sizeof_decipher_text, encipher_text, length))) {
                this->out("decipher-text: "); 
                this->output_x(decipher_text, length);

                if ((bytes_t::compare(decipher_text, plain_text, sizeof_plain_text))) {
                    this->errln("decipher_text != plain_text");
                    return 1;
                }
            } else {
                this->errln("failed on decrypt()");
                return 1;
            }
        }
        this->outln();
        return err;
    }
    virtual int set_rc4_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_test_run_ = &derives::rc4_test_run;
        return err;
    }

    virtual int on_aes_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        err = set_aes_test_run(argc, argv, env);
        return err;
    }
    virtual int on_des3_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        err = set_des3_test_run(argc, argv, env);
        return err;
    }
    virtual int on_rc4_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        err = set_rc4_test_run(argc, argv, env);
        return err;
    }

protected:
    cipher_algorithm_t cipher_algorithm_;

    devine_aes_cipher_t devine_aes_cipher_;
    openssl_des3_cipher_t openssl_des3_cipher_;
    openssl_des_cipher_t openssl_des_cipher_;
    etiris_rc4_cipher_t etiris_rc4_cipher_;

    size_t cipher_iv_size_, cipher_key_size_, 
           encipher_block_size_, decipher_block_size_, block_size_;

    byte_t cipher_iv_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_IVSIZE],
           cipher_key_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_KEYSIZE],
           encipher_block_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_BLOCKSIZE],
           decipher_block_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_CIPHER_BLOCKSIZE],
           block_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE];

    string_t plain_text_, cipher_text_;
}; /// class maint
typedef maint<> main;

} /// namespace cipher
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP
